#pragma once
#include <iostream>

template <typename T>
struct NodeType { //리스트의 노드
	T record;
	NodeType* prev = nullptr;
	NodeType* next = nullptr;
};

template <class T>
class DoublyLinkedList
{
private :
	NodeType<T>* head; //이중연결리스트의 맨 처음 노드
	int length; //현재 리스트의 길이
	
public :
	DoublyLinkedList(); //기본 생성자
	~DoublyLinkedList(); //기본 소멸자

	/**
	*	@brief	리스트를 초기화하는 함수
	*	@pre	None
	*	@post	모든 노드의 할당이 해제되고 length가 0으로 초기화 됨
	*/
	void MakeEmpty();

	/**
	*	@brief	리스트에 새로운 노드를 추가할 수 있는지 확인
	*	@pre	초기화 된 리스트가 필요함
	*	@post	None
	*	@return	더 할당할 메모리가 있으면 false, 더 이상 할당할 수 없으면 true를 반환
	*/
	bool IsFull();

	/**
	*	@brief	리스트가 비어있는지 확인
	*	@pre	초기화 된 리스트가 필요함
	*	@post	None
	*	@return	리스트의 길이가 0이 아니면 false, 0이면 true를 반환
	*/
	bool IsEmpty();

	/**
	*	@brief	새로운 아이템을 리스트에 추가
	*	@pre	초기화 된 리스트가 필요함
	*	@post	리스트에 새로운 아이템이 추가 됨
	*   @param  T item 추가할 아이템
	*	@return	리스트에 추가를 성공할 경우 1을 반환, 실패할 경우 0을 반환
	*/
	int Add(T item);

	/**
	*	@return 현재 리스트의 길이를 반환
	*/
	int getLength();
	
	/**
	*	@return 현재 리스트의 첫 번째 노드(Head)를 반환
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
	//모든 노드의 할당을 해제
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
	//메모리 허용 여부
	try {
		NodeType<T>* tmp = new NodeType<T>;
		delete tmp;
		return false;
	}
	catch (std::bad_alloc& error) {
		std::cout << "\t메모리가 가득 찼습니다." << std::endl;
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

		if (head == nullptr) { //리스트가 비어있을 때
			head = node;
		}
		else { //리스트가 비어 있지 않을 때
			NodeType<T>* tmp = head;
			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			tmp->next = node;
		}

		length++;
		std::cout << "\t추가에 성공하였습니다." << std::endl;
		return 1;
	}
	else {
		std::cout << "\t추가에 실패하였습니다." << std::endl;
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