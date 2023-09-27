#include "PhotoViewDialog.h"


PhotoViewDialog::PhotoViewDialog(QString fileName, QWidget* parent) : QDialog(parent)
{
	setWindowFlags(Qt::Window);
	ui.setupUi(this);

	QPixmap photo; //QPixmax������ �����ϰ�
	photo.load("./Contents/Multimedia/" + fileName); //������ �������� ������ �о��

	ui.PhotoPreview->setPixmap(photo); //���� ����
	ui.PhotoPreview->setScaledContents(true);
}