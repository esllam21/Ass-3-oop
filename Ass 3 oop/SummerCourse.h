#pragma once
#include "Course.h"
class SummerCourse :public Course {
public:
	SummerCourse() :Course() {}
	SummerCourse(string Name, int Level, int Hours) :Course(Name, Level, Hours) {
		code = name + "_S" + to_string(Level);
	}
};
