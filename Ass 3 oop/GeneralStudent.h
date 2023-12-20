#pragma once
#include"Student.h"
class GeneralStudent :public Student {
public:
	bool RegisterCourse(Course* course) {
		if (level > course->getMinLevel()) {
			for (int i = 0; i < numberOfCourses; i++) {
				courseList[i]->setName(course->getName());
				courseList[i]->setCode(course->getCode());
				courseList[i]->setMinLevel(course->getMinLevel());
				courseList[i]->setHours(course->getHours());
			}
			return true;
		}
		else {
			cout << "Registeration failed\n";
			return false;
		}
	}
	float CalculateExpenses() {
		float Expenses = level * 1000;
		return Expenses;
	}
};
