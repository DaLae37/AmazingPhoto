#include "MultimediaManagementProgram.h"

MultimediaManagementProgram::MultimediaManagementProgram(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);

	std::ifstream inFile;
	inFile.open("./Contents/Database/data.txt"); //������ ������ data.txt

	if (inFile) {
		while (!inFile.eof()) {
			MultimediaContent content;
			content.ReadDataFromFile(inFile); //�������� �ӽ� ������ ������ �о��
			if (inFile.eof() || content.getCreateDate() == "") {
				break;
			}
			getMasterList()->AddItem(content); //Master List�� �ش� ������ �߰�

			bool isFind = false;

			Event* event = new Event;
			event->setEventName(content.getInnerEvent()); //�̺�Ʈ�� �ӽ� ����
			getEventList()->RetrieveItem(*event, isFind); //�ش� �̺�Ʈ�� �����ϸ�
			event->AddId(content.getFileName()); //�̺�Ʈ�� id�� �߰�
			if (!isFind) {
				getEventList()->AddItem(*event); //�̹�Ʈ�� �������� �ʾ��� ��� �̺�Ʈ�� ����
			}

			Person* person = new Person;
			person->setPersonName(content.getInnerPerson()); //�ι��� �ӽ� ����
			getPersonList()->RetrieveItem(*person, isFind); //�ش� �ι��� �����ϸ�
			person->AddId(content.getFileName()); //�ι��� id�� �߰�
			if (!isFind) {
				getPersonList()->AddItem(*person); //�ι��� �������� �ʾ��� ��� �ι��� ����
			}

			Place* place = new Place;
			place->setPlaceName(content.getInnerPlace()); //��Ҹ� �ӽ� ����
			getPlaceList()->RetrieveItem(*place, isFind); //�ش� ��Ұ� �����ϸ�
			place->AddId(content.getFileName()); //��ҿ� id�� �߰�
			if (!isFind) {
				getPlaceList()->AddItem(*place); //��Ұ� �������� �ʾ��� ��� ��Ҹ� ����
			}
		}
	}
}

void MultimediaManagementProgram::OpenContentsManagement() { //������ ���� â�� ����
    contentsManagement = new ContentsManagement(this);
    contentsManagement->show();
}

void MultimediaManagementProgram::OpenPhotoViewer() { //���� ���� â�� ����
    photoViewer = new PhotoViewer(this);
    photoViewer->show();
}

void MultimediaManagementProgram::OpenVideoViewer() { //���� ���� â�� ����
    videoViewer = new VideoViewer(this);
    videoViewer->show();
}

BinarySearchTree<MultimediaContent>* MultimediaManagementProgram::getMasterList() { //master list
    return &masterList;
}

BinarySearchTree<Event>* MultimediaManagementProgram::getEventList() { //event list
    return &eventList;
}

BinarySearchTree<Person>* MultimediaManagementProgram::getPersonList() { //person list
    return &personList;
}

BinarySearchTree<Place>* MultimediaManagementProgram::getPlaceList() { //place list
    return &placeList;
}