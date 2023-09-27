#include "Person.h"

Person::Person() {
	personName = ""; //기본 값으로 초기화
}

Person::~Person() {

}

void Person::operator=(const Person& item) { //연산자 재정의
	personName = item.personName;
	personIdList = item.personIdList;
}

bool Person::operator==(const Person& item) { //연산자 재정의
	return (personName == item.personName);
}

bool Person::operator>(const Person& item) { //연산자 재정의
	return (personName > item.personName);
}

bool Person::operator>=(const Person& item) { //연산자 재정의
	return (personName >= item.personName);
}

bool Person::operator<(const Person& item) { //연산자 재정의
	return (personName < item.personName);
}

bool Person::operator<=(const Person& item) { //연산자 재정의
	return (personName <= item.personName);
}