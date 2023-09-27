#include "Person.h"

Person::Person() {
	personName = ""; //�⺻ ������ �ʱ�ȭ
}

Person::~Person() {

}

void Person::operator=(const Person& item) { //������ ������
	personName = item.personName;
	personIdList = item.personIdList;
}

bool Person::operator==(const Person& item) { //������ ������
	return (personName == item.personName);
}

bool Person::operator>(const Person& item) { //������ ������
	return (personName > item.personName);
}

bool Person::operator>=(const Person& item) { //������ ������
	return (personName >= item.personName);
}

bool Person::operator<(const Person& item) { //������ ������
	return (personName < item.personName);
}

bool Person::operator<=(const Person& item) { //������ ������
	return (personName <= item.personName);
}