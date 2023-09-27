#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MultimediaManagementProgram.h"
#include "ContentsManagement.h"
#include "PhotoViewer.h"
#include "VideoViewer.h"

#include "BinarySearchTree.h"
#include "MultimediaContent.h"
#include "Event.h"
#include "Person.h"
#include "Place.h"
#include <time.h>

class MultimediaManagementProgram : public QMainWindow
{
    Q_OBJECT

public:
    MultimediaManagementProgram(QWidget* parent = Q_NULLPTR); //������
    BinarySearchTree<MultimediaContent>* getMasterList(); //Master List�� �����ϴ� �Լ�
    BinarySearchTree<Event>* getEventList(); //Event List�� �����ϴ� �Լ�
    BinarySearchTree<Person>* getPersonList(); //Person List�� �����ϴ� �Լ�
    BinarySearchTree<Place>* getPlaceList(); //Place List�� �����ϴ� �Լ�

private:
    Ui::MultimediaManagementProgramClass ui;

    ContentsManagement* contentsManagement; //������ ���� â
    PhotoViewer* photoViewer; //���� ���� â
    VideoViewer* videoViewer; //���� ���� â

    BinarySearchTree<MultimediaContent> masterList; //Master List
    BinarySearchTree<Event> eventList; //Event List
    BinarySearchTree<Person> personList; //Person List
    BinarySearchTree<Place> placeList; //Place List

private slots:
    //������ ���� â�� ����
    void OpenContentsManagement();

    //���� ���� â�� ����
    void OpenPhotoViewer();

    //���� ���� â�� ����
    void OpenVideoViewer();
};