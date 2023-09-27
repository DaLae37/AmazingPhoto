#include "MultimediaManagementProgram.h"
#include <QtWidgets/QApplication>
#include <Windows.h>

int main(int argc, char *argv[])
{
    if ((_waccess(L"./Contents", 0)) == -1) { //���α׷��� ���۵� �� ./Contents ������ ������
        CreateDirectory(L"./Contents", nullptr); //���� ����
    }
    if ((_waccess(L"./Contents/Multimedia", 0)) == -1) { //���α׷��� ���۵� �� ./Contents/Multimedia ������ ������
        CreateDirectory(L"./Contents/Multimedia", nullptr); //���� ����
    }
    if ((_waccess(L"./Contents/Database", 0)) == -1) { //���α׷��� ���۵� �� ./Contents/Database ������ ������
        CreateDirectory(L"./Contents/Database", nullptr); //���� ����
    }

    QApplication a(argc, argv);
    MultimediaManagementProgram w;
    w.show();
    return a.exec();
}