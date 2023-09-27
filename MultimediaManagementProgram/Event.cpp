#include "Event.h"

Event::Event() {
	eventName = ""; //기본 값으로 초기화
}

Event::~Event() {

}

void Event::operator=(const Event& item) { //연산자 재정의
	eventName = item.eventName;
	eventIdList = item.eventIdList;
}

bool Event::operator==(const Event& item) { //연산자 재정의
	return (eventName == item.eventName);
}

bool Event::operator>(const Event& item) { //연산자 재정의
	return (eventName > item.eventName);
}

bool Event::operator>=(const Event& item) { //연산자 재정의
	return (eventName >= item.eventName);
}

bool Event::operator<(const Event& item) { //연산자 재정의
	return (eventName < item.eventName);
}

bool Event::operator<=(const Event& item) { //연산자 재정의
	return (eventName <= item.eventName);
}