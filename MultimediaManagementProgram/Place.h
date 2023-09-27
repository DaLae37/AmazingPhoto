#pragma once
#include <iostream>
#include "MultimediaContent.h"
#include "DoublyLinkedList.h"

class Place
{
private:
	std::string placeName; //장소의 이름
	DoublyLinkedList<std::string> placeIdList; //해당 장소가 포함된 콘텐츠의 id 리스트

public:
	Place(); //생성자
	~Place(); //소멸자

	/*
	*	@brief	placeIdList에 id를 추가하는 함수
	*   @param  string id 추가할 id값
	*	@post   placeIdList에 id가 추가됨
	*/
	void AddId(std::string id) {
		placeIdList.Add(id);
	}

	//@Getter

	/*
	*	@brief	해당 장소에 있는 콘텐츠의 모든 id를 반환
	*	@return placeIdList를 pass by reference로 넘겨줌
	*/
	DoublyLinkedList<std::string> GetIdList() {
		return placeIdList;
	}

	//@Setter

	/*
	*	@brief	placeName을 지정하는 함수
	*   @param  placeName 설정할 사람 이름
	*	@post   멤버변수 placeName이 파라미터 값으로 바뀜
	*/
	void setPlaceName(std::string placeName) {
		this->placeName = placeName;
	}

	//연산자 재정의
	void operator=(const Place& item);
	bool operator==(const Place& item);
	bool operator>(const Place& item);
	bool operator>=(const Place& item);
	bool operator<(const Place& item);
	bool operator<=(const Place& item);
};