#include "MultimediaManagementProgram.h"

MultimediaManagementProgram::MultimediaManagementProgram(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);

	std::ifstream inFile;
	inFile.open("./Contents/Database/data.txt"); //데이터 폴더에 data.txt

	if (inFile) {
		while (!inFile.eof()) {
			MultimediaContent content;
			content.ReadDataFromFile(inFile); //콘텐츠를 임시 생성해 정보를 읽어옴
			if (inFile.eof() || content.getCreateDate() == "") {
				break;
			}
			getMasterList()->AddItem(content); //Master List에 해당 콘텐츠 추가

			bool isFind = false;

			Event* event = new Event;
			event->setEventName(content.getInnerEvent()); //이벤트를 임시 생성
			getEventList()->RetrieveItem(*event, isFind); //해당 이벤트가 존재하면
			event->AddId(content.getFileName()); //이벤트에 id를 추가
			if (!isFind) {
				getEventList()->AddItem(*event); //이번트가 존재하지 않았을 경우 이벤트를 생성
			}

			Person* person = new Person;
			person->setPersonName(content.getInnerPerson()); //인물을 임시 생성
			getPersonList()->RetrieveItem(*person, isFind); //해당 인물이 존재하면
			person->AddId(content.getFileName()); //인물에 id를 추가
			if (!isFind) {
				getPersonList()->AddItem(*person); //인물이 존재하지 않았을 경우 인물을 생성
			}

			Place* place = new Place;
			place->setPlaceName(content.getInnerPlace()); //장소를 임시 생성
			getPlaceList()->RetrieveItem(*place, isFind); //해당 장소가 존재하면
			place->AddId(content.getFileName()); //장소에 id를 추가
			if (!isFind) {
				getPlaceList()->AddItem(*place); //장소가 존재하지 않았을 경우 장소를 생성
			}
		}
	}
}

void MultimediaManagementProgram::OpenContentsManagement() { //콘텐츠 관리 창을 열음
    contentsManagement = new ContentsManagement(this);
    contentsManagement->show();
}

void MultimediaManagementProgram::OpenPhotoViewer() { //사진 보기 창을 열음
    photoViewer = new PhotoViewer(this);
    photoViewer->show();
}

void MultimediaManagementProgram::OpenVideoViewer() { //비디오 보기 창을 열음
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