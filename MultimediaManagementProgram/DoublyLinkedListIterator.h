#pragma once
#include "DoublyLinkedList.h"

template <typename T>
class DoublyLinkedList; //템플릿 사용을 위한 재정의

template <class T>
struct NodeType; //템플릿 사용을 위한 재정의

template <class T>
class DoublyLinkedListIterator
{
private :
	DoublyLinkedList<T>& list; //이터레이터의 리스트
	NodeType<T>* currentPointer; //리스트에서 현재 가리키고 있는 위치

public :
	DoublyLinkedListIterator(DoublyLinkedList<T> list) : list(list), currentPointer(list.getHead()) {} //기본 생성자
	~DoublyLinkedListIterator(); // 기본 소멸자

	/**
	*	@brief	현재 가리키고 있는 위치가 null인지 확인
	*	@pre	초기화 된 리스트가 필요함
	*	@post	None
	*	@return	현재 가리키는 위치가 null일경우 false, null이 아닐경우 true를 반환
	*/
	bool NotNull();

	/**
	*	@brief	현재 가리키고 있는 위치의 다음 값이 null인지 확인
	*	@pre	초기화 된 리스트가 필요함
	*	@post	None
	*	@return	현재 가리키고 있는 위치의 다음 값이 null일경우 false, null이 아닐경우 true를 반환
	*/
	bool NextNotNull();

	/**
	*	@brief	리스트의 첫 번째 아이템을 반환
	*	@pre	초기화 된 리스트가 필요함
	*	@post	None
	*	@return	리스트의 첫 번째 아이템을 반환
	*/
	T First();

	/**
	*	@brief	현재 가리키고 있는 값을 반환함
	*	@pre	초기화 된 리스트가 필요함
	*	@post	현재 가리키고 있는 위치의 다음 위치로 이동함
	*	@return	현재 가리키고 있는 값을 반환함
	*/
	T Next();

	/**
	*	@return	현재 가리키는 노드를 반환
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
	if (!list.IsEmpty()) { //리스트가 비어 있지 않으면
		currentPointer = list.getHead(); //리스트의 헤드를 가져옴
		return currentPointer->record;
	}
}


template <class T>
T DoublyLinkedListIterator<T>::Next() {
	T tmp = currentPointer->record;
	if (NotNull()) { //현재 노드가 null이 아니면
		currentPointer = currentPointer->next; // 다음 노드로 넘김
	}
	return tmp;
}

template <class T>
NodeType<T>* DoublyLinkedListIterator<T>::getCurrentPointer() { //현재 가리키고 있는 노드를 반환
	if (currentPointer != nullptr){
		return currentPointer;
	}
}