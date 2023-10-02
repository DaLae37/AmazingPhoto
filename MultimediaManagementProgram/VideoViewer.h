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
	VideoViewWindow* videoViewWindow; //���� ��� ������

private slots:
	//���� �̸����� �˻��ϴ� �Լ�
	void RetrieveFileName();

	//�ϳ� �̻��� Ű�� �˻��ϴ� �Լ�
	void MultiRetrieve();

	//�������� �����ִ� �Լ�
	void OpenVideoFile();
};