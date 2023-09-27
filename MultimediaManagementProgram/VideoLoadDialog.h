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
	VideoLoadDialog(QWidget* parent = Q_NULLPTR); //������

private:
	Ui::VideoLoadDialog ui;
	QString currentVideoPath; //�ӽ� ���� ��ü
	bool loadedCurrentVideo;

public slots:
	//������ �ҷ����� ���� �Լ�
	void LoadVideo();

	//������ �����ϱ� ���� �Լ�
	void SaveVideo();
};