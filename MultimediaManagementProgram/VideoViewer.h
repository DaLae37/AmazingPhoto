#pragma once
#include <QWidget>
#include "ui_VideoViewer.h"

class VideoViewer : public QWidget
{
	Q_OBJECT
		
public :
	VideoViewer(QWidget* parent = Q_NULLPTR);

private :
	Ui::VideoViewer ui;

private slots:
	//파일 이름으로 검색하는 함수
	void RetrieveFileName();

	//하나 이상의 키로 검색하는 함수
	void MultiRetrieve();
};