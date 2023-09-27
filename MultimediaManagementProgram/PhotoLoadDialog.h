#pragma once
#include <QWidget>
#include <QDialog>
#include <QFileDialog>
#include "ui_PhotoLoadDialog.h"

class PhotoLoadDialog : public QDialog
{
	Q_OBJECT

public:
	PhotoLoadDialog(QWidget* parent = Q_NULLPTR); //생성자

private:
	Ui::PhotoLoadDialog ui;
	QString currentPhotoName; //임시 저장 객체
	QPixmap currentPhoto;
	bool loadedCurrentPhoto;

public slots:
	//사진을 불러오기 위한 함수
	void LoadPhoto();

	//사진을 저장하기 위한 함수
	void SavePhoto();
};