#pragma once
#include <iostream>

template <typename T>
struct NodeType { //����Ʈ�� ���
	T record;
	NodeType* prev = nullptr;
	NodeType* next = nullptr;
};

template <class T>
class DoublyLinkedList
{
private :
	NodeType<T>* head; //���߿��Ḯ��Ʈ�� �� ó�� ���
	int length; //���� ����Ʈ�� ����
	
public :
	DoublyLinkedList(); //�⺻ ������
	~DoublyLinkedList(); //�⺻ �Ҹ���

	/**
	*	@brief	����Ʈ�� �ʱ�ȭ�ϴ� �Լ�
	*	@pre	None
	*	@post	��� ����� �Ҵ��� �����ǰ� length�� 0���� �ʱ�ȭ ��
	*/
	void MakeEmpty();

	/**
	*	@brief	����Ʈ�� ���ο� ��带 �߰��� �� �ִ��� Ȯ��
	*	@pre	�ʱ�ȭ �� ����Ʈ�� �ʿ���
	*	@post	None
	*	@return	�� �Ҵ��� �޸𸮰� ������ false, �� �̻� �Ҵ��� �� ������ true�� ��ȯ
	*/
	bool IsFull();

	/**
	*	@brief	����Ʈ�� ����ִ��� Ȯ��
	*	@pre	�ʱ�ȭ �� ����Ʈ�� �ʿ���
	*	@post	None
	*	@return	����Ʈ�� ���̰� 0�� �ƴϸ� false, 0�̸� true�� ��ȯ
	*/
	bool IsEmpty();

	/**
	*	@brief	���ο� �������� ����Ʈ�� �߰�
	*	@pre	�ʱ�ȭ �� ����Ʈ�� �ʿ���
	*	@post	����Ʈ�� ���ο� �������� �߰� ��
	*   @param  T item �߰��� ������
	*	@return	����Ʈ�� �߰��� ������ ��� 1�� ��ȯ, ������ ��� 0�� ��ȯ
	*/
	int Add(T item);

	/**
	*	@return ���� ����Ʈ�� ���̸� ��ȯ
	*/
	int getLength();
	
	/**
	*	@return ���� ����Ʈ�� ù ��° ���(Head)�� ��ȯ
	*/
	NodeType<T>* getHead();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
	length = 0;
	head = nullptr;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	//��� ����� �Ҵ��� ����
	MakeEmpty();
}

template <class T>
void DoublyLinkedList<T>::MakeEmpty() {
	if (length > 0) {
		NodeType<T>* cursor = head;
		NodeType<T>* tmp = cursor;

		while (cursor != nullptr) {
			tmp = cursor;
			cursor = cursor->next;
			delete tmp;
		}

		length = 0;
	}
}

template <class T>
bool DoublyLinkedList<T>::IsFull() {
	//�޸� ��� ����
	try {
		NodeType<T>* tmp = new NodeType<T>;
		delete tmp;
		return false;
	}
	catch (std::bad_alloc& error) {
		std::cout << "\t�޸𸮰� ���� á���ϴ�." << std::endl;
		return true;
	}
}

template <class T>
bool DoublyLinkedList<T>::IsEmpty() {
	if (length == 0) {
		return true;
	}
	else {
		return false;
	}
}

template <class T>
int DoublyLinkedList<T>::Add(T item) {
	if (!IsFull()) {
		NodeType<T>* node = new NodeType<T>;

		node->record = item;

		if (head == nullptr) { //����Ʈ�� ������� ��
			head = node;
		}
		else { //����Ʈ�� ��� ���� ���� ��
			NodeType<T>* tmp = head;
			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			tmp->next = node;
		}

		length++;
		std::cout << "\t�߰��� �����Ͽ����ϴ�." << std::endl;
		return 1;
	}
	else {
		std::cout << "\t�߰��� �����Ͽ����ϴ�." << std::endl;
		return 0;
	}
}

template <class T>
int DoublyLinkedList<T>::getLength() {
	return length;
}

template <class T>
NodeType<T>* DoublyLinkedList<T>::getHead() {
	return head;
}