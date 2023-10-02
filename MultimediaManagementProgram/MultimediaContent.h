#pragma once
#include <iostream>
#include <fstream>
#include <string>

#define NUM_OF_DATA 7

class MultimediaContent
{
private :
	std::string fileName; //콘텐츠의 파일이름
	std::string fileType; //콘텐츠의 확장자
	std::string createDate; //콘텐츠가 생성된 날짜
	std::string innerEvent; //콘텐츠의 이벤트
	std::string innerPerson; //콘텐츠에 포함된 사람
	std::string innerPlace; //콘텐츠에 포함된 장소
	int numberOfHits; //조회 수

public :
	MultimediaContent(); //생성자
	~MultimediaContent(); //소멸자

	/*
	*	@brief	현재 콘텐츠의 정보를 저장
	*	@post	ofstream을 통해 현재 정보를 저장
	*/
	void WriteDataToFile(std::ofstream &fout);

	/*
	*	@brief	현재 파일에서 콘텐츠 정보를 읽어옴
	*	@post	ifstream을 통해 현재 정보를 읽어옴
	*/
	void ReadDataFromFile(std::ifstream &fin);

	//@Getter

	//콘텐츠의 파일 이름을 반환
	std::string getFileName() {
		return fileName;
	}

	//콘텐츠의 파일 종류(확장자)를 반환
	std::string getFileType() {
		return fileType;
	}

	//콘텐츠가 생성된 날짜(리스트에 들어간 시간)를 반환
	std::string getCreateDate() {
		return createDate;
	}

	//콘텐츠의 이벤트를 반환
	std::string getInnerEvent() {
		return innerEvent;
	}

	//콘텐츠의 사람을 반환
	std::string getInnerPerson() {
		return innerPerson;
	}

	//콘텐츠의 장소를 반환
	std::string getInnerPlace() {
		return innerPlace;
	}	

	//콘텐츠의 조회수를 반환
	int getNumberOfHits() {
		return numberOfHits;
	}

	//@Setter

	/*
	*	@brief	현재 콘텐츠의 모든 정보를 설정하는 함수
	*	@post	파라미터로 가져온 값들을 현재 값으로 변경
	*/
	void SetRecord(std::string fileName, std::string fileType, std::string createDate, std::string innerEvent, std::string innerPerson, std::string innerPlace, int numberOfHits) {
		this->fileName = fileName;
		this->createDate = createDate;
		this->innerEvent = innerEvent;
		this->innerPerson = innerPerson;
		this->innerPlace = innerPlace;
		this->fileType = fileType;
		this->numberOfHits = numberOfHits;
	}

	//연산자 재정의
	void operator=(const MultimediaContent& item);
	bool operator==(const MultimediaContent& item);
	bool operator>(const MultimediaContent& item);
	bool operator>=(const MultimediaContent& item);
	bool operator<(const MultimediaContent& item);
	bool operator<=(const MultimediaContent& item);
};