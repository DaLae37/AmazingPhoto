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
	fout << fileName << ",";
	fout << fileType << ",";
	fout << createDate << ",";
	fout << innerEvent << ",";
	fout << innerPerson << ",";
	fout << innerPlace << ",";
	fout << numberOfHits << ",";
	fout << "\n";
}

void MultimediaContent::ReadDataFromFile(std::ifstream &fin) { //���Ͽ��� �о����
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