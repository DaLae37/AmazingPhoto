#include <QWidget>
#include <QDialog>
#include "ui_VideoViewDialog.h"

class VideoViewDialog  : public QDialog
{
	Q_OBJECT

public:
	VideoViewDialog(QString fileName, QWidget *parent);

private :
	Ui::VideoViewDialog ui;
};