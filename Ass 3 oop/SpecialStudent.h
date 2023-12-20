#pragma once
#include"Student.h"
class SpecialStudent :public Student {
public:
	bool RegisterCourse(Course* course) {
		for (int i = 0; i < numberOfCourses; i++) {
			courseList[i]->setName(course->getName());
			courseList[i]->setCode(course->getCode());
			courseList[i]->setMinLevel(course->getMinLevel());
			courseList[i]->setHours(course->getHours());
		}
		return true;
	}
	float CalculateExpenses() {
		float Expenses = 0;
		float TotalHours = 0;
		for (int i = 0; i < numberOfCourses; i++) {
			TotalHours += courseList[i]->getHours();
		}
		Expenses = TotalHours * 500;
		return Expenses;
	}
};
