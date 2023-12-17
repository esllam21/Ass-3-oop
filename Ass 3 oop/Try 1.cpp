//#include<iostream>
//#include<string>
//using namespace std;
//class Course {
//protected:
//
//	string name;
//	string code;
//	int MinStudentLevel;
//	int CreditHours;
//public:
//	void setName_code(string Name, string Code) {
//		name = Name;
//		code = Code;
//	}
//	void setAll(string Name, string Code, int level, int hours) {
//		name = Name;
//		code = Code;
//		MinStudentLevel = level;
//		CreditHours = hours;
//	}
//	string getName() { return name; }
//	string getCode() { return code; }
//	int getLevel() { return MinStudentLevel; }
//	int getHours() { return CreditHours; }
//	Course() {
//		name = "";
//		code = "";
//		MinStudentLevel = 0;
//		CreditHours = 0;
//	}
//	Course(string Name, int level, int hours) {
//		name = Name;
//		CreditHours = hours;
//		MinStudentLevel = level;
//	}
//	friend ostream& operator<<(ostream& on, Course &obj);
//};
//ostream& operator<<(ostream on, Course obj) {
//	on << "course Code: " << obj.getCode() << endl << "Course Name: " << obj.getName() << endl << "Credit hours: " << obj.getHours() << endl << "Min Student Level: " << obj.getLevel() << endl;
//	return on;
//}
//class Normalcourse :public Course {
//	Normalcourse() :Course() {};
//	Normalcourse(string name, int level, int creditHours):Course(name,level, creditHours){
//		code = name + "-N" + to_string(level);
//	}
//
//};
//
//class SummerCourse :public Course {
//	SummerCourse() :Course() {};
//	SummerCourse(string name, int level, int creditHours) :Course(name, level, creditHours) {
//		code = name + "-S" + to_string(level);
//	}
//
//};
//class Student {
//protected:
//	Course* CourseList[6];
//	int noOfCourses;
//	int level;
//	double Grades[6];
//public:
//
//	Student() {
//		noOfCourses = 0;
//		for (int i = 0; i < 6; i++) {
//			CourseList[i] = 0;
//		}
//	}
//	void printRegisteredCourses() {
//		for (int i = 0; i < noOfCourses; i++) {
//			cout << "Course Information:\n Code: " << CourseList[i]->getCode() << " \nName: " << CourseList[i]->getName() << endl;
//			cout << "Grades: " << Grades[i];
//		}
//	}
//	virtual float CalculateExpenses() = 0;
//	bool RegisterCourse(Course* course) {
//		if (noOfCourses >= 0 && noOfCourses < 6) {
//			CourseList[noOfCourses] = course;
//			noOfCourses++;
//			return true;
//		}
//		else return false;
//	}
//	void getTotalGpa() {
//		double totalGPA = 0.0;
//		double 
//	}
//	double getCourseGPA(double grade) {
//
//		if (grade >= 90.0) {
//			return 4.0;
//		}
//		else if (grade >= 85.0) {
//			return 3.7;
//		}
//		else if (grade >= 80.0) {
//			return 3.3;
//		}
//		else if (grade >= 75.0) {
//			return 3.0;
//		}
//		else if (grade >= 70.0) {
//			return 2.7;
//		}
//		else if (grade >= 65.0) {
//			return 2.3;
//		}
//		else if (grade >= 60.0) {
//			return 2.0;
//		}
//		else if (grade >= 55.0) {
//			return 1.7;
//		}
//		else if (grade >= 50.0) {
//			return 1.3;
//		}
//		else if (grade >= 45.0) {
//			return 1.0;
//		}
//		else if (grade >= 40.0) {
//			return 0.7;
//		}
//		else {
//			return 0.0;
//		}
//	}
//	
//};