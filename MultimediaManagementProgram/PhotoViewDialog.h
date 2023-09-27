#include <QWidget>
#include <QDialog>
#include "ui_PhotoViewDialog.h"

class PhotoViewDialog : public QDialog
{
	Q_OBJECT

public:
	PhotoViewDialog(QString fileName, QWidget* parent = Q_NULLPTR); //»ý¼ºÀÚ

private:
	Ui::PhotoViewDialog ui;
};