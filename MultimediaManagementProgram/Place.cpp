#include "Place.h"

Place::Place() {
	placeName = ""; //기본 값으로 초기화
}

Place::~Place() {

}

void Place::operator=(const Place& item) { //연산자 재정의
	placeName = item.placeName;
	placeIdList = item.placeIdList;
}

bool Place::operator==(const Place& item) { //연산자 재정의
	return (placeName == item.placeName);
}

bool Place::operator>(const Place& item) { //연산자 재정의
	return (placeName > item.placeName);
}

bool Place::operator>=(const Place& item) { //연산자 재정의
	return (placeName >= item.placeName);
}

bool Place::operator<(const Place& item) { //연산자 재정의
	return (placeName < item.placeName);
}

bool Place::operator<=(const Place& item) { //연산자 재정의
	return (placeName <= item.placeName);
}