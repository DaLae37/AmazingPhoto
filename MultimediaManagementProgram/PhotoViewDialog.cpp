#include "PhotoViewDialog.h"


PhotoViewDialog::PhotoViewDialog(QString fileName, QWidget* parent) : QDialog(parent)
{
	setWindowFlags(Qt::Window);
	ui.setupUi(this);

	QPixmap photo; //QPixmax파일을 생성하고
	photo.load("./Contents/Multimedia/" + fileName); //콘텐츠 폴더에서 파일을 읽어옴

	ui.PhotoPreview->setPixmap(photo); //사진 설정
	ui.PhotoPreview->setScaledContents(true);
}