#pragma once
#include <iostream>
#include <fstream>
#include <string>

#define NUM_OF_DATA 7

class MultimediaContent
{
private :
	std::string fileName; //�������� �����̸�
	std::string fileType; //�������� Ȯ����
	std::string createDate; //�������� ������ ��¥
	std::string innerEvent; //�������� �̺�Ʈ
	std::string innerPerson; //�������� ���Ե� ���
	std::string innerPlace; //�������� ���Ե� ���
	int numberOfHits; //��ȸ ��

public :
	MultimediaContent(); //������
	~MultimediaContent(); //�Ҹ���

	/*
	*	@brief	���� �������� ������ ����
	*	@post	ofstream�� ���� ���� ������ ����
	*/
	void WriteDataToFile(std::ofstream &fout);

	/*
	*	@brief	���� ���Ͽ��� ������ ������ �о��
	*	@post	ifstream�� ���� ���� ������ �о��
	*/
	void ReadDataFromFile(std::ifstream &fin);

	//@Getter

	//�������� ���� �̸��� ��ȯ
	std::string getFileName() {
		return fileName;
	}

	//�������� ���� ����(Ȯ����)�� ��ȯ
	std::string getFileType() {
		return fileType;
	}

	//�������� ������ ��¥(����Ʈ�� �� �ð�)�� ��ȯ
	std::string getCreateDate() {
		return createDate;
	}

	//�������� �̺�Ʈ�� ��ȯ
	std::string getInnerEvent() {
		return innerEvent;
	}

	//�������� ����� ��ȯ
	std::string getInnerPerson() {
		return innerPerson;
	}

	//�������� ��Ҹ� ��ȯ
	std::string getInnerPlace() {
		return innerPlace;
	}	

	//�������� ��ȸ���� ��ȯ
	int getNumberOfHits() {
		return numberOfHits;
	}

	//@Setter

	/*
	*	@brief	���� �������� ��� ������ �����ϴ� �Լ�
	*	@post	�Ķ���ͷ� ������ ������ ���� ������ ����
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

	//������ ������
	void operator=(const MultimediaContent& item);
	bool operator==(const MultimediaContent& item);
	bool operator>(const MultimediaContent& item);
	bool operator>=(const MultimediaContent& item);
	bool operator<(const MultimediaContent& item);
	bool operator<=(const MultimediaContent& item);
};