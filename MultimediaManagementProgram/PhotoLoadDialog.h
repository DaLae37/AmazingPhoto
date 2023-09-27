#pragma once
#include <QWidget>
#include <QDialog>
#include <QFileDialog>
#include "ui_PhotoLoadDialog.h"

class PhotoLoadDialog : public QDialog
{
	Q_OBJECT

public:
	PhotoLoadDialog(QWidget* parent = Q_NULLPTR); //������

private:
	Ui::PhotoLoadDialog ui;
	QString currentPhotoName; //�ӽ� ���� ��ü
	QPixmap currentPhoto;
	bool loadedCurrentPhoto;

public slots:
	//������ �ҷ����� ���� �Լ�
	void LoadPhoto();

	//������ �����ϱ� ���� �Լ�
	void SavePhoto();
};