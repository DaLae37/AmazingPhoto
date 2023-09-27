#include "MultimediaContent.h"

MultimediaContent::MultimediaContent() {
	fileName = ""; //�⺻ ������ �ʱ�ȭ
	createDate = "";
	innerEvent = "";
	innerPerson = "";
	innerPlace = "";
	fileType = "";
	numberOfHits = 0;
}

MultimediaContent::~MultimediaContent() {

}

void MultimediaContent::WriteDataToFile(std::ofstream &fout) { //���Ͽ� ���
	fout << fileName << " ";
	fout << fileType << " ";
	fout << createDate << " ";
	fout << innerEvent << " ";
	fout << innerPerson << " ";
	fout << innerPlace << " ";
	fout << numberOfHits << " ";
}

void MultimediaContent::ReadDataFromFile(std::ifstream &fin) { //���Ͽ��� �о����
	fin >> fileName;
	fin >> fileType;
	fin >> createDate;
	fin >> innerEvent;
	fin >> innerPerson;
	fin >> innerPlace;
	fin >> numberOfHits;
}

void MultimediaContent::operator=(const MultimediaContent& item) { //������ ������
	SetRecord(item.fileName, item.fileType, item.createDate, item.innerEvent, item.innerPerson, item.innerPlace, item.numberOfHits);
}

bool MultimediaContent::operator==(const MultimediaContent& item) { //������ ������
	return (fileName == item.fileName);
}

bool MultimediaContent::operator>(const MultimediaContent& item) { //������ ������
	return (fileName > item.fileName);
}

bool MultimediaContent::operator>=(const MultimediaContent& item) { //������ ������
	return (fileName >= item.fileName);
}

bool MultimediaContent::operator<(const MultimediaContent& item) { //������ ������
	return (fileName < item.fileName);
}

bool MultimediaContent::operator<=(const MultimediaContent& item) { //������ ������
	return (fileName <= item.fileName);
}