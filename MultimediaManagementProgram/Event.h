#pragma once
#include <iostream>
#include "MultimediaContent.h"
#include "DoublyLinkedList.h"

class Event
{
private :
	std::string eventName; //이벤트의 이름
	DoublyLinkedList<std::string> eventIdList; //해당 이벤트의 이름을 가진 id들의 리스트

public :
	Event(); //생성자
	~Event(); //소멸자

	/*
	*	@brief	eventIdList에 id를 추가하는 함수
	*   @param  string id 추가할 id값
	*	@post   eventIdList에 id가 추가됨
	*/
	void AddId(std::string id) {
		eventIdList.Add(id);
	}

	//@Getter

	/*
	*	@brief	해당 장소에 있는 콘텐츠의 모든 id를 반환
	*	@return eventIdList를 pass by reference로 넘겨줌
	*/
	DoublyLinkedList<std::string> GetIdList() {
		return eventIdList;
	}

	//@Setter

	/*
	*	@brief	eventName을 지정하는 함수
	*   @param  eventName 설정할 사람 이름
	*	@post   멤버변수 eventName이 파라미터 값으로 바뀜
	*/
	void setEventName(std::string eventName) {
		this->eventName = eventName;
	}

	//연산자 재정의
	void operator=(const Event& item);
	bool operator==(const Event& item);
	bool operator>(const Event& item);
	bool operator>=(const Event& item);
	bool operator<(const Event& item);
	bool operator<=(const Event& item);
};