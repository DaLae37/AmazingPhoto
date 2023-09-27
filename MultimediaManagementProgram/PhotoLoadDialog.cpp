#include "PhotoLoadDialog.h"
#include "ContentsManagement.h"

PhotoLoadDialog::PhotoLoadDialog(QWidget* parent) : QDialog(parent)
{
	setWindowFlags(Qt::Window);
	ui.setupUi(this);
	loadedCurrentPhoto = false; //초기화
}

void PhotoLoadDialog::LoadPhoto()
{
	//사진 열기 다이얼로그를 열어
	QFileDialog dialog;
	QString filePath = dialog.getOpenFileName(this, "Load Photo", "", "Photo Files (*.png *.jpg *.bmp)");

	//파일 이름을 가져옴
	QString fileName = filePath.section("/", -1);
	ui.FileNameInput->setText(fileName);


	//사진 객체를 만들어 사진을 등록
	QPixmap photo;
	photo.load(filePath);


	//가로와 세로 크기를 가져와 등록
	int w = photo.width();
	ui.WidthInput->setText(QString::number(w));
	int h = photo.height();
	ui.HeightInput->setText(QString::number(h));

	ui.PhotoPreview->setPixmap(photo);
	ui.PhotoPreview->setScaledContents(true);

	//사진 객체 임시 저장
	currentPhotoName = fileName;
	currentPhoto = photo;
	loadedCurrentPhoto = true;
}

void PhotoLoadDialog::SavePhoto() {
	if (loadedCurrentPhoto) { //임시 저장된 사진 객체를 실제 폴더에 저장
		currentPhoto.save("./Contents/Multimedia/" + currentPhotoName);
		this->close(); //그 후 다이얼로그를 닫음
	}
}