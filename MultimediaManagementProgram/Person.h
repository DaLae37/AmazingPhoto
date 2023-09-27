#pragma once
#include <iostream>
#include "DoublyLinkedList.h"

class Person
{
private:
	std::string personName; //����� �̸�
	DoublyLinkedList<std::string> personIdList; //�ش� ����� ���Ե� �������� id ����Ʈ

public:
	Person(); //������
	~Person(); //�Ҹ���

	/*
	*	@brief	personIdList�� id�� �߰��ϴ� �Լ�
	*   @param  string id �߰��� id��
	*	@post   personIdList�� id�� �߰���
	*/
	void AddId(std::string id) {
		personIdList.Add(id);
	}

	//@Getter

	/*
	*	@brief	�ش� ����� �ִ� �������� ��� id�� ��ȯ
	*	@return personIdList�� pass by reference�� �Ѱ���
	*/
	DoublyLinkedList<std::string> GetIdList() {
		return personIdList;
	}

	//@Setter

	/*
	*	@brief	personName�� �����ϴ� �Լ�
	*   @param  personName ������ ��� �̸�
	*	@post   ������� personName�� �Ķ���� ������ �ٲ�
	*/
	void setPersonName(std::string personName) {
		this->personName = personName;
	}

	//������ ������
	void operator=(const Person& item);
	bool operator==(const Person& item);
	bool operator>(const Person& item);
	bool operator>=(const Person& item);
	bool operator<(const Person& item);
	bool operator<=(const Person& item);
};