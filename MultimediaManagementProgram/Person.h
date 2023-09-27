#pragma once
#include <iostream>
#include "DoublyLinkedList.h"

class Person
{
private:
	std::string personName; //사람의 이름
	DoublyLinkedList<std::string> personIdList; //해당 사람이 포함된 콘텐츠의 id 리스트

public:
	Person(); //생성자
	~Person(); //소멸자

	/*
	*	@brief	personIdList에 id를 추가하는 함수
	*   @param  string id 추가할 id값
	*	@post   personIdList에 id가 추가됨
	*/
	void AddId(std::string id) {
		personIdList.Add(id);
	}

	//@Getter

	/*
	*	@brief	해당 사람이 있는 콘텐츠의 모든 id를 반환
	*	@return personIdList를 pass by reference로 넘겨줌
	*/
	DoublyLinkedList<std::string> GetIdList() {
		return personIdList;
	}

	//@Setter

	/*
	*	@brief	personName을 지정하는 함수
	*   @param  personName 설정할 사람 이름
	*	@post   멤버변수 personName이 파라미터 값으로 바뀜
	*/
	void setPersonName(std::string personName) {
		this->personName = personName;
	}

	//연산자 재정의
	void operator=(const Person& item);
	bool operator==(const Person& item);
	bool operator>(const Person& item);
	bool operator>=(const Person& item);
	bool operator<(const Person& item);
	bool operator<=(const Person& item);
};