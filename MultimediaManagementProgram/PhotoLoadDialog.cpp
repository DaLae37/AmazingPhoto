#include "PhotoLoadDialog.h"
#include "ContentsManagement.h"

PhotoLoadDialog::PhotoLoadDialog(QWidget* parent) : QDialog(parent)
{
	setWindowFlags(Qt::Window);
	ui.setupUi(this);
	loadedCurrentPhoto = false; //�ʱ�ȭ
}

void PhotoLoadDialog::LoadPhoto()
{
	//���� ���� ���̾�α׸� ����
	QFileDialog dialog;
	QString filePath = dialog.getOpenFileName(this, "Load Photo", "", "Photo Files (*.png *.jpg *.bmp)");

	//���� �̸��� ������
	QString fileName = filePath.section("/", -1);
	ui.FileNameInput->setText(fileName);


	//���� ��ü�� ����� ������ ���
	QPixmap photo;
	photo.load(filePath);


	//���ο� ���� ũ�⸦ ������ ���
	int w = photo.width();
	ui.WidthInput->setText(QString::number(w));
	int h = photo.height();
	ui.HeightInput->setText(QString::number(h));

	ui.PhotoPreview->setPixmap(photo);
	ui.PhotoPreview->setScaledContents(true);

	//���� ��ü �ӽ� ����
	currentPhotoName = fileName;
	currentPhoto = photo;
	loadedCurrentPhoto = true;
}

void PhotoLoadDialog::SavePhoto() {
	if (loadedCurrentPhoto) { //�ӽ� ����� ���� ��ü�� ���� ������ ����
		currentPhoto.save("./Contents/Multimedia/" + currentPhotoName);
		this->close(); //�� �� ���̾�α׸� ����
	}
}