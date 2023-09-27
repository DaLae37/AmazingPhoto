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
    MultimediaManagementProgram(QWidget* parent = Q_NULLPTR); //생성자
    BinarySearchTree<MultimediaContent>* getMasterList(); //Master List에 접근하는 함수
    BinarySearchTree<Event>* getEventList(); //Event List에 접근하는 함수
    BinarySearchTree<Person>* getPersonList(); //Person List에 접근하는 함수
    BinarySearchTree<Place>* getPlaceList(); //Place List에 접근하는 함수

private:
    Ui::MultimediaManagementProgramClass ui;

    ContentsManagement* contentsManagement; //콘텐츠 관리 창
    PhotoViewer* photoViewer; //사진 보기 창
    VideoViewer* videoViewer; //비디오 보기 창

    BinarySearchTree<MultimediaContent> masterList; //Master List
    BinarySearchTree<Event> eventList; //Event List
    BinarySearchTree<Person> personList; //Person List
    BinarySearchTree<Place> placeList; //Place List

private slots:
    //콘텐츠 관리 창을 열음
    void OpenContentsManagement();

    //사진 보기 창을 열음
    void OpenPhotoViewer();

    //비디오 보기 창을 열음
    void OpenVideoViewer();
};