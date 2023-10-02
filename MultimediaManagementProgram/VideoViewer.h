#pragma once
#include <QWidget>
#include "ui_VideoViewer.h"
#include "VideoViewDialog.h"

class VideoViewer : public QWidget
{
	Q_OBJECT
		
public :
	VideoViewer(QWidget* parent = Q_NULLPTR);

private :
	Ui::VideoViewer ui;
	VideoViewDialog* videoViewDialog; //비디오 재생 다이얼로그

private slots:
	//파일 이름으로 검색하는 함수
	void RetrieveFileName();

	//하나 이상의 키로 검색하는 함수
	void MultiRetrieve();

	//동영상을 보여주는 함수
	void OpenVideoFile();
};