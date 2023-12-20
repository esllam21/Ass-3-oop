#pragma once
#include"Course.h"
class Student {
protected:
	int level, ID, numberOfCourses;
	string Name;
	Course* courseList[6];
public:
	double grades[6] = { 0 };

	void setLevel(int Level) {
		level = Level;
	}
	int getLevel() { return level; }
	void setName(string name) {
		Name = name;
	}
	string getName() { return Name; }
	void setID(int id) {
		ID = id;
	}
	int getID() { return ID; }
	Student() :numberOfCourses(0),level(0),ID(0),Name("") {
		for (int i = 0; i < 6; i++)
			courseList[i] = 0;
	}
	void printRegisteredCourses() {
		for (int i = 0; i < numberOfCourses; i++) {
			cout << "Course " << i + 1 << " Information:\n" << courseList[i] << endl;
			cout << "Grade: " << grades[i] << endl;
		}
	}
	virtual float CalculateExpenses() = 0;
	bool RegisterCourse(Course* course) {
		if (numberOfCourses <= 6 && numberOfCourses >= 0) {
			for (int i = 0; i < numberOfCourses; i++) {
				courseList[i]->setName(course->getName());
				courseList[i]->setCode(course->getCode());
				courseList[i]->setMinLevel(course->getMinLevel());
				courseList[i]->setHours(course->getHours());
				return true;
			}
			numberOfCourses++;
		}
		else {
			cout << "Registeration falied\n";
			return false;
		}
	}
	double getCourseGPA(double grade) {
		double GPA = 0;
		if (grade >= 98 && grade <= 100)
			GPA = 4.0;
		else if (grade >= 93 && grade <= 97)
			GPA = 4.0;
		else if (grade >= 90 && grade <= 92)
			GPA = 3.7;
		else if (grade >= 87 && grade <= 89)
			GPA = 3.3;
		else if (grade >= 83 && grade <= 86)
			GPA = 3.0;
		else if (grade >= 80 && grade <= 82)
			GPA = 2.7;
		else if (grade >= 77 && grade <= 79)
			GPA = 2.3;
		else if (grade >= 73 && grade <= 76)
			GPA = 2.0;
		else if (grade >= 70 && grade <= 72)
			GPA = 1.7;
		else if (grade >= 67 && grade <= 69)
			GPA = 1.3;
		else if (grade >= 63 && grade <= 66)
			GPA = 1.0;
		else if (grade >= 60 && grade <= 62)
			GPA = 0.7;
		else if (grade >= 0 && grade <= 59)
			GPA = 0.0;

		else cout << "Please enter valid Grade\n";
		return GPA;
	}
	double getTotalGPA() {
		float Totalhours = 0;
		float TotalGPA = 0;
		for (int i = 0; i < numberOfCourses; i++) {
			Totalhours += courseList[i]->getHours();
			TotalGPA += courseList[i]->getHours() * getCourseGPA(grades[i]);
		}
		return TotalGPA / Totalhours;
	}
};
