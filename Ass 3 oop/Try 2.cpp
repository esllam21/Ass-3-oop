//<<<<<<< HEAD
////#include<iostream>
////#include<string>
////using namespace std;
////class Course {
////protected:
////	string name;
////	string code;
////	int Min_Student_level;
////	int CreditHours;
////public:
////	void setHour(int hour) {
////		CreditHours = hour;
////	}
////	void setLevel(int level) {
////		Min_Student_level = level;
////	}
////	void setName(string Name) {
////		name = Name;
////	}
////	void setCode(string Code) {
////		code = Code;
////	}
////	Course() :name(""), code(""), Min_Student_level(0), CreditHours(0) {};
////	Course(string Name, int level, int Hours) :name(Name), Min_Student_level(level), CreditHours(Hours) {};
////	friend ostream& operator<<(ostream& out, const Course& obj);
////	int getHours() { return CreditHours; }
////	int getLevel() { return Min_Student_level; }
////	string getCODE() { return code; }
////	string getName() { return name; }
////};
////class NormalCourse :public Course {
////public:
////
////	NormalCourse() :Course() {};
////	NormalCourse(string Name, int level, int Hours) :Course(Name, level, Hours) {
////		code = name + "_N" + to_string(Min_Student_level);
////	}
////};
////class SummerCourse :public Course {
////public:
////
////	SummerCourse() :Course() {};
////	SummerCourse(string Name, int level, int Hours) :Course(Name, level, Hours) {
////		code = name + "_S" + to_string(Min_Student_level);
////	}
////};
////class Student {
////protected:
////	int level;
////	float grades[6];
////	Course* CourseList[6];
////	int noOfCourses;
////public:
////	float getGrades() {
////		for (int i = 0; i < 6; i++)
////			return grades[i];
////	}
////	Student() :noOfCourses(0), level(0) {
////		for (int i = 0; i < 6; i++) {
////			CourseList[i] = 0;
////			grades[i] = 0;
////		}
////	}
////	void print() {
////		for (int i = 0; i < noOfCourses; i++) {
////			cout << "kasjhgkasd\n";
////			cout << CourseList[i]->getHours() << "\nGrade: " << grades[i] << "\n";
////		}
////	}
////	virtual float CalculateExpenses() = 0;
////	bool RegisterCourse(Course* course) {
////		if (noOfCourses >= 0 && noOfCourses < 6) {
////			CourseList[noOfCourses] = course;
////			noOfCourses++;
////			return true;
////		}
////		else return false;
////	}
////
////	double getTotalGPA() {
////		double TotalGPA = 0;
////		double TotalHours = 0;
////		for (int i = 0; i < noOfCourses; i++) {
////			TotalHours += CourseList[i]->getHours();
////			TotalGPA += getCourseGPA(grades[i]) * CourseList[i]->getHours();
////		}
////		if (TotalHours == 0.0)
////			return 0.0;
////		else return TotalGPA / TotalHours;
////	}
////	double getCourseGPA(double grade) {
////		string GPA_Letter;
////		if (grade >= 98 && grade <= 100) {
////			GPA_Letter = "A+";
////			return 4.0;
////		}
////		else if (grade >= 93 && grade <= 97) {
////			GPA_Letter = "A";
////			return 4.0;
////		}
////		else if (grade >= 90 && grade <= 92) {
////			GPA_Letter = "A-";
////			return 3.7;
////		}
////		else if (grade >= 87 && grade <= 89) {
////			GPA_Letter = "B+";
////			return 3.3;
////		}
////		else if (grade >= 83 && grade <= 86) {
////			GPA_Letter = "B";
////			return 3.0;
////		}
////		else if (grade >= 80 && grade <= 82) {
////			GPA_Letter = "B-";
////			return 2.7;
////		}
////		else if (grade >= 77 && grade <= 79) {
////			GPA_Letter = "C+";
////			return 2.3;
////		}
////		else if (grade >= 73 && grade <= 76) {
////			GPA_Letter = "C";
////			return 2.0;
////		}
////		else if (grade >= 70 && grade <= 72) {
////			GPA_Letter = "C-";
////			return 1.7;
////		}
////		else if (grade >= 67 && grade <= 69) {
////			GPA_Letter = "D+";
////			return 1.3;
////		}
////		else if (grade >= 63 && grade <= 66) {
////			GPA_Letter = "D";
////			return 1.0;
////		}
////		else if (grade >= 60 && grade <= 62) {
////			GPA_Letter = "D-";
////			return 0.7;
////		}
////		else if (grade >= 0 && grade <= 59) {
////			GPA_Letter = "F";
////			return 0.0;
////		}
////		else cout << "Please enter valid Grade\n";
////	}
////};
////class GeneralProgramStudent :public Student {
////	bool RegisterCourse(Course* course) {
////		if (noOfCourses >= 0 && noOfCourses < 6 && course->getLevel() <= level) {
////			CourseList[noOfCourses] = course;
////			return true;
////		}
////		else return false;
////	}
////	float CalculateExpenses() {
////		float Expenses = 0;
////		for (int i = 0; i < noOfCourses; i++) {
////			Expenses = CourseList[i]->getLevel() * 1000;
////		}
////		return Expenses;
////
////	}
////};
////class SpecialProgramStudent :public Student {
////	bool RegisterCourse(Course* course) {
////		if (noOfCourses >= 0 && noOfCourses < 6) {
////			CourseList[noOfCourses] = course;
////			return true;
////		}
////		else return false;
////	}
////	float CalculateExpenses() {
////		float Expenses;
////		float TotalHours = 0;
////		for (int i = 0; i < noOfCourses; i++)
////			TotalHours += CourseList[i]->getHours();
////		Expenses = TotalHours * 500;
////
////
////		return Expenses;
////	}
////};
////
////ostream& operator<<(ostream& out, const Course& obj) {
////	out << "Course Information: " << endl << "Code: " << obj.code << endl;
////	out << "Name: " << obj.name << endl;
////	out << "Credit Hours: " << obj.CreditHours << endl;
////	out << "Minimum Student Level: " << obj.Min_Student_level;
////	return out;
////}
////Course* COURSES[] = { new NormalCourse("Math",1,2),
////				   new NormalCourse("Programming_1",1,3),
////				   new NormalCourse("Technical_Writing",1,3),
////				   new NormalCourse("Electronics",2,4),
////				   new NormalCourse("Data_Structures",2,3),
////				   new NormalCourse("OOP",2,3),
////				   new NormalCourse("Alogorithms",3,2),
////				   new NormalCourse("Operating_Systems",3,3),
////				   new NormalCourse("Databases",3,3),
////				   new NormalCourse("Machinw_Learning",4,3),
////				   new NormalCourse("Compilers",4,4),
////				   new NormalCourse("Programming_Concepts",4,4),
////				   new SummerCourse("Math",1,2),
////				   new SummerCourse("Compilers",4,4),
////				   new SummerCourse("Algorithms",3,2),
////				   new SummerCourse("OOP",2,3) };
////
////Course* searchCourse(string code) {
////
////	for (Course* course : COURSES) {
////		
////			course->setCode(code);
////			course->setName("ahmed");
////			return course;
////		
////		//else nullptr;
////	}
////}
////int main() {
////	int numberOfStudents, choice, ID, numberOfCourses, level;
////	string name;
////	cout << "Enter number of students\n";
////	cin >> numberOfStudents;
////	Student* students[10];
////	Course obj[6];
////	for (int i = 0; i < numberOfStudents; i++) {
////		cout << "Enter Student number " << i + 1 << "Type (0:General 1:Special)" << endl;
////		cin >> choice;
////		if (choice == 0)
////			students[i] = new GeneralProgramStudent;
////		else if (choice == 1)
////			students[i] = new SpecialProgramStudent;
////		else cout << "Invalid input\n";
////		cout << "Enter Student Information:\n";
////		cout << "Name: ";
////		cin >> name;
////
////		cout << "ID: ";
////		cin >> ID;
////		cout << "Level: ";
////		cin >> level;
////
////		cout << "Enter number of courses: ";
////		cin >> numberOfCourses;
////		for (int j = 0; j < numberOfCourses; j++) {
////			string courseCode;
////			cout << "Enter the course number" << j + 1 << " code: ";
////			cin >> courseCode;
////			obj[j].setCode(courseCode+"_N"+to_string(level));
////			Course* course = searchCourse(courseCode);
////			if (students[i]->RegisterCourse(course)) {
////				double grade;
////				cout << "Enter grade for " << courseCode << ": ";
////				cin >> grade;
////				students[i]->getCourseGPA(grade);
////			}
////			obj[j].getHours();
////
////		}
////		
////		cout << "\nStudent Information:" << endl;
////		cout << "Name: " << name << endl;
////		cout << "ID: " << ID << endl;
////		cout << "Level: " << level << endl;
////		for (int k = 0; k < numberOfCourses; k++) {
////			cout << "Name: "<<obj[k].getName() << endl <<"Code: "<< obj[k].getCODE() << endl <<"Hpurs: "<< obj[k].getHours() << endl;
////			cout << students[i]->getGrades() << endl;
////		}
////		cout << "Student Expenses: " << students[i]->CalculateExpenses() << endl;
////		cout << "Overall GPA: " << students[i]->getTotalGPA();
////	}
////
////}
//=======
//#include<iostream>
//#include<string>
//using namespace std;
//class Course {
//protected:
//	string name;
//	string code;
//	int Min_Student_level;
//	int CreditHours;
//public:
//	void setHour(int hour) {
//		CreditHours = hour;
//	}
//	void setLevel(int level) {
//		Min_Student_level = level;
//	}
//	void setName(string Name) {
//		name = Name;
//	}
//	void setCode(string Code) {
//		code = Code;
//	}
//	Course() :name(""), code(""), Min_Student_level(0), CreditHours(0) {};
//	Course(string Name, int level, int Hours) :name(Name), Min_Student_level(level), CreditHours(Hours) {};
//	friend ostream& operator<<(ostream& out, const Course& obj);
//	int getHours() { return CreditHours; }
//	int getLevel() { return Min_Student_level; }
//	string getCODE() { return code; }
//	string getName() { return name; }
//};
//class NormalCourse :public Course {
//public:
//
//	NormalCourse() :Course() {};
//	NormalCourse(string Name, int level, int Hours) :Course(Name, level, Hours) {
//		code = name + "_N" + to_string(Min_Student_level);
//	}
//};
//class SummerCourse :public Course {
//public:
//
//	SummerCourse() :Course() {};
//	SummerCourse(string Name, int level, int Hours):Course(Name,level,Hours) {
//		code = name + "_S" + to_string(Min_Student_level);
//	}
//};
//class Student {
//protected:
//	int level;
//	float grades[6];
//	Course* CourseList[6];
//	int noOfCourses;
//public:
//	float getGrades() {
//		for (int i = 0; i < 6; i++)
//			return grades[i];
//	}
//	Student() :noOfCourses(0),level(0) {
//		for (int i = 0; i < 6; i++) {
//			CourseList[i] = 0;
//			grades[i] = 0;
//		}
//	}
//	void print() {
//		for (int i = 0; i < noOfCourses; i++) {
//			cout << "kasjhgkasd\n";
//			cout << CourseList[i]<<"\nGrade: "<<grades[i]<<"\n";
//		}
//	}
//	virtual float CalculateExpenses() = 0;
//	bool RegisterCourse(Course*course) {
//		if (noOfCourses >= 0 && noOfCourses < 6) {
//			CourseList[noOfCourses] = course;
//			noOfCourses++;
//			return true;
//		}
//		else return false;
//	}
//	double getTotalGPA() {
//		double TotalGPA = 0;
//		double TotalHours = 0;
//		for (int i = 0; i < noOfCourses; i++) {
//			TotalHours += CourseList[i]->getHours();
//			TotalGPA += getCourseGPA(grades[i]) * CourseList[i]->getHours();
//		}
//		if (TotalHours == 0.0)
//			return 0.0;
//		else return TotalGPA / TotalHours;
//	}
//	double getCourseGPA(double grade) {
//		string GPA_Letter;
//		if (grade >= 98 && grade <= 100) {
//			GPA_Letter = "A+";
//			return 4.0;
//		}
//		else if (grade >= 93 && grade <= 97) {
//			GPA_Letter = "A";
//			return 4.0;
//		}
//		else if (grade >= 90 && grade <= 92) {
//			GPA_Letter = "A-";
//			return 3.7;
//		}
//		else if (grade >= 87 && grade <= 89) {
//			GPA_Letter = "B+";
//			return 3.3;
//		}
//		else if (grade >= 83 && grade <= 86) {
//			GPA_Letter = "B";
//			return 3.0;
//		}
//		else if (grade >= 80 && grade <= 82) {
//			GPA_Letter = "B-";
//			return 2.7;
//		}
//		else if (grade >= 77 && grade <= 79) {
//			GPA_Letter = "C+";
//			return 2.3;
//		}
//		else if (grade >= 73 && grade <= 76) {
//			GPA_Letter = "C";
//			return 2.0;
//		}
//		else if (grade >= 70 && grade <= 72) {
//			GPA_Letter = "C-";
//			return 1.7;
//		}
//		else if (grade >= 67 && grade <= 69) {
//			GPA_Letter = "D+";
//			return 1.3;
//		}
//		else if (grade >= 63 && grade <= 66) {
//			GPA_Letter = "D";
//			return 1.0;
//		}
//		else if (grade >= 60 && grade <= 62) {
//			GPA_Letter = "D-";
//			return 0.7;
//		}
//		else if (grade >= 0 && grade <= 59) {
//			GPA_Letter = "F";
//			return 0.0;
//		}
//		else cout << "Please enter valid Grade\n";
//	}
//};
//class GeneralProgramStudent :public Student {
//	bool RegisterCourse(Course* course) {
//		if (noOfCourses >= 0 && noOfCourses < 6 && course->getLevel() <= level) {
//			CourseList[noOfCourses] = course;
//			return true;
//		}
//		else return false;
//	}
//	float CalculateExpenses() {
//		float Expenses=0;
//		for (int i = 0; i < noOfCourses; i++) {
//			Expenses = CourseList[i]->getLevel() * 1000;
//		}
//		return Expenses;
//
//	}
//};
//class SpecialProgramStudent :public Student {
//	bool RegisterCourse(Course*course) {
//		if (noOfCourses >= 0 && noOfCourses < 6) {
//			CourseList[noOfCourses] = course;
//			return true;
//		}
//		else return false;
//	}
//	float CalculateExpenses() {
//		float Expenses;
//		float TotalHours = 0;
//		for (int i = 0; i < noOfCourses; i++)
//			TotalHours += CourseList[i]->getHours();
//		Expenses = TotalHours * 500;
//
//
//		return Expenses;
//	}
//};
//
//ostream& operator<<(ostream& out, const Course& obj) {
//	out << "Course Information: " << endl << "Code: " << obj.code << endl;
//	out << "Name: " << obj.name << endl;
//	out << "Credit Hours: " << obj.CreditHours << endl;
//	out << "Minimum Student Level: " << obj.Min_Student_level;
//	return out;
//}
//Course* COURSES[] = { new NormalCourse("Math",1,2),
//				   new NormalCourse("Programming_1",1,3),
//				   new NormalCourse("Technical_Writing",1,3),
//				   new NormalCourse("Electronics",2,4),-
//				   new NormalCourse("Data_Structures",2,3),
//				   new NormalCourse("OOP",2,3),
//				   new NormalCourse("Alogorithms",3,2),
//				   new NormalCourse("Operating_Systems",3,3),
//				   new NormalCourse("Databases",3,3),
//				   new NormalCourse("Machinw_Learning",4,3),
//				   new NormalCourse("Compilers",4,4),
//				   new NormalCourse("Programming_Concepts",4,4),
//				   new SummerCourse("Math",1,2),
//				   new SummerCourse("Compilers",4,4),
//				   new SummerCourse("Algorithms",3,2),
//				   new SummerCourse("OOP",2,3) };
//
//Course* searchCourse(string code) {
//	
//	for (Course* course : COURSES) {
//		if (course->getCODE() == code) {
//			course->setHour()
//		}
//		else nullptr;
//	}
//}
//int main() {
//	int numberOfStudents,choice,ID,numberOfCourses,level;
//	string name;
//	cout << "Enter number of students\n";
//	cin >> numberOfStudents;
//	Student* students[10];
//	Course obj[6];
//	for (int i = 0; i < numberOfStudents; i++) {
//		cout << "Enter Student number " << i + 1 << "Type (0:General 1:Special)" << endl;
//		cin >> choice;
//		if (choice == 0)
//			students[i] = new GeneralProgramStudent;
//		else if (choice == 1)
//			students[i] = new SpecialProgramStudent;
//		else cout << "Invalid input\n";
//		cout << "Enter Student Information:\n";
//		cout << "Name: " ;
//		cin >> name;
//
//		cout << "ID: ";
//		cin >> ID;
//		cout << "Level: ";
//		cin >> level;
//		
//		cout << "Enter number of courses: ";
//		cin >> numberOfCourses;
//		for (int j = 0; j < numberOfCourses; j++) {
//			string courseCode;
//			cout << "Enter the course number" << j + 1 << " code: "; 
//			cin >> courseCode;
//			Course* course = searchCourse(courseCode);
//			if (students[i]->RegisterCourse(course)) {
//				double grade;
//				cout << "Enter grade for " << courseCode << ": ";
//				cin >> grade;
//				students[i]->getCourseGPA(grade);
//			}
//			obj[j].setCode(courseCode);
//		}
//		cout << "\nStudent Information:" << endl;
//		cout << "Name: " << name<<endl;
//		cout << "ID: " << ID << endl;
//		cout << "Level: " << level << endl;
//		for (int k = 0; k < numberOfCourses; k++) {
//			cout << obj[k].getName() << endl << obj[k].getCODE() << endl  << obj[k].getHours() << endl;
//			cout << students[i]->getGrades() << endl;
//		}
//		cout<<"Student Expenses: "<<students[i]->CalculateExpenses()<<endl;
//		cout<<"Overall GPA: "<<students[i]->getTotalGPA();
//	}
//
//}
