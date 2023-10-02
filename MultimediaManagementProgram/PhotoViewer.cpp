#include "PhotoViewer.h"
#include "MultimediaManagementProgram.h"
#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"

PhotoViewer::PhotoViewer(QWidget* parent) : QWidget(parent) {
	setWindowFlag(Qt::Window);
	ui.setupUi(this);
}

void PhotoViewer::RetrieveFileName() {
	ui.RetrieveResult->clear(); //먼저 결과 리스트를 비워줌

	std::string fileName = ui.FileNameInput->text().toStdString(); //입력한 파일 이름을 가져옴

	MultimediaContent content;
	content.SetRecord(fileName, "", "", "", "", "", 0); //콘텐츠 임시 생성

	bool isFind = false;
	((MultimediaManagementProgram*)parent())->getMasterList()->RetrieveItem(content, isFind); //Master List에서 탐색

	if (isFind) { //탐색에 성공하였으면
		ui.RetrieveResult->addItem(fileName.c_str()); //결과 리스트에 추가
	}
}

void PhotoViewer::MultiRetrieve() {
	ui.RetrieveResult->clear(); //먼저 결과 리스트를 비워줌

	MultimediaContent content;
	Event event;
	Person person;
	Place place;

	std::string eventName = ui.EventNameInput->text().toStdString(); //입력한 이벤트 이름을 가져옴
	std::string personName = ui.PersonNameInput->text().toStdString(); //입력한 인물 이름을 가져옴
	std::string placeName = ui.PlaceNameInput->text().toStdString(); //입력한 장소 이름을 가져옴

	bool isFind = false;
	int command = 0;

	if (eventName != "" && personName != "" && placeName == "") { //이벤트와 인물을 입력했을 때
		command = 1; //커멘드는 1
	}
	else if (eventName != "" && personName == "" && placeName != "") { //이벤트와 장소를 입력했을 때
		command = 2; //커멘드는 2
	}
	else if (eventName == "" && personName != "" && placeName != "") { //인물과 장소를 입력했을 때
		command = 3; //커멘드는 3
	}
	else if (eventName != "" && personName != "" && placeName != "") { //모두 입력 했을 때
		command = 4; //커멘드는 4
	}

	if (command == 1 || command == 2 || command == 3) {
		if (command == 1) {
			event.setEventName(eventName); //이벤트 이름 지정
			isFind = false;
			((MultimediaManagementProgram*)parent())->getEventList()->RetrieveItem(event, isFind); //이벤트 리스트에서 탐색

			if (!isFind) { //만약 발견되지 않았으면
				return; //함수 종료
			}

			person.setPersonName(personName); //인물 이름 지정
			isFind = false;
			((MultimediaManagementProgram*)parent())->getPersonList()->RetrieveItem(person, isFind); //인물 리스트에서 탐색

			if (!isFind) { //만약 발견되지 않았으면
				return; //함수 종료
			}

			DoublyLinkedListIterator<std::string> iter1(event.GetIdList()); //아이디를 받아와 Iterator를 생성

			while (iter1.NotNull()) {
				DoublyLinkedListIterator<std::string> iter2(person.GetIdList());
				while (iter2.NotNull()) {
					if (iter1.getCurrentPointer()->record == iter2.getCurrentPointer()->record) { //만약 두 곳에서 동일한 키를 발견했으면
						content.SetRecord(iter1.getCurrentPointer()->record, "", "", "", "", "", 0); //콘텐츠 임시 생성

						isFind = false;
						((MultimediaManagementProgram*)parent())->getMasterList()->RetrieveItem(content, isFind); //Master List에서 탐색
						if (isFind) { //MasterList에 존재하면
							ui.RetrieveResult->addItem(iter1.getCurrentPointer()->record.c_str()); //그 값을 결과 리스트에 추가
						}
					}
					iter2.Next();
				}
				iter1.Next();
			}
		}
		else if (command == 2) {
			event.setEventName(eventName); //이벤트 이름 지정
			isFind = false;
			((MultimediaManagementProgram*)parent())->getEventList()->RetrieveItem(event, isFind); //이벤트 리스트에서 탐색

			if (!isFind) { //만약 발견되지 않았으면
				return; //함수 종료
			}

			place.setPlaceName(placeName); //장소 이름 지정
			isFind = false;
			((MultimediaManagementProgram*)parent())->getPlaceList()->RetrieveItem(place, isFind); //장소 리스트에서 탐색

			if (!isFind) { //만약 발견되지 않았으면
				return; //함수 종료
			}

			DoublyLinkedListIterator<std::string> iter1(event.GetIdList()); //아이디를 받아와 Iterator를 생성

			while (iter1.NotNull()) {
				DoublyLinkedListIterator<std::string> iter2(place.GetIdList());
				while (iter2.NotNull()) {
					if (iter1.getCurrentPointer()->record == iter2.getCurrentPointer()->record) { //만약 두 곳에서 동일한 키를 발견했으면
						content.SetRecord(iter1.getCurrentPointer()->record, "", "", "", "", "", 0); //콘텐츠 임시 생성

						isFind = false;
						((MultimediaManagementProgram*)parent())->getMasterList()->RetrieveItem(content, isFind); //Master List에서 탐색
						if (isFind) { //MasterList에 존재하면
							ui.RetrieveResult->addItem(iter1.getCurrentPointer()->record.c_str()); //그 값을 결과 리스트에 추가
						}
					}
					iter2.Next();
				}
				iter1.Next();
			}
		}
		else {
			person.setPersonName(personName); //인물 이름 지정
			isFind = false;
			((MultimediaManagementProgram*)parent())->getPersonList()->RetrieveItem(person, isFind); //인물 리스트에서 탐색

			if (!isFind) { //만약 발견되지 않았으면
				return; //함수 종료
			}

			place.setPlaceName(placeName); //장소 이름 지정
			isFind = false;
			((MultimediaManagementProgram*)parent())->getPlaceList()->RetrieveItem(place, isFind); //장소 리스트에서 탐색

			if (!isFind) { //만약 발견되지 않았으면
				return; //함수 종료
			}

			DoublyLinkedListIterator<std::string> iter1(person.GetIdList()); //아이디를 받아와 Iterator를 생성

			while (iter1.NotNull()) {
				DoublyLinkedListIterator<std::string> iter2(place.GetIdList());
				while (iter2.NotNull()) {
					if (iter1.getCurrentPointer()->record == iter2.getCurrentPointer()->record) { //만약 두 곳에서 동일한 키를 발견했으면
						content.SetRecord(iter1.getCurrentPointer()->record, "", "", "", "", "", 0); //콘텐츠 임시 생성

						isFind = false;
						((MultimediaManagementProgram*)parent())->getMasterList()->RetrieveItem(content, isFind); //Master List에서 탐색
						if (isFind) { //MasterList에 존재하면
							ui.RetrieveResult->addItem(iter1.getCurrentPointer()->record.c_str()); //그 값을 결과 리스트에 추가
						}
					}
					iter2.Next();
				}
				iter1.Next();
			}
		}
	}
	else if (command == 4) {
		event.setEventName(eventName); //이벤트 이름 지정
		isFind = false;
		((MultimediaManagementProgram*)parent())->getEventList()->RetrieveItem(event, isFind); //이벤트 리스트에서 탐색

		if (!isFind) { //만약 발견되지 않았으면
			return; //함수 종료
		}

		person.setPersonName(personName); //인물 이름 지정
		isFind = false;
		((MultimediaManagementProgram*)parent())->getPersonList()->RetrieveItem(person, isFind); //인물 리스트에서 탐색

		if (!isFind) { //만약 발견되지 않았으면
			return; //함수 종료
		}

		place.setPlaceName(placeName); //장소 이름 지정
		isFind = false;
		((MultimediaManagementProgram*)parent())->getPlaceList()->RetrieveItem(place, isFind); //장소 리스트에서 탐색

		if (!isFind) { //만약 발견되지 않았으면
			return; //함수 종료
		}

		DoublyLinkedListIterator<std::string> iter1(event.GetIdList()); //아이디를 받아와 Iterator를 생성

		while (iter1.NotNull()) {
			DoublyLinkedListIterator<std::string> iter2(person.GetIdList());
			while (iter2.NotNull()) {
				DoublyLinkedListIterator<std::string> iter3(place.GetIdList());
				while (iter3.NotNull()) {
					if (iter1.getCurrentPointer()->record == iter2.getCurrentPointer()->record && iter2.getCurrentPointer()->record == iter3.getCurrentPointer()->record) { //만약 두 곳에서 동일한 키를 발견했으면
						content.SetRecord(iter1.getCurrentPointer()->record, "", "", "", "", "", 0); //콘텐츠 임시 생성

						isFind = false;
						((MultimediaManagementProgram*)parent())->getMasterList()->RetrieveItem(content, isFind); //Master List에서 탐색
						if (isFind) { //MasterList에 존재하면
							ui.RetrieveResult->addItem(iter1.getCurrentPointer()->record.c_str()); //그 값을 결과 리스트에 추가
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
	photoViewDialog = new PhotoViewDialog(ui.RetrieveResult->currentItem()->text(), this); //사진 재생 다이얼로그를 동적 할당
	photoViewDialog->show(); //화면을 띄움
}