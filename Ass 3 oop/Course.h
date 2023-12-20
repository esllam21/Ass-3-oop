#pragma once
#include<iostream>
#include<string>
using namespace std;
class Course {
protected:
	string name, code;
	int MinLevel;
	int hours;
public:
	void setName(string Name) { name = Name; }
	string getName() { return name; }
	void setCode(string Code) { code = Code; }
	string getCode() { return code; }
	void setMinLevel(int level) { MinLevel = level; }
	int getMinLevel() { return MinLevel; }
	void setHours(int Hours) { hours = Hours; }
	int getHours() { return hours; }
	Course() : name(""), code(""), MinLevel(0), hours(0) {}
	Course(string Name, int Level, int Hours) :name(Name), MinLevel(Level), hours(Hours) {}
	friend ostream& operator<<(ostream& out, const Course& obj) {
		out << "Code: " << obj.code << endl;
		out << "Course Name: " << obj.name << endl;
		out << "Credit Hours: " << obj.hours << endl;
		out << "Minmum Student level: " << obj.MinLevel << endl;
	}
};
