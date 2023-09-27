#pragma once
#include <QWidget>
#include "ui_PhotoViewer.h"
#include "PhotoViewDialog.h"

class PhotoViewer : public QWidget
{
	Q_OBJECT

public : 
	PhotoViewer(QWidget* parent = Q_NULLPTR);

private :
	Ui::PhotoViewer ui;
	PhotoViewDialog* photoViewDialog; //사진 재생 다이얼로그

private slots:
	//파일 이름으로 검색하는 함수
	void RetrieveFileName();

	//하나 이상의 키로 검색하는 함수
	void MultiRetrieve();

	//사진을 보여주는 함수
	void OpenPhotoFile();
};