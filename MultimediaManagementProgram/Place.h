#pragma once
#include <iostream>
#include "MultimediaContent.h"
#include "DoublyLinkedList.h"

class Place
{
private:
	std::string placeName; //����� �̸�
	DoublyLinkedList<std::string> placeIdList; //�ش� ��Ұ� ���Ե� �������� id ����Ʈ

public:
	Place(); //������
	~Place(); //�Ҹ���

	/*
	*	@brief	placeIdList�� id�� �߰��ϴ� �Լ�
	*   @param  string id �߰��� id��
	*	@post   placeIdList�� id�� �߰���
	*/
	void AddId(std::string id) {
		placeIdList.Add(id);
	}

	//@Getter

	/*
	*	@brief	�ش� ��ҿ� �ִ� �������� ��� id�� ��ȯ
	*	@return placeIdList�� pass by reference�� �Ѱ���
	*/
	DoublyLinkedList<std::string> GetIdList() {
		return placeIdList;
	}

	//@Setter

	/*
	*	@brief	placeName�� �����ϴ� �Լ�
	*   @param  placeName ������ ��� �̸�
	*	@post   ������� placeName�� �Ķ���� ������ �ٲ�
	*/
	void setPlaceName(std::string placeName) {
		this->placeName = placeName;
	}

	//������ ������
	void operator=(const Place& item);
	bool operator==(const Place& item);
	bool operator>(const Place& item);
	bool operator>=(const Place& item);
	bool operator<(const Place& item);
	bool operator<=(const Place& item);
};