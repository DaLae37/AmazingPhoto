#include "MultimediaManagementProgram.h"
#include <QtWidgets/QApplication>
#include <Windows.h>

int main(int argc, char *argv[])
{
    if ((_waccess(L"./Contents", 0)) == -1) { //프로그램이 시작될 때 ./Contents 폴더가 없으면
        CreateDirectory(L"./Contents", nullptr); //폴더 생성
    }
    if ((_waccess(L"./Contents/Multimedia", 0)) == -1) { //프로그램이 시작될 때 ./Contents/Multimedia 폴더가 없으면
        CreateDirectory(L"./Contents/Multimedia", nullptr); //폴더 생성
    }
    if ((_waccess(L"./Contents/Database", 0)) == -1) { //프로그램이 시작될 때 ./Contents/Database 폴더가 없으면
        CreateDirectory(L"./Contents/Database", nullptr); //폴더 생성
    }

    QApplication a(argc, argv);
    MultimediaManagementProgram w;
    w.show();
    return a.exec();
}