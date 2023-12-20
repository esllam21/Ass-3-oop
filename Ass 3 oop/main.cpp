#include<string>
#include"Course.h"
#include"NormalCourse.h"
#include"SummerCourse.h"
#include"Student.h"
#include"GeneralStudent.h"
#include"SpecialStudent.h"
Course* COURSES[] = { new NormalCourse("Math", 1, 2),
new NormalCourse("Programming_1", 1, 3),
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
	return nullptr;
}

int main() {
	int numberOfStudents, choice,numerOfCourses,ID,Level;
	cout << "Number of Students: ";
	cin >> numberOfStudents;
	string Name;
	for (int i = 0; i < numberOfStudents; i++) {
		cout << endl << "Enter Student type (0:General  1:Special): ";
		cin >> choice;
		Student* student{};

		if (choice == 0)
			student= new GeneralStudent;
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
		student[i].setName(Name);
		student[i].setID(ID);
		student[i].setLevel(Level);
		cout << "\n---------------------------------------------------------\n";
		cout << "Enter number of courses: ";
		cin >> numerOfCourses;
		for (int j = 0; j < numerOfCourses; j++) {
			cout << "Enter Course Code: ";
			string courseCode;
			cin >> courseCode;
			cout << "Enter grade: ";
			Course* course = searchCourse(courseCode);
			if (course != nullptr) {
				if (student->RegisterCourse(course)) {
					double grade;
					cout << "Grade: ";
					cin >> grade;
					student->grades[j] = grade;
				}
				else {
					cout << "Error: You cannot register in this course\n";
					--j;
				}

			}
			else cout << "Error course not found\n";			
		}
		cout << "\nStudent Name: " << student->getName() << "\n";
		cout << "ID: " << student->getID() << "\n";
		cout << "Level: " << student->getLevel() << "\n";
		student->printRegisteredCourses();
		cout << "Overall GPA: " << student->getTotalGPA() << "\n";
		cout << "Student Expenses: " << student->CalculateExpenses() << " EGP\n\n";


	}
	return 0;

}