#include<iostream>
#include<string>
using namespace std;
class Course {
protected:

	string name;
	string code;
	int MinStudentLevel;
	int CreditHourse;
public:
	void setAll(string Name, string Code, int level, int hours) {
		name = Name;
		code = Code;
		MinStudentLevel = level;
		CreditHourse = hours;
	}
	string getName() { return name; }
	string getCode() { return code; }
	int getLevel() { return MinStudentLevel; }
	int getHours() { return CreditHourse; }
	Course() {
		name = "";
		code = "";
		MinStudentLevel = 0;
		CreditHourse = 0;
	}
	Course(string Name, int level, int hours) {
		name = Name;
		CreditHourse = hours;
		MinStudentLevel = level;
	}
	friend ostream& operator<<(ostream& on, Course &obj);
};
ostream& operator<<(ostream on, Course obj) {
	on << "course Code: " << obj.getCode() << endl << "Course Name: " << obj.getName() << endl << "Credit hours: " << obj.getHours() << endl << "Min Student Level: " << obj.getLevel() << endl;
	return on;
}
class Normalcourse :public Course {
	Normalcourse() :Course() {};
	Normalcourse(string name, int level, int creditHours):Course(name,level, creditHours){
		code = name + "-N" + to_string(level);
	}

};

class SummerCourse :public Course {
	SummerCourse() :Course() {};
	SummerCourse(string name, int level, int creditHours) :Course(name, level, creditHours) {
		code = name + "-S" + to_string(level);
	}

};
class Student {
	Student() {

	}
};