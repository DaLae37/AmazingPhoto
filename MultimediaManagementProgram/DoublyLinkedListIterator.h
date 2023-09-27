#pragma once
#include "DoublyLinkedList.h"

template <typename T>
class DoublyLinkedList; //���ø� ����� ���� ������

template <class T>
struct NodeType; //���ø� ����� ���� ������

template <class T>
class DoublyLinkedListIterator
{
private :
	DoublyLinkedList<T>& list; //���ͷ������� ����Ʈ
	NodeType<T>* currentPointer; //����Ʈ���� ���� ����Ű�� �ִ� ��ġ

public :
	DoublyLinkedListIterator(DoublyLinkedList<T> list) : list(list), currentPointer(list.getHead()) {} //�⺻ ������
	~DoublyLinkedListIterator(); // �⺻ �Ҹ���

	/**
	*	@brief	���� ����Ű�� �ִ� ��ġ�� null���� Ȯ��
	*	@pre	�ʱ�ȭ �� ����Ʈ�� �ʿ���
	*	@post	None
	*	@return	���� ����Ű�� ��ġ�� null�ϰ�� false, null�� �ƴҰ�� true�� ��ȯ
	*/
	bool NotNull();

	/**
	*	@brief	���� ����Ű�� �ִ� ��ġ�� ���� ���� null���� Ȯ��
	*	@pre	�ʱ�ȭ �� ����Ʈ�� �ʿ���
	*	@post	None
	*	@return	���� ����Ű�� �ִ� ��ġ�� ���� ���� null�ϰ�� false, null�� �ƴҰ�� true�� ��ȯ
	*/
	bool NextNotNull();

	/**
	*	@brief	����Ʈ�� ù ��° �������� ��ȯ
	*	@pre	�ʱ�ȭ �� ����Ʈ�� �ʿ���
	*	@post	None
	*	@return	����Ʈ�� ù ��° �������� ��ȯ
	*/
	T First();

	/**
	*	@brief	���� ����Ű�� �ִ� ���� ��ȯ��
	*	@pre	�ʱ�ȭ �� ����Ʈ�� �ʿ���
	*	@post	���� ����Ű�� �ִ� ��ġ�� ���� ��ġ�� �̵���
	*	@return	���� ����Ű�� �ִ� ���� ��ȯ��
	*/
	T Next();

	/**
	*	@return	���� ����Ű�� ��带 ��ȯ
	*/
	NodeType<T>* getCurrentPointer();
};

template<class T>
DoublyLinkedListIterator<T>::~DoublyLinkedListIterator() {

}

template <class T>
bool DoublyLinkedListIterator<T>::NotNull() {
	if (currentPointer == nullptr) {
		return false;
	}
	else {
		return true;
	}
}

template <class T>
bool DoublyLinkedListIterator<T>::NextNotNull() {
	if (currentPointer->next == nullptr) {
		return false;
	}
	else {
		return true;
	}
}

template <class T>
T DoublyLinkedListIterator<T>::First() {
	if (!list.IsEmpty()) { //����Ʈ�� ��� ���� ������
		currentPointer = list.getHead(); //����Ʈ�� ��带 ������
		return currentPointer->record;
	}
}


template <class T>
T DoublyLinkedListIterator<T>::Next() {
	T tmp = currentPointer->record;
	if (NotNull()) { //���� ��尡 null�� �ƴϸ�
		currentPointer = currentPointer->next; // ���� ���� �ѱ�
	}
	return tmp;
}

template <class T>
NodeType<T>* DoublyLinkedListIterator<T>::getCurrentPointer() { //���� ����Ű�� �ִ� ��带 ��ȯ
	if (currentPointer != nullptr){
		return currentPointer;
	}
}