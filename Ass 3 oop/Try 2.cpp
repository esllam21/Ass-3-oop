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
	int getLevel() { return Min_Student_level; }
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
protected:
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
		double TotalGPA = 0;
		double TotalHours = 0;
		for (int i = 0; i < noOfCourses; i++) {
			TotalHours += CourseList[i]->getHours();
			TotalGPA += getCourseGPA(grades[i]) * CourseList[i]->getHours();
		}
		if (TotalHours == 0.0)
			return 0.0;
		return TotalGPA / TotalHours;
	}
	double getCourseGPA(double grade) {
		string GPA_Letter;
		if (grade >= 98 && grade <= 100) {
			GPA_Letter = "A+";
			return 4.0;
		}
		else if (grade >= 93 && grade <= 97) {
			GPA_Letter = "A";
			return 4.0;
		}
		else if (grade >= 90 && grade <= 92) {
			GPA_Letter = "A-";
			return 3.7;
		}
		else if (grade >= 87 && grade <= 89) {
			GPA_Letter = "B+";
			return 3.3;
		}
		else if (grade >= 83 && grade <= 86) {
			GPA_Letter = "B";
			return 3.0;
		}
		else if (grade >= 80 && grade <= 82) {
			GPA_Letter = "B-";
			return 2.7;
		}
		else if (grade >= 77 && grade <= 79) {
			GPA_Letter = "C+";
			return 2.3;
		}
		else if (grade >= 73 && grade <= 76) {
			GPA_Letter = "C";
			return 2.0;
		}
		else if (grade >= 70 && grade <= 72) {
			GPA_Letter = "C-";
			return 1.7;
		}
		else if (grade >= 67 && grade <= 69) {
			GPA_Letter = "D+";
			return 1.3;
		}
		else if (grade >= 63 && grade <= 66) {
			GPA_Letter = "D";
			return 1.0;
		}
		else if (grade >= 60 && grade <= 62) {
			GPA_Letter = "D-";
			return 0.7;
		}
		else if (grade >= 0 && grade <= 59) {
			GPA_Letter = "F";
			return 0.0;
		}
		else cout << "Please enter valid Grade\n";
	}
};
class GenralProgramStudent :public Student {
	bool RegisterCourse(Course* course) {
		if (noOfCourses >= 0 && noOfCourses < 6 && course->getLevel() <= level) {
			CourseList[noOfCourses] = course;
			return true;
		}
		else return false;
	}
	float CalculateExpenses() {
		float Expenses = level*1000;
		return Expenses;
	}
};
class SpecialProgramStudent :public Student {
	bool RegisterCourse(Course*course) {
		if (noOfCourses >= 0 && noOfCourses < 6) {
			CourseList[noOfCourses] = course;
			return true;
		}
		else return false;
	}
	float CalculateExpenses() {
		float Expenses;
		float TotalHours = 0;
		for (int i = 0; i < noOfCourses; i++)
			TotalHours += CourseList[i]->getHours();
		Expenses = TotalHours * 500;



	}
};

ostream& operator<<(ostream& out, const Course& obj) {
	out << "Course Information: \nCode: " << obj.code << endl;
	out << "Name: " << obj.name << endl;
	out << "Credit Hours: " << obj.CreditHours << endl;
	out << "Minimum Student Level: " << obj.Min_Student_level;
	return out;
}
