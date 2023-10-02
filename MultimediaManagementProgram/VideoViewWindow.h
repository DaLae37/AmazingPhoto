#pragma once
#include "ui_VideoViewWindow.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget.h>
class VideoViewWindow  : public QMainWindow
{
	Q_OBJECT

public:
	VideoViewWindow(QString fileName, QWidget *parent);
	~VideoViewWindow();

	QMediaPlayer* mediaPlayer;
	QVideoWidget* videoWidget;

private:
	Ui::VideoViewWindow ui;
};
