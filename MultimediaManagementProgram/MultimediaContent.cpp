#include "MultimediaContent.h"

MultimediaContent::MultimediaContent() {
	fileName = ""; //기본 값으로 초기화
	createDate = "";
	innerEvent = "";
	innerPerson = "";
	innerPlace = "";
	fileType = "";
	numberOfHits = 0;
}

MultimediaContent::~MultimediaContent() {

}

void MultimediaContent::WriteDataToFile(std::ofstream &fout) { //파일에 기록
	fout << fileName << " ";
	fout << fileType << " ";
	fout << createDate << " ";
	fout << innerEvent << " ";
	fout << innerPerson << " ";
	fout << innerPlace << " ";
	fout << numberOfHits << " ";
}

void MultimediaContent::ReadDataFromFile(std::ifstream &fin) { //파일에서 읽어오기
	fin >> fileName;
	fin >> fileType;
	fin >> createDate;
	fin >> innerEvent;
	fin >> innerPerson;
	fin >> innerPlace;
	fin >> numberOfHits;
}

void MultimediaContent::operator=(const MultimediaContent& item) { //연산자 재정의
	SetRecord(item.fileName, item.fileType, item.createDate, item.innerEvent, item.innerPerson, item.innerPlace, item.numberOfHits);
}

bool MultimediaContent::operator==(const MultimediaContent& item) { //연산자 재정의
	return (fileName == item.fileName);
}

bool MultimediaContent::operator>(const MultimediaContent& item) { //연산자 재정의
	return (fileName > item.fileName);
}

bool MultimediaContent::operator>=(const MultimediaContent& item) { //연산자 재정의
	return (fileName >= item.fileName);
}

bool MultimediaContent::operator<(const MultimediaContent& item) { //연산자 재정의
	return (fileName < item.fileName);
}

bool MultimediaContent::operator<=(const MultimediaContent& item) { //연산자 재정의
	return (fileName <= item.fileName);
}