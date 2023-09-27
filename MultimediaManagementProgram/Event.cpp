#include "Event.h"

Event::Event() {
	eventName = ""; //�⺻ ������ �ʱ�ȭ
}

Event::~Event() {

}

void Event::operator=(const Event& item) { //������ ������
	eventName = item.eventName;
	eventIdList = item.eventIdList;
}

bool Event::operator==(const Event& item) { //������ ������
	return (eventName == item.eventName);
}

bool Event::operator>(const Event& item) { //������ ������
	return (eventName > item.eventName);
}

bool Event::operator>=(const Event& item) { //������ ������
	return (eventName >= item.eventName);
}

bool Event::operator<(const Event& item) { //������ ������
	return (eventName < item.eventName);
}

bool Event::operator<=(const Event& item) { //������ ������
	return (eventName <= item.eventName);
}