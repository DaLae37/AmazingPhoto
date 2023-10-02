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
	fout << fileName << ",";
	fout << fileType << ",";
	fout << createDate << ",";
	fout << innerEvent << ",";
	fout << innerPerson << ",";
	fout << innerPlace << ",";
	fout << numberOfHits << ",";
	fout << "\n";
}

void MultimediaContent::ReadDataFromFile(std::ifstream &fin) { //파일에서 읽어오기
	std::string line;
	std::string data[NUM_OF_DATA];
	fin >> line;
	
	if (line == "") {
		return;
	}

	int cursor = 0;
	for (int i = 0; i < NUM_OF_DATA; i++) {
		int index = line.find(',', cursor);
		data[i] = line.substr(cursor, index - cursor);
		cursor = index + 1;
	}

	fileName = data[0];
	fileType = data[1];
	createDate = data[2];
	innerEvent = data[3];
	innerPerson = data[4];
	innerPlace = data[5];
	numberOfHits = std::stoi(data[6]);
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