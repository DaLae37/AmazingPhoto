#include "Place.h"

Place::Place() {
	placeName = ""; //�⺻ ������ �ʱ�ȭ
}

Place::~Place() {

}

void Place::operator=(const Place& item) { //������ ������
	placeName = item.placeName;
	placeIdList = item.placeIdList;
}

bool Place::operator==(const Place& item) { //������ ������
	return (placeName == item.placeName);
}

bool Place::operator>(const Place& item) { //������ ������
	return (placeName > item.placeName);
}

bool Place::operator>=(const Place& item) { //������ ������
	return (placeName >= item.placeName);
}

bool Place::operator<(const Place& item) { //������ ������
	return (placeName < item.placeName);
}

bool Place::operator<=(const Place& item) { //������ ������
	return (placeName <= item.placeName);
}