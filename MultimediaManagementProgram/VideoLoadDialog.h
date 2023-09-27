#pragma once
#include <QWidget>
#include <QDialog>
#include <QFileDialog>
#include <QtMultimedia/QMediaPlayer>
#include "ui_VideoLoadDialog.h"

class VideoLoadDialog : public QDialog
{
	Q_OBJECT

public:
	VideoLoadDialog(QWidget* parent = Q_NULLPTR); //생성자

private:
	Ui::VideoLoadDialog ui;
	QString currentVideoPath; //임시 저장 객체
	bool loadedCurrentVideo;

public slots:
	//비디오를 불러오기 위한 함수
	void LoadVideo();

	//비디오를 저장하기 위한 함수
	void SaveVideo();
};