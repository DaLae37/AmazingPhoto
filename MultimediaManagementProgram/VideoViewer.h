#pragma once
#include <QWidget>
#include "ui_VideoViewer.h"
#include "VideoViewWindow.h"

class VideoViewer : public QWidget
{
	Q_OBJECT
		
public :
	VideoViewer(QWidget* parent = Q_NULLPTR);
	~VideoViewer();

private :
	Ui::VideoViewer ui;
	VideoViewWindow* videoViewWindow; //비디오 재생 윈도우

private slots:
	//파일 이름으로 검색하는 함수
	void RetrieveFileName();

	//하나 이상의 키로 검색하는 함수
	void MultiRetrieve();

	//동영상을 보여주는 함수
	void OpenVideoFile();
};