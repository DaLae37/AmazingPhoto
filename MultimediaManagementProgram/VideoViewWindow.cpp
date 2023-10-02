#include "VideoViewWindow.h"

VideoViewWindow::VideoViewWindow(QString fileName, QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);

	mediaPlayer = new QMediaPlayer;
	videoWidget = new QVideoWidget;

	mediaPlayer->setVideoOutput(videoWidget);
	mediaPlayer->setMedia(QUrl::fromLocalFile("./Contents/Multimedia/" + fileName));

	QVBoxLayout * layout = new QVBoxLayout;
	layout->addWidget(videoWidget);
	QPushButton * playButton = new QPushButton("Play");
	layout->addWidget(playButton);

	ui.centralwidget->setLayout(layout);

	QObject::connect(playButton, &QPushButton::clicked, [=]() {
		mediaPlayer->play();
		});
	videoWidget->show();
}

VideoViewWindow::~VideoViewWindow() {
	delete videoWidget;
	delete mediaPlayer;
	delete this;
}