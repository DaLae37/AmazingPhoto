#include "VideoLoadDialog.h"
#include "ContentsManagement.h"

VideoLoadDialog::VideoLoadDialog(QWidget* parent) : QDialog(parent)
{
	setWindowFlags(Qt::Window);
	ui.setupUi(this);
	loadedCurrentVideo = false; //�ʱ�ȭ
}

void VideoLoadDialog::LoadVideo()
{
	//������ ���� ���̾�α׸� ����
	QFileDialog dialog;
	QString filePath = dialog.getOpenFileName(this, "Load Video", "", "Video Files (*.mp4 *.avi)");
	
	//���� �̸��� ������
	QString fileName = filePath.section("/", -1);
	ui.FileNameInput->setText(fileName);

	//������ ��ü �ӽ� ����
	currentVideoPath = filePath;
	loadedCurrentVideo = true;
}

void VideoLoadDialog::SaveVideo() {
	if (loadedCurrentVideo) { 
		QFile file(currentVideoPath); //������ ������ ����
		QFile writeFile("./Contents/Multimedia/" + currentVideoPath.section("/", -1)); //������ ������ ����
		file.open(QIODevice::ReadOnly);
		writeFile.open(QIODevice::WriteOnly);
		writeFile.write(file.readAll()); //������ ������ ���Ͽ��� ����Ʈ�ڵ带 �о�� ������ ������ ���Ͽ� �ۼ�

		file.close(); //���� ��Ʈ�� �ݱ�
		writeFile.close();
		((ContentsManagement*)parent())->Reload();
		this->close();
	}
}