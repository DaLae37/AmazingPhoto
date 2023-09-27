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
	PhotoViewDialog* photoViewDialog; //���� ��� ���̾�α�

private slots:
	//���� �̸����� �˻��ϴ� �Լ�
	void RetrieveFileName();

	//�ϳ� �̻��� Ű�� �˻��ϴ� �Լ�
	void MultiRetrieve();

	//������ �����ִ� �Լ�
	void OpenPhotoFile();
};