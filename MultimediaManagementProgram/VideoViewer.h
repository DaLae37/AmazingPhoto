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
	VideoViewDialog* videoViewDialog; //���� ��� ���̾�α�

private slots:
	//���� �̸����� �˻��ϴ� �Լ�
	void RetrieveFileName();

	//�ϳ� �̻��� Ű�� �˻��ϴ� �Լ�
	void MultiRetrieve();

	//�������� �����ִ� �Լ�
	void OpenVideoFile();
};