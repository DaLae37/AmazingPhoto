#include "ContentsManagement.h"
#include "MultimediaManagementProgram.h"

ContentsManagement::ContentsManagement(QWidget* parent) : QWidget(parent) {
	setWindowFlags(Qt::Window);
	ui.setupUi(this);

	Reload(); //콘텐츠 폴더에 존재하는 파일을 불러온다.
	LoadFromFile();
	if (!((MultimediaManagementProgram*)parent)->getMasterList()->IsEmpty()) { //Master List가 비어있지 않으면
		UpdateMasterList(((MultimediaManagementProgram*)parent)->getMasterList()->getRoot(), 0); //테이블 리스트를 업데이트
	}
}

void ContentsManagement::SelectUnregisterFile() { //미등록 리스트의 아이템을 클릭했을 때
	isUnregisterSelected = true;
	selectedUnregisterFileName = ui.UnregisterFile->currentItem()->text(); //그 리스트의 아이템을 받아와서 (파일 이름)
	ui.FileNamePrint->setText(selectedUnregisterFileName); //파일 이름을 등록 (파일 이름 출력)
	ui.FileTypePrint->setText(selectedUnregisterFileName.section(".", -1)); //파싱 후 파일의 확장자를 등록
	isRegisterSelected = false; //등록 리스트의 선택은 해제
}

void ContentsManagement::SelectRegisterFile() {
	isUnregisterSelected = false;
	int row = ui.MasterList->currentItem()->row(); //등록리스트에서 선택한 아이템의 인덱스를 탐색
	selectedRegisterFileName = ui.MasterList->item(row, 0)->text(); //그 인덱스를 통해 0번 컬럼인 파일이름을 저장
	isRegisterSelected = true; //미등록 리스트의 선택은 해제
}

void ContentsManagement::OpenPhotoLoadDialog() { //사진 불러오기 다이얼로그 오픈
	photoLoadDialog = new PhotoLoadDialog(this);
	photoLoadDialog->show();
}

void ContentsManagement::OpenVideoLoadDialog() { //비디오 블러오기 다이얼로그 오픈
	videoLoadDialog = new VideoLoadDialog(this);
	videoLoadDialog->show();
}

void ContentsManagement::Reload() {
	ui.UnregisterFile->clear(); //우선 미등록 콘텐츠 리스트를 비움

	std::string searching = "./Contents/Multimedia/*.*"; //콘텐츠 파일이 있는 폴더

	_finddata_t fd;
	intptr_t handle = _findfirst(searching.c_str(), &fd);  //현재 폴더 내 모든 파일을 찾는다.

	if (handle == -1) { //파일이 없는 등 에러가 있으면 종료
		return;
	}
	else {
		int result = 0;
		do
		{
			if (!(fd.attrib & _A_SUBDIR)) { //찾은 파일이 폴더가 아닐 때
				bool isFind = false;
				MultimediaContent content;
				content.SetRecord(fd.name, "", "", "", "", "", 0); //임시적으로 콘텐츠를 생성하고
				((MultimediaManagementProgram*)parent())->getMasterList()->RetrieveItem(content, isFind); //MasterList에서 존재하는지 탐색
				if (!isFind) { //MasterList에 없을 경우
					ui.UnregisterFile->addItem(fd.name); //미등록 리스트에 추가
				}
			}
			result = _findnext(handle, &fd); //반복
		} while (result != -1); //파일이 없거나 에러가 날 때까지

		_findclose(handle);
	}
}

void ContentsManagement::MakeEmpty() { //모든 리스트를 비움
	int row = ui.MasterList->rowCount(); //등록 리스트의 길이를 가져와
	for (int i = 0; i < row; i++) {
		ui.MasterList->removeRow(0); //모든 행을 삭제함
	}
	
	((MultimediaManagementProgram*)parent())->getMasterList()->MakeEmpty(); //모든 리스트를 비워줌
	((MultimediaManagementProgram*)parent())->getEventList()->MakeEmpty();
	((MultimediaManagementProgram*)parent())->getPersonList()->MakeEmpty();
	((MultimediaManagementProgram*)parent())->getPlaceList()->MakeEmpty();
	Reload(); //미등록 리스트를 새로고침
}

void ContentsManagement::AddItem() { //아이템을 추가
	if (isUnregisterSelected) { //미등록 리스트에서 아이템이 선택되었을 때
		MultimediaContent content; //콘텐츠를 임시 생성
		time_t timeT = time(nullptr);
		struct tm* timer = localtime(&timeT); //유닉스 시간을 통해 현재 시간을 가져옴

		std::string fileName = ui.FileNamePrint->text().toStdString(); //파일 이름
		std::string fileType = ui.FileTypePrint->text().toStdString(); //확장자
		std::string createDate = std::to_string(timer->tm_year + 1900) + "-" + std::to_string(timer->tm_mon + 1) + "-" + std::to_string(timer->tm_mday) + "-" + std::to_string(timer->tm_hour) + "-" + std::to_string(timer->tm_min) + "-" + std::to_string(timer->tm_sec);
		std::string eventName = ui.EventNameInput->text().toStdString(); //입력한 이벤트 이름을 가져옴
		std::string personName = ui.PersonNameInput->text().toStdString(); //입력한 인물 이름을 가져옴
		std::string placeName = ui.PlaceNameInput->text().toStdString(); //입력한 장소 이름을 가져옴

		content.SetRecord(fileName, fileType, createDate, eventName, personName, placeName, 0); //콘텐츠를 초기화
		((MultimediaManagementProgram*)parent())->getMasterList()->AddItem(content); //마스터 리스트에 추가

		bool isFind = false;

		Event event;
		event.setEventName(eventName); //이벤트를 임시 생성
		((MultimediaManagementProgram*)parent())->getEventList()->RetrieveItem(event, isFind); //해당 이벤트가 존재하면
		if (!isFind) {
			((MultimediaManagementProgram*)parent())->getEventList()->AddItem(event); //이번트가 존재하지 않았을 경우 이벤트를 생성
		}
		else {
			event.AddId(fileName); //이벤트에 id를 추가
		}

		Person person;
		person.setPersonName(personName); //인물을 임시 생성
		((MultimediaManagementProgram*)parent())->getPersonList()->RetrieveItem(person, isFind); //해당 인물이 존재하면
		if (!isFind) {
			((MultimediaManagementProgram*)parent())->getPersonList()->AddItem(person); //인물이 존재하지 않았을 경우 인물을 생성
		}
		else {
			person.AddId(fileName); //인물에 id를 추가
		}

		Place place;
		place.setPlaceName(placeName); //장소를 임시 생성
		((MultimediaManagementProgram*)parent())->getPlaceList()->RetrieveItem(place, isFind); //해당 장소가 존재하면
		if (!isFind) {
			((MultimediaManagementProgram*)parent())->getPlaceList()->AddItem(place); //장소가 존재하지 않았을 경우 장소를 생성
		}
		else {
			place.AddId(fileName); //장소에 id를 추가
		}

		int row = ui.MasterList->rowCount(); //등록 리스트의 인덱스를 받아와
		ui.MasterList->setRowCount(row + 1);
		ui.MasterList->setItem(row, 0, new QTableWidgetItem(ui.FileNamePrint->text()));
		ui.MasterList->setItem(row, 1, new QTableWidgetItem(createDate.c_str()));
		ui.MasterList->setItem(row, 2, new QTableWidgetItem(ui.FileTypePrint->text()));
		ui.MasterList->setItem(row, 3, new QTableWidgetItem(ui.EventNameInput->text()));
		ui.MasterList->setItem(row, 4, new QTableWidgetItem(ui.PersonNameInput->text()));
		ui.MasterList->setItem(row, 5, new QTableWidgetItem(ui.PlaceNameInput->text())); //등록 리스트에 값을 추가
	}
	isUnregisterSelected = false; //초기화
	ui.FileNamePrint->setText("");
	ui.FileTypePrint->setText("");
	ui.EventNameInput->setText("");
	ui.PersonNameInput->setText("");
	ui.PlaceNameInput->setText(""); //입력 칸 비우기
	Reload(); //새로 고침
}

void ContentsManagement::DeleteItem() { //아이템 삭제
	if (isRegisterSelected) { //등록 리스트에서 선택된 아이템이 있을 때
		MultimediaContent content;
		content.SetRecord(selectedRegisterFileName.toStdString(), "", "", "", "", "", 0); //콘텐츠 임시 생성
		((MultimediaManagementProgram*)parent())->getMasterList()->DeleteItem(content); //삭제
		Reload(); //새로고침
		int index = ui.MasterList->currentRow();
		ui.MasterList->removeRow(index); //등록 리스트에서 해당 아이템 삭제
	}
}

void ContentsManagement::SaveToFile() { //파일에 Master List의 정보를 저장
	std::ofstream outFile;
	outFile.open("./Contents/Database/data.txt"); //데이터 폴더에 data.txt

	if (outFile) {
		if (!((MultimediaManagementProgram*)parent())->getMasterList()->IsEmpty()) { //Master List가 비어있지 않으면
			SaveFile(((MultimediaManagementProgram*)parent())->getMasterList()->getRoot(), outFile); //재귀를 통해 저장
		}
	}
}

void ContentsManagement::LoadFromFile() { //파일로부터 정보를 읽어옴
	MakeEmpty();
	std::ifstream inFile;
	inFile.open("./Contents/Database/data.txt"); //데이터 폴더에 data.txt
	int row = ui.MasterList->rowCount();
	for (int i = 0; i < row; i++) {
		ui.MasterList->removeRow(i);
	}
	if (inFile) {
		while (!inFile.eof()) {
			MultimediaContent content;
			content.ReadDataFromFile(inFile); //콘텐츠를 임시 생성해 정보를 읽어옴
			if (inFile.eof() || content.getCreateDate() == "") {
				break;
			}
			((MultimediaManagementProgram*)parent())->getMasterList()->AddItem(content); //Master List에 해당 콘텐츠 추가

			bool isFind = false;

			Event *event = new Event;
			event->setEventName(content.getInnerEvent()); //이벤트를 임시 생성
			((MultimediaManagementProgram*)parent())->getEventList()->RetrieveItem(*event, isFind); //해당 이벤트가 존재하면
			event->AddId(content.getFileName()); //이벤트에 id를 추가
			if (!isFind) {
				((MultimediaManagementProgram*)parent())->getEventList()->AddItem(*event); //이번트가 존재하지 않았을 경우 이벤트를 생성
			}

			Person *person = new Person;
			person->setPersonName(content.getInnerPerson()); //인물을 임시 생성
			((MultimediaManagementProgram*)parent())->getPersonList()->RetrieveItem(*person, isFind); //해당 인물이 존재하면
			person->AddId(content.getFileName()); //인물에 id를 추가
			if (!isFind) {
				((MultimediaManagementProgram*)parent())->getPersonList()->AddItem(*person); //인물이 존재하지 않았을 경우 인물을 생성
			}

			Place *place = new Place;
			place->setPlaceName(content.getInnerPlace()); //장소를 임시 생성
			((MultimediaManagementProgram*)parent())->getPlaceList()->RetrieveItem(*place, isFind); //해당 장소가 존재하면
			place->AddId(content.getFileName()); //장소에 id를 추가
			if (!isFind) {
				((MultimediaManagementProgram*)parent())->getPlaceList()->AddItem(*place); //장소가 존재하지 않았을 경우 장소를 생성
			}

			row = ui.MasterList->rowCount(); //등록 리스트의 인덱스를 가져와서
			ui.MasterList->setRowCount(row + 1);
			ui.MasterList->setItem(row, 0, new QTableWidgetItem(content.getFileName().c_str()));
			ui.MasterList->setItem(row, 1, new QTableWidgetItem(content.getCreateDate().c_str()));
			ui.MasterList->setItem(row, 2, new QTableWidgetItem(content.getFileType().c_str()));
			ui.MasterList->setItem(row, 3, new QTableWidgetItem(content.getInnerEvent().c_str()));
			ui.MasterList->setItem(row, 4, new QTableWidgetItem(content.getInnerPerson().c_str()));
			ui.MasterList->setItem(row, 5, new QTableWidgetItem(content.getInnerPlace().c_str())); //테이블 위젯에 정보 추가
		}
		Reload(); //새로 고침
	}
}