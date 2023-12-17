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
class NormalCourse :public Course {
public:
	NormalCourse() :Course() {}
	NormalCourse(string Name, int Level, int Hours) :Course(Name, Level, Hours) {
		code = Name + "_N" + to_string(Level);
	}
};
class SummerCourse :public Course {
public:
	SummerCourse() :Course() {}
	SummerCourse(string Name, int Level, int Hours) :Course(Name, Level, Hours) {
		code = name + "_S" + to_string(Level);
	}
};
class Student {
protected:
	int level, numberOfCourses;
	double grades[6];
	Course* courseList[6];
public:
	Student() :numberOfCourses(0) {
		for (int i = 0; i < 6; i++)
			courseList[i] = nullptr;
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
		double GPA=0;
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
			GPA=1.0;
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
			TotalGPA+=courseList[i]->getHours()* getCourseGPA(grades[i]);
		}
		return TotalGPA / Totalhours;
	}
};
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
Course* COURSES[] = { new NormalCourse("Math", 1, 2),
new NormalCourse("Programming_1,", 1, 3),
new NormalCourse("Technical_Writing", 1, 3),
new NormalCourse("Electronics", 2, 4),
new NormalCourse("Data_Structures", 2, 3),
new NormalCourse("OOP", 2, 3),
new NormalCourse("Algorithms", 3, 2),
new NormalCourse("Operating_Systems", 3, 3),
new NormalCourse("Databases", 3, 3),
new NormalCourse("Machine_Learning", 4, 3),
new NormalCourse("Compilers", 4, 4),
new NormalCourse("Programming_Concepts", 4, 4),
new SummerCourse("Math", 1, 2),
new SummerCourse("Compilers", 4, 4),
new SummerCourse("Algorithms", 3, 2),
new SummerCourse("OOP", 2, 3)
};
Course* searchCourse(string code) {
	for (Course* course : COURSES) {
		if (course->getCode() == code)
			return course;
	}
}

int main() {
	int numberOfStudents, choice,numerOfCourses,ID,Level;
	cout << "Number of Students: ";
	cin >> numberOfStudents;
	Student* student;
	string Name;
	for (int i = 0; i < numberOfStudents; i++) {
		cout << endl << "Enter Student type (0:General  1:Special): ";
		cin >> choice;
		if (choice == 0)
			student = new GeneralStudent;
		else if (choice == 1)
			student = new SpecialStudent;
		else 
			cout << "\nInvalid input\n";
		cout << "Enter Information of student number " << i + 1 << endl<<endl;
		cout << "Name: ";
		cin >> Name;
		cout << "\nID: ";
		cin >> ID;
		cout << "\nLevel: ";
		cin >> Level;
		cout << "\n---------------------------------------------------------\n";
		cout << "Enter number of courses: ";
		cin >> numerOfCourses;
		for (int j = 0; j < numerOfCourses; j++) {
			
		}

	}

}