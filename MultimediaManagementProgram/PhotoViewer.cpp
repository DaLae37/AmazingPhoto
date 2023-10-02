#include "PhotoViewer.h"
#include "MultimediaManagementProgram.h"
#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"

PhotoViewer::PhotoViewer(QWidget* parent) : QWidget(parent) {
	setWindowFlag(Qt::Window);
	ui.setupUi(this);
}

void PhotoViewer::RetrieveFileName() {
	ui.RetrieveResult->clear(); //���� ��� ����Ʈ�� �����

	std::string fileName = ui.FileNameInput->text().toStdString(); //�Է��� ���� �̸��� ������

	MultimediaContent content;
	content.SetRecord(fileName, "", "", "", "", "", 0); //������ �ӽ� ����

	bool isFind = false;
	((MultimediaManagementProgram*)parent())->getMasterList()->RetrieveItem(content, isFind); //Master List���� Ž��

	if (isFind) { //Ž���� �����Ͽ�����
		ui.RetrieveResult->addItem(fileName.c_str()); //��� ����Ʈ�� �߰�
	}
}

void PhotoViewer::MultiRetrieve() {
	ui.RetrieveResult->clear(); //���� ��� ����Ʈ�� �����

	MultimediaContent content;
	Event event;
	Person person;
	Place place;

	std::string eventName = ui.EventNameInput->text().toStdString(); //�Է��� �̺�Ʈ �̸��� ������
	std::string personName = ui.PersonNameInput->text().toStdString(); //�Է��� �ι� �̸��� ������
	std::string placeName = ui.PlaceNameInput->text().toStdString(); //�Է��� ��� �̸��� ������

	bool isFind = false;
	int command = 0;

	if (eventName != "" && personName != "" && placeName == "") { //�̺�Ʈ�� �ι��� �Է����� ��
		command = 1; //Ŀ���� 1
	}
	else if (eventName != "" && personName == "" && placeName != "") { //�̺�Ʈ�� ��Ҹ� �Է����� ��
		command = 2; //Ŀ���� 2
	}
	else if (eventName == "" && personName != "" && placeName != "") { //�ι��� ��Ҹ� �Է����� ��
		command = 3; //Ŀ���� 3
	}
	else if (eventName != "" && personName != "" && placeName != "") { //��� �Է� ���� ��
		command = 4; //Ŀ���� 4
	}

	if (command == 1 || command == 2 || command == 3) {
		if (command == 1) {
			event.setEventName(eventName); //�̺�Ʈ �̸� ����
			isFind = false;
			((MultimediaManagementProgram*)parent())->getEventList()->RetrieveItem(event, isFind); //�̺�Ʈ ����Ʈ���� Ž��

			if (!isFind) { //���� �߰ߵ��� �ʾ�����
				return; //�Լ� ����
			}

			person.setPersonName(personName); //�ι� �̸� ����
			isFind = false;
			((MultimediaManagementProgram*)parent())->getPersonList()->RetrieveItem(person, isFind); //�ι� ����Ʈ���� Ž��

			if (!isFind) { //���� �߰ߵ��� �ʾ�����
				return; //�Լ� ����
			}

			DoublyLinkedListIterator<std::string> iter1(event.GetIdList()); //���̵� �޾ƿ� Iterator�� ����

			while (iter1.NotNull()) {
				DoublyLinkedListIterator<std::string> iter2(person.GetIdList());
				while (iter2.NotNull()) {
					if (iter1.getCurrentPointer()->record == iter2.getCurrentPointer()->record) { //���� �� ������ ������ Ű�� �߰�������
						content.SetRecord(iter1.getCurrentPointer()->record, "", "", "", "", "", 0); //������ �ӽ� ����

						isFind = false;
						((MultimediaManagementProgram*)parent())->getMasterList()->RetrieveItem(content, isFind); //Master List���� Ž��
						if (isFind) { //MasterList�� �����ϸ�
							ui.RetrieveResult->addItem(iter1.getCurrentPointer()->record.c_str()); //�� ���� ��� ����Ʈ�� �߰�
						}
					}
					iter2.Next();
				}
				iter1.Next();
			}
		}
		else if (command == 2) {
			event.setEventName(eventName); //�̺�Ʈ �̸� ����
			isFind = false;
			((MultimediaManagementProgram*)parent())->getEventList()->RetrieveItem(event, isFind); //�̺�Ʈ ����Ʈ���� Ž��

			if (!isFind) { //���� �߰ߵ��� �ʾ�����
				return; //�Լ� ����
			}

			place.setPlaceName(placeName); //��� �̸� ����
			isFind = false;
			((MultimediaManagementProgram*)parent())->getPlaceList()->RetrieveItem(place, isFind); //��� ����Ʈ���� Ž��

			if (!isFind) { //���� �߰ߵ��� �ʾ�����
				return; //�Լ� ����
			}

			DoublyLinkedListIterator<std::string> iter1(event.GetIdList()); //���̵� �޾ƿ� Iterator�� ����

			while (iter1.NotNull()) {
				DoublyLinkedListIterator<std::string> iter2(place.GetIdList());
				while (iter2.NotNull()) {
					if (iter1.getCurrentPointer()->record == iter2.getCurrentPointer()->record) { //���� �� ������ ������ Ű�� �߰�������
						content.SetRecord(iter1.getCurrentPointer()->record, "", "", "", "", "", 0); //������ �ӽ� ����

						isFind = false;
						((MultimediaManagementProgram*)parent())->getMasterList()->RetrieveItem(content, isFind); //Master List���� Ž��
						if (isFind) { //MasterList�� �����ϸ�
							ui.RetrieveResult->addItem(iter1.getCurrentPointer()->record.c_str()); //�� ���� ��� ����Ʈ�� �߰�
						}
					}
					iter2.Next();
				}
				iter1.Next();
			}
		}
		else {
			person.setPersonName(personName); //�ι� �̸� ����
			isFind = false;
			((MultimediaManagementProgram*)parent())->getPersonList()->RetrieveItem(person, isFind); //�ι� ����Ʈ���� Ž��

			if (!isFind) { //���� �߰ߵ��� �ʾ�����
				return; //�Լ� ����
			}

			place.setPlaceName(placeName); //��� �̸� ����
			isFind = false;
			((MultimediaManagementProgram*)parent())->getPlaceList()->RetrieveItem(place, isFind); //��� ����Ʈ���� Ž��

			if (!isFind) { //���� �߰ߵ��� �ʾ�����
				return; //�Լ� ����
			}

			DoublyLinkedListIterator<std::string> iter1(person.GetIdList()); //���̵� �޾ƿ� Iterator�� ����

			while (iter1.NotNull()) {
				DoublyLinkedListIterator<std::string> iter2(place.GetIdList());
				while (iter2.NotNull()) {
					if (iter1.getCurrentPointer()->record == iter2.getCurrentPointer()->record) { //���� �� ������ ������ Ű�� �߰�������
						content.SetRecord(iter1.getCurrentPointer()->record, "", "", "", "", "", 0); //������ �ӽ� ����

						isFind = false;
						((MultimediaManagementProgram*)parent())->getMasterList()->RetrieveItem(content, isFind); //Master List���� Ž��
						if (isFind) { //MasterList�� �����ϸ�
							ui.RetrieveResult->addItem(iter1.getCurrentPointer()->record.c_str()); //�� ���� ��� ����Ʈ�� �߰�
						}
					}
					iter2.Next();
				}
				iter1.Next();
			}
		}
	}
	else if (command == 4) {
		event.setEventName(eventName); //�̺�Ʈ �̸� ����
		isFind = false;
		((MultimediaManagementProgram*)parent())->getEventList()->RetrieveItem(event, isFind); //�̺�Ʈ ����Ʈ���� Ž��

		if (!isFind) { //���� �߰ߵ��� �ʾ�����
			return; //�Լ� ����
		}

		person.setPersonName(personName); //�ι� �̸� ����
		isFind = false;
		((MultimediaManagementProgram*)parent())->getPersonList()->RetrieveItem(person, isFind); //�ι� ����Ʈ���� Ž��

		if (!isFind) { //���� �߰ߵ��� �ʾ�����
			return; //�Լ� ����
		}

		place.setPlaceName(placeName); //��� �̸� ����
		isFind = false;
		((MultimediaManagementProgram*)parent())->getPlaceList()->RetrieveItem(place, isFind); //��� ����Ʈ���� Ž��

		if (!isFind) { //���� �߰ߵ��� �ʾ�����
			return; //�Լ� ����
		}

		DoublyLinkedListIterator<std::string> iter1(event.GetIdList()); //���̵� �޾ƿ� Iterator�� ����

		while (iter1.NotNull()) {
			DoublyLinkedListIterator<std::string> iter2(person.GetIdList());
			while (iter2.NotNull()) {
				DoublyLinkedListIterator<std::string> iter3(place.GetIdList());
				while (iter3.NotNull()) {
					if (iter1.getCurrentPointer()->record == iter2.getCurrentPointer()->record && iter2.getCurrentPointer()->record == iter3.getCurrentPointer()->record) { //���� �� ������ ������ Ű�� �߰�������
						content.SetRecord(iter1.getCurrentPointer()->record, "", "", "", "", "", 0); //������ �ӽ� ����

						isFind = false;
						((MultimediaManagementProgram*)parent())->getMasterList()->RetrieveItem(content, isFind); //Master List���� Ž��
						if (isFind) { //MasterList�� �����ϸ�
							ui.RetrieveResult->addItem(iter1.getCurrentPointer()->record.c_str()); //�� ���� ��� ����Ʈ�� �߰�
						}
					}
					iter3.Next();
				}
				iter2.Next();
			}
			iter1.Next();
		}
	}
}

void PhotoViewer::OpenPhotoFile() {
	photoViewDialog = new PhotoViewDialog(ui.RetrieveResult->currentItem()->text(), this); //���� ��� ���̾�α׸� ���� �Ҵ�
	photoViewDialog->show(); //ȭ���� ���
}