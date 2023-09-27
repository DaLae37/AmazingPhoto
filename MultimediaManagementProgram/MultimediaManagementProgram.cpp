#include "MultimediaManagementProgram.h"

MultimediaManagementProgram::MultimediaManagementProgram(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
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