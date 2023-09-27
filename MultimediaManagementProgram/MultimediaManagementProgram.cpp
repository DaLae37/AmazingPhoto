#include "MultimediaManagementProgram.h"

MultimediaManagementProgram::MultimediaManagementProgram(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
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