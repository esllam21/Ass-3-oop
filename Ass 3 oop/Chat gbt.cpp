//#include <iostream>
//#include <string>
//#include <iomanip>
//
//class Course {
//protected:
//    std::string Name;
//    std::string Code;
//    int MinStudentLevel;
//    int CreditHours;
//
//public:
//    Course() {}
//    Course(std::string name, int level, int creditHours) : Name(name), MinStudentLevel(level), CreditHours(creditHours) {}
//
//    friend std::ostream& operator<<(std::ostream& os, const Course& course) {
//        os << "Name: " << course.Name << "\n";
//        os << "Code: " << course.Code << "\n";
//        os << "Credit Hours: " << course.CreditHours << "\n";
//        os << "Min Student Level: " << course.MinStudentLevel << "\n";
//        return os;
//    }
//
//    int GetMinStudentLevel() const { return MinStudentLevel; }
//    int GetCreditHours() const { return CreditHours; }
//};
//
//class NormalCourse : public Course {
//public:
//    NormalCourse() {}
//    NormalCourse(std::string name, int level, int creditHours) : Course(name, level, creditHours) {
//        Code = name + "_N" + std::to_string(level);
//    }
//};
//
//class SummerCourse : public Course {
//public:
//    SummerCourse() {}
//    SummerCourse(std::string name, int level, int creditHours) : Course(name, level, creditHours) {
//        Code = name + "_S" + std::to_string(level);
//    }
//};
//
//class Student {
//protected:
//    std::string Name;
//    std::string ID;
//    int Level;
//    double Grades[6] = { 0 };
//    Course* courseList[6] = { nullptr };
//    int noOfCourses = 0;
//
//public:
//    Student() {}
//    bool RegisterCourse(Course* course);
//    void printRegisteredCourses();
//    virtual double CalculateExpenses() = 0;
//    double getTotalGPA();
//    double getCourseGPA(double grade);
//
//    const std::string& GetName() const { return Name; }
//    const std::string& GetID() const { return ID; }
//    int GetLevel() const { return Level; }
//};
//
//class GeneralStudent : public Student {
//public:
//    bool RegisterCourse(Course* course) override;
//    double CalculateExpenses() override;
//};
//
//class SpecialStudent : public Student {
//public:
//    bool RegisterCourse(Course* course) override;
//    double CalculateExpenses() override;
//};
//
//Course* COURSES[] = {
//    new NormalCourse("Math", 1, 2),
//    new NormalCourse("Programming_1", 1, 3),
//    new NormalCourse("Technical_Writing", 1, 3),
//    new NormalCourse("Electronics", 2, 4),
//    new NormalCourse("Data_Structures", 2, 3),
//    new NormalCourse("OOP", 2, 3),
//    new NormalCourse("Algorithms", 3, 2),
//    new NormalCourse("Operating_Systems", 3, 3),
//    new NormalCourse("Databases", 3, 3),
//    new NormalCourse("Machine_Learning", 4, 3),
//    new NormalCourse("Compilers", 4, 4),
//    new NormalCourse("Programming_Concepts", 4, 4),
//    new SummerCourse("Math", 1, 2),
//    new SummerCourse("Compilers", 4, 4),
//    new SummerCourse("Algorithms", 3, 2),
//    new SummerCourse("OOP", 2, 3)
//};
//
//Course* searchCourse(std::string code) {
//    for (Course* course : COURSES) {
//        if (course->Code == code) {
//            return course;
//        }
//    }
//    return nullptr;
//}
//
//bool Student::RegisterCourse(Course* course) {
//    if (noOfCourses >= 6) {
//        std::cout << "Error: Maximum number of courses reached\n";
//        return false;
//    }
//
//    if (course->GetMinStudentLevel() > Level) {
//        std::cout << "Error: You cannot register in this course\n";
//        return false;
//    }
//
//    courseList[noOfCourses++] = course;
//    return true;
//}
//
//void Student::printRegisteredCourses() {
//    std::cout << "Registered Courses:\n";
//    for (int i = 0; i < noOfCourses; ++i) {
//        std::cout << "Course " << i + 1 << ":\n";
//        std::cout << *courseList[i];
//        std::cout << "Grade: " << Grades[i] << "\n";
//    }
//}
//
//double Student::getTotalGPA() {
//    double totalGradePoints = 0.0;
//    int totalCreditHours = 0;
//
//    for (int i = 0; i < noOfCourses; ++i) {
//        totalGradePoints += getCourseGPA(Grades[i]) * courseList[i]->GetCreditHours();
//        totalCreditHours += courseList[i]->GetCreditHours();
//    }
//
//    if (totalCreditHours == 0) {
//        return 0.0;
//    }
//
//    return totalGradePoints / totalCreditHours;
//}
//
//double Student::getCourseGPA(double grade) {
//    // Implement based on GPA calculation table
//    return 0.0;
//}
//
//bool GeneralStudent::RegisterCourse(Course* course) {
//    // Implementation specific to GeneralStudent
//    return false;
//}
//
//double GeneralStudent::CalculateExpenses() {
//    // Implementation specific to GeneralStudent
//    return 0.0;
//}
//
//bool SpecialStudent::RegisterCourse(Course* course) {
//    // Implementation specific to SpecialStudent
//    return false;
//}
//
//double SpecialStudent::CalculateExpenses() {
//    // Implementation specific to SpecialStudent
//    return 0.0;
//}
//
//int main() {
//    int numStudents;
//    std::cout << "How many students in the system? ";
//    std::cin >> numStudents;
//
//    for (int i = 0; i < numStudents; ++i) {
//        std::cout << "Enter student type (0: general, 1: special): ";
//        int studentType;
//        std::cin >> studentType;
//
//        std::string name, id;
//        int level;
//        std::cout << "Enter name: ";
//        std::cin >> name;
//        std::cout << "Enter ID: ";
//        std::cin >> id;
//        std::cout << "Enter student level: ";
//        std::cin >> level;
//
//        Student* student;
//        if (studentType == 0) {
//            student = new GeneralStudent();
//        }
//        else {
//            student = new SpecialStudent();
//        }
//
//        student->Name = name;
//        student->ID = id;
//        student->Level = level;
//
//        int numCourses;
//        std::cout << "Enter the number of courses to register: ";
//        std::cin >> numCourses;
//
//        for (int j = 0; j < numCourses; ++j) {
//            std::cout << "Course " << j + 1 << ":\n";
//            std::string courseCode;
//            std::cout << "Code: ";
//            std::cin >> courseCode;
//
//            Course* course = searchCourse(courseCode);
//            if (course) {
//                if (student->RegisterCourse(course)) {
//                    std::cout << "Grade: ";
//                    std::cin >> student->Grades[j];
//                }
//                else {
//                    --j; // Retry the same course
//                }
//            }
//            else {
//                std::cout << "Error: Course not found\n";
//                --j;
//            }
//        }
//
//        std::cout << "\nStudent Name: " << student->GetName() << "\n";
//        std::cout << "ID: " << student->GetID() << "\n";
//        std::cout << "Level: " << student->GetLevel() << "\n";
//        student->printRegisteredCourses();
//        std::cout << "Overall GPA: " << std::fixed << std::setprecision(2) << student->getTotalGPA() << "\n";
//        std::cout << "Student Expenses: " << student->CalculateExpenses() << " EGP\n\n";
//
//        delete student;
//    }
//
//    for (Course* course : COURSES) {
//        delete course;
//    }
//
//    return 0;
//}
