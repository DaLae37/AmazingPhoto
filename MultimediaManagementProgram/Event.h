#pragma once
#include <iostream>
#include "MultimediaContent.h"
#include "DoublyLinkedList.h"

class Event
{
private :
	std::string eventName; //�̺�Ʈ�� �̸�
	DoublyLinkedList<std::string> eventIdList; //�ش� �̺�Ʈ�� �̸��� ���� id���� ����Ʈ

public :
	Event(); //������
	~Event(); //�Ҹ���

	/*
	*	@brief	eventIdList�� id�� �߰��ϴ� �Լ�
	*   @param  string id �߰��� id��
	*	@post   eventIdList�� id�� �߰���
	*/
	void AddId(std::string id) {
		eventIdList.Add(id);
	}

	//@Getter

	/*
	*	@brief	�ش� ��ҿ� �ִ� �������� ��� id�� ��ȯ
	*	@return eventIdList�� pass by reference�� �Ѱ���
	*/
	DoublyLinkedList<std::string> GetIdList() {
		return eventIdList;
	}

	//@Setter

	/*
	*	@brief	eventName�� �����ϴ� �Լ�
	*   @param  eventName ������ ��� �̸�
	*	@post   ������� eventName�� �Ķ���� ������ �ٲ�
	*/
	void setEventName(std::string eventName) {
		this->eventName = eventName;
	}

	//������ ������
	void operator=(const Event& item);
	bool operator==(const Event& item);
	bool operator>(const Event& item);
	bool operator>=(const Event& item);
	bool operator<(const Event& item);
	bool operator<=(const Event& item);
};