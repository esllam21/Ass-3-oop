#pragma once
#include "Course.h"
class NormalCourse :public Course {
public:
	NormalCourse() :Course() {}
	NormalCourse(string Name, int Level, int Hours) :Course(Name, Level, Hours) {
		code = Name + "_N" + to_string(Level);
	}
};
