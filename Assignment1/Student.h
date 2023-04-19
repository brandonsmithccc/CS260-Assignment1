#pragma once

#include<cstring>
#include<iostream>

class Student{
public:
	Student(const std::string name = "anonymous", char letterGrade = 'W') {
		this->name = name;
		this->letterGrade = letterGrade;
	}

	friend bool operator==(const Student& stu1, const Student& stu2);
	friend std::ostream& operator << (std::ostream& stream, const Student& student);

private:
	std::string name;
	char letterGrade;
};

bool operator==(const Student& stu1, const Student& stu2){
	if (stu1.name == stu2.name && stu1.letterGrade == stu2.letterGrade) {
		return true;
	}
	else {
		return false;
	}
}

std::ostream& operator << (std::ostream& stream, const Student& student) {
	stream << student.name;
	stream << " (" << student.letterGrade << ") ";
	return stream;
}
