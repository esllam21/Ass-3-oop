#include<iostream>
#include<string>
using namespace std;
class Course {
protected:
	string name;
	string code;
	int Min_Student_level;
	int CreditHours;
public:
	Course() :name(""), code(""), Min_Student_level(0), CreditHours(0) {};
	Course(string Name, int level, int Hours) :name(Name), Min_Student_level(level), CreditHours(Hours) {};
	friend ostream& operator<<(ostream& out, const Course& obj);
	int getHours() { return CreditHours; }
};
class NormalCourse :public Course {
	NormalCourse() :Course() {};
	NormalCourse(string Name, int level, int Hours) :Course(Name, level, Hours) {
		code = name + "_N" + to_string(Min_Student_level);
	}
};
class SummerCourse :public Course {
	SummerCourse() :Course() {};
	SummerCourse(string Name, int level, int Hours):Course(Name,level,Hours) {
		code = name + "_S" + to_string(Min_Student_level);
	}
};
class Student {
	int level;
	float grades[6];
	Course* CourseList[6];
	int noOfCourses;
public:
	Student():noOfCourses(0) {
		for (int i = 0; i < 6; i++)
			CourseList[i] = 0;
	}
	void print() {
		for (int i = 0; i < noOfCourses; i++) {
			cout << CourseList[i]<<"\nGrade: "<<grades[i];
		}
	}
	virtual float CalculateExpenses() = 0;
	bool RegisterCourse(Course*course) {
		if (noOfCourses >= 0 && noOfCourses < 6) {
			CourseList[noOfCourses] = course;
			noOfCourses++;
			return true;
		}
		else return false;
	}
	double getTotalGPA() {
		double totalGPA = 0;
		double TotalHours = 0;
		for (int i = 0; i < noOfCourses; i++) {
			TotalHours += CourseList[i]->getHours();

		}
	}
};
























ostream& operator<<(ostream& out, const Course& obj) {
	out << "Course Information: \nCode: " << obj.code << endl;
	out << "Name: " << obj.name << endl;
	out << "Credit Hours: " << obj.CreditHours << endl;
	out << "Minimum Student Level: " << obj.Min_Student_level;
	return out;
}
