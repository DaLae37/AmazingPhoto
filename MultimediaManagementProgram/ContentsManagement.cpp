#include "ContentsManagement.h"
#include "MultimediaManagementProgram.h"

ContentsManagement::ContentsManagement(QWidget* parent) : QWidget(parent) {
	setWindowFlags(Qt::Window);
	ui.setupUi(this);

	Reload(); //������ ������ �����ϴ� ������ �ҷ��´�.
	LoadFromFile();
	if (!((MultimediaManagementProgram*)parent)->getMasterList()->IsEmpty()) { //Master List�� ������� ������
		UpdateMasterList(((MultimediaManagementProgram*)parent)->getMasterList()->getRoot(), 0); //���̺� ����Ʈ�� ������Ʈ
	}
}

void ContentsManagement::SelectUnregisterFile() { //�̵�� ����Ʈ�� �������� Ŭ������ ��
	isUnregisterSelected = true;
	selectedUnregisterFileName = ui.UnregisterFile->currentItem()->text(); //�� ����Ʈ�� �������� �޾ƿͼ� (���� �̸�)
	ui.FileNamePrint->setText(selectedUnregisterFileName); //���� �̸��� ��� (���� �̸� ���)
	ui.FileTypePrint->setText(selectedUnregisterFileName.section(".", -1)); //�Ľ� �� ������ Ȯ���ڸ� ���
	isRegisterSelected = false; //��� ����Ʈ�� ������ ����
}

void ContentsManagement::SelectRegisterFile() {
	isUnregisterSelected = false;
	int row = ui.MasterList->currentItem()->row(); //��ϸ���Ʈ���� ������ �������� �ε����� Ž��
	selectedRegisterFileName = ui.MasterList->item(row, 0)->text(); //�� �ε����� ���� 0�� �÷��� �����̸��� ����
	isRegisterSelected = true; //�̵�� ����Ʈ�� ������ ����
}

void ContentsManagement::OpenPhotoLoadDialog() { //���� �ҷ����� ���̾�α� ����
	photoLoadDialog = new PhotoLoadDialog(this);
	photoLoadDialog->show();
}

void ContentsManagement::OpenVideoLoadDialog() { //���� ������ ���̾�α� ����
	videoLoadDialog = new VideoLoadDialog(this);
	videoLoadDialog->show();
}

void ContentsManagement::Reload() {
	ui.UnregisterFile->clear(); //�켱 �̵�� ������ ����Ʈ�� ���

	std::string searching = "./Contents/Multimedia/*.*"; //������ ������ �ִ� ����

	_finddata_t fd;
	intptr_t handle = _findfirst(searching.c_str(), &fd);  //���� ���� �� ��� ������ ã�´�.

	if (handle == -1) { //������ ���� �� ������ ������ ����
		return;
	}
	else {
		int result = 0;
		do
		{
			if (!(fd.attrib & _A_SUBDIR)) { //ã�� ������ ������ �ƴ� ��
				bool isFind = false;
				MultimediaContent content;
				content.SetRecord(fd.name, "", "", "", "", "", 0); //�ӽ������� �������� �����ϰ�
				((MultimediaManagementProgram*)parent())->getMasterList()->RetrieveItem(content, isFind); //MasterList���� �����ϴ��� Ž��
				if (!isFind) { //MasterList�� ���� ���
					ui.UnregisterFile->addItem(fd.name); //�̵�� ����Ʈ�� �߰�
				}
			}
			result = _findnext(handle, &fd); //�ݺ�
		} while (result != -1); //������ ���ų� ������ �� ������

		_findclose(handle);
	}
}

void ContentsManagement::MakeEmpty() { //��� ����Ʈ�� ���
	int row = ui.MasterList->rowCount(); //��� ����Ʈ�� ���̸� ������
	for (int i = 0; i < row; i++) {
		ui.MasterList->removeRow(0); //��� ���� ������
	}
	
	((MultimediaManagementProgram*)parent())->getMasterList()->MakeEmpty(); //��� ����Ʈ�� �����
	((MultimediaManagementProgram*)parent())->getEventList()->MakeEmpty();
	((MultimediaManagementProgram*)parent())->getPersonList()->MakeEmpty();
	((MultimediaManagementProgram*)parent())->getPlaceList()->MakeEmpty();
	Reload(); //�̵�� ����Ʈ�� ���ΰ�ħ
}

void ContentsManagement::AddItem() { //�������� �߰�
	if (isUnregisterSelected) { //�̵�� ����Ʈ���� �������� ���õǾ��� ��
		MultimediaContent content; //�������� �ӽ� ����
		time_t timeT = time(nullptr);
		struct tm* timer = localtime(&timeT); //���н� �ð��� ���� ���� �ð��� ������

		std::string fileName = ui.FileNamePrint->text().toStdString(); //���� �̸�
		std::string fileType = ui.FileTypePrint->text().toStdString(); //Ȯ����
		std::string createDate = std::to_string(timer->tm_year + 1900) + "-" + std::to_string(timer->tm_mon + 1) + "-" + std::to_string(timer->tm_mday) + "-" + std::to_string(timer->tm_hour) + "-" + std::to_string(timer->tm_min) + "-" + std::to_string(timer->tm_sec);
		std::string eventName = ui.EventNameInput->text().toStdString(); //�Է��� �̺�Ʈ �̸��� ������
		std::string personName = ui.PersonNameInput->text().toStdString(); //�Է��� �ι� �̸��� ������
		std::string placeName = ui.PlaceNameInput->text().toStdString(); //�Է��� ��� �̸��� ������

		content.SetRecord(fileName, fileType, createDate, eventName, personName, placeName, 0); //�������� �ʱ�ȭ
		((MultimediaManagementProgram*)parent())->getMasterList()->AddItem(content); //������ ����Ʈ�� �߰�

		bool isFind = false;

		Event event;
		event.setEventName(eventName); //�̺�Ʈ�� �ӽ� ����
		((MultimediaManagementProgram*)parent())->getEventList()->RetrieveItem(event, isFind); //�ش� �̺�Ʈ�� �����ϸ�
		if (!isFind) {
			((MultimediaManagementProgram*)parent())->getEventList()->AddItem(event); //�̹�Ʈ�� �������� �ʾ��� ��� �̺�Ʈ�� ����
		}
		else {
			event.AddId(fileName); //�̺�Ʈ�� id�� �߰�
		}

		Person person;
		person.setPersonName(personName); //�ι��� �ӽ� ����
		((MultimediaManagementProgram*)parent())->getPersonList()->RetrieveItem(person, isFind); //�ش� �ι��� �����ϸ�
		if (!isFind) {
			((MultimediaManagementProgram*)parent())->getPersonList()->AddItem(person); //�ι��� �������� �ʾ��� ��� �ι��� ����
		}
		else {
			person.AddId(fileName); //�ι��� id�� �߰�
		}

		Place place;
		place.setPlaceName(placeName); //��Ҹ� �ӽ� ����
		((MultimediaManagementProgram*)parent())->getPlaceList()->RetrieveItem(place, isFind); //�ش� ��Ұ� �����ϸ�
		if (!isFind) {
			((MultimediaManagementProgram*)parent())->getPlaceList()->AddItem(place); //��Ұ� �������� �ʾ��� ��� ��Ҹ� ����
		}
		else {
			place.AddId(fileName); //��ҿ� id�� �߰�
		}

		int row = ui.MasterList->rowCount(); //��� ����Ʈ�� �ε����� �޾ƿ�
		ui.MasterList->setRowCount(row + 1);
		ui.MasterList->setItem(row, 0, new QTableWidgetItem(ui.FileNamePrint->text()));
		ui.MasterList->setItem(row, 1, new QTableWidgetItem(createDate.c_str()));
		ui.MasterList->setItem(row, 2, new QTableWidgetItem(ui.FileTypePrint->text()));
		ui.MasterList->setItem(row, 3, new QTableWidgetItem(ui.EventNameInput->text()));
		ui.MasterList->setItem(row, 4, new QTableWidgetItem(ui.PersonNameInput->text()));
		ui.MasterList->setItem(row, 5, new QTableWidgetItem(ui.PlaceNameInput->text())); //��� ����Ʈ�� ���� �߰�
	}
	isUnregisterSelected = false; //�ʱ�ȭ
	ui.FileNamePrint->setText("");
	ui.FileTypePrint->setText("");
	ui.EventNameInput->setText("");
	ui.PersonNameInput->setText("");
	ui.PlaceNameInput->setText(""); //�Է� ĭ ����
	Reload(); //���� ��ħ
}

void ContentsManagement::DeleteItem() { //������ ����
	if (isRegisterSelected) { //��� ����Ʈ���� ���õ� �������� ���� ��
		MultimediaContent content;
		content.SetRecord(selectedRegisterFileName.toStdString(), "", "", "", "", "", 0); //������ �ӽ� ����
		((MultimediaManagementProgram*)parent())->getMasterList()->DeleteItem(content); //����
		Reload(); //���ΰ�ħ
		int index = ui.MasterList->currentRow();
		ui.MasterList->removeRow(index); //��� ����Ʈ���� �ش� ������ ����
	}
}

void ContentsManagement::SaveToFile() { //���Ͽ� Master List�� ������ ����
	std::ofstream outFile;
	outFile.open("./Contents/Database/data.txt"); //������ ������ data.txt

	if (outFile) {
		if (!((MultimediaManagementProgram*)parent())->getMasterList()->IsEmpty()) { //Master List�� ������� ������
			SaveFile(((MultimediaManagementProgram*)parent())->getMasterList()->getRoot(), outFile); //��͸� ���� ����
		}
	}
}

void ContentsManagement::LoadFromFile() { //���Ϸκ��� ������ �о��
	MakeEmpty();
	std::ifstream inFile;
	inFile.open("./Contents/Database/data.txt"); //������ ������ data.txt
	int row = ui.MasterList->rowCount();
	for (int i = 0; i < row; i++) {
		ui.MasterList->removeRow(i);
	}
	if (inFile) {
		while (!inFile.eof()) {
			MultimediaContent content;
			content.ReadDataFromFile(inFile); //�������� �ӽ� ������ ������ �о��
			if (inFile.eof() || content.getCreateDate() == "") {
				break;
			}
			((MultimediaManagementProgram*)parent())->getMasterList()->AddItem(content); //Master List�� �ش� ������ �߰�

			bool isFind = false;

			Event *event = new Event;
			event->setEventName(content.getInnerEvent()); //�̺�Ʈ�� �ӽ� ����
			((MultimediaManagementProgram*)parent())->getEventList()->RetrieveItem(*event, isFind); //�ش� �̺�Ʈ�� �����ϸ�
			event->AddId(content.getFileName()); //�̺�Ʈ�� id�� �߰�
			if (!isFind) {
				((MultimediaManagementProgram*)parent())->getEventList()->AddItem(*event); //�̹�Ʈ�� �������� �ʾ��� ��� �̺�Ʈ�� ����
			}

			Person *person = new Person;
			person->setPersonName(content.getInnerPerson()); //�ι��� �ӽ� ����
			((MultimediaManagementProgram*)parent())->getPersonList()->RetrieveItem(*person, isFind); //�ش� �ι��� �����ϸ�
			person->AddId(content.getFileName()); //�ι��� id�� �߰�
			if (!isFind) {
				((MultimediaManagementProgram*)parent())->getPersonList()->AddItem(*person); //�ι��� �������� �ʾ��� ��� �ι��� ����
			}

			Place *place = new Place;
			place->setPlaceName(content.getInnerPlace()); //��Ҹ� �ӽ� ����
			((MultimediaManagementProgram*)parent())->getPlaceList()->RetrieveItem(*place, isFind); //�ش� ��Ұ� �����ϸ�
			place->AddId(content.getFileName()); //��ҿ� id�� �߰�
			if (!isFind) {
				((MultimediaManagementProgram*)parent())->getPlaceList()->AddItem(*place); //��Ұ� �������� �ʾ��� ��� ��Ҹ� ����
			}

			row = ui.MasterList->rowCount(); //��� ����Ʈ�� �ε����� �����ͼ�
			ui.MasterList->setRowCount(row + 1);
			ui.MasterList->setItem(row, 0, new QTableWidgetItem(content.getFileName().c_str()));
			ui.MasterList->setItem(row, 1, new QTableWidgetItem(content.getCreateDate().c_str()));
			ui.MasterList->setItem(row, 2, new QTableWidgetItem(content.getFileType().c_str()));
			ui.MasterList->setItem(row, 3, new QTableWidgetItem(content.getInnerEvent().c_str()));
			ui.MasterList->setItem(row, 4, new QTableWidgetItem(content.getInnerPerson().c_str()));
			ui.MasterList->setItem(row, 5, new QTableWidgetItem(content.getInnerPlace().c_str())); //���̺� ������ ���� �߰�
		}
		Reload(); //���� ��ħ
	}
}