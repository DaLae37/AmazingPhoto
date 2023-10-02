#include "VideoLoadDialog.h"
#include "ContentsManagement.h"

VideoLoadDialog::VideoLoadDialog(QWidget* parent) : QDialog(parent)
{
	setWindowFlags(Qt::Window);
	ui.setupUi(this);
	loadedCurrentVideo = false; //초기화
}

void VideoLoadDialog::LoadVideo()
{
	//동영상 열기 다이얼로그를 열어
	QFileDialog dialog;
	QString filePath = dialog.getOpenFileName(this, "Load Video", "", "Video Files (*.mp4 *.avi)");
	
	//파일 이름을 가져옴
	QString fileName = filePath.section("/", -1);
	ui.FileNameInput->setText(fileName);

	//동영상 객체 임시 저장
	currentVideoPath = filePath;
	loadedCurrentVideo = true;
}

void VideoLoadDialog::SaveVideo() {
	if (loadedCurrentVideo) { 
		QFile file(currentVideoPath); //선택한 동영상 파일
		QFile writeFile("./Contents/Multimedia/" + currentVideoPath.section("/", -1)); //생성될 동영상 파일
		file.open(QIODevice::ReadOnly);
		writeFile.open(QIODevice::WriteOnly);
		writeFile.write(file.readAll()); //선택한 동영상 파일에서 바이트코드를 읽어와 생성될 동영상 파일에 작성

		file.close(); //파일 스트림 닫기
		writeFile.close();
		((ContentsManagement*)parent())->Reload();
		this->close();
	}
}