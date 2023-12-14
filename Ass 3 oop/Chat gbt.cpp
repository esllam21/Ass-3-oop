//#include <iostream>
//#include <string>
//
//class Course {
//protected:
//    std::string name;
//    std::string code;
//    int minStudentLevel;
//    int creditHours;
//
//public:
//    Course() : name(""), code(""), minStudentLevel(0), creditHours(0) {}
//
//    Course(std::string name, int level, int creditHours)
//        : name(name), minStudentLevel(level), creditHours(creditHours) {
//        // Generate code based on class type
//        code = name + "_N" + std::to_string(level);
//    }
//
//    int getCreditHours() const {
//        return creditHours;
//    }
//
//    friend std::ostream& operator<<(std::ostream& os, const Course& course) {
//        os << "Code: " << course.code << ", Name: " << course.name
//            << ", Credit Hours: " << course.creditHours
//            << ", Min Student Level: " << course.minStudentLevel;
//        return os;
//    }
//};
//
//class Student {
//protected:
//    int level;
//    double grades[6];
//    Course* courseList[6];
//    int noOfCourses;
//
//public:
//    Student() : level(0), noOfCourses(0) {
//        for (int i = 0; i < 6; ++i) {
//            grades[i] = 0.0;
//            courseList[i] = nullptr;
//        }
//    }
//
//    virtual bool RegisterCourse(Course* course) {
//        if (noOfCourses >= 6 || level < course->minStudentLevel) {
//            return false;
//        }
//
//        courseList[noOfCourses++] = course;
//        return true;
//    }
//
//    void printRegisteredCourses() const {
//        for (int i = 0; i < noOfCourses; ++i) {
//            std::cout << *courseList[i] << ", Grade: " << grades[i] << std::endl;
//        }
//    }
//
//    virtual float CalculateExpenses() const = 0;
//
//    double getTotalGPA() const {
//        double totalPoints = 0.0;
//        double totalCredits = 0.0;
//
//        for (int i = 0; i < noOfCourses; ++i) {
//            totalPoints += getCourseGPA(grades[i]) * courseList[i]->getCreditHours();
//            totalCredits += static_cast<float>(courseList[i]->getCreditHours());
//        }
//
//        if (totalCredits == 0.0) {
//            return 0.0;
//        }
//
//        return totalPoints / totalCredits;
//    }
//
//    double getCourseGPA(double grade) const {
//        if (grade >= 90) {
//            return 4.0;
//        }
//        else if (grade >= 80) {
//            return 3.0;
//        }
//        else if (grade >= 70) {
//            return 2.0;
//        }
//        else if (grade >= 60) {
//            return 1.0;
//        }
//        else {
//            return 0.0;
//        }
//    }
//};
//
//class GeneralProgramStudent : public Student {
//public:
//    bool RegisterCourse(Course* course) override {
//        if (noOfCourses >= 6 || level < course->minStudentLevel) {
//            return false;
//        }
//
//        courseList[noOfCourses++] = course;
//        return true;
//    }
//
//    float CalculateExpenses() const override {
//        return static_cast<float>(level * 1000);
//    }
//};
//
//class SpecialProgramStudent : public Student {
//public:
//    bool RegisterCourse(Course* course) override {
//        if (noOfCourses >= 6) {
//            return false;
//        }
//
//        courseList[noOfCourses++] = course;
//        return true;
//    }
//
//    float CalculateExpenses() const override {
//        float totalCredits = 0.0;
//        for (int i = 0; i < noOfCourses; ++i) {
//            totalCredits += static_cast<float>(courseList[i]->getCreditHours());
//        }
//
//        return totalCredits * 500;
//    }
//};
//
//int main() {
//    // Example usage
//    GeneralProgramStudent generalStudent;
//    generalStudent.RegisterCourse(new Course("Math", 1, 3));
//    generalStudent.RegisterCourse(new Course("Physics", 2, 4));
//
//    SpecialProgramStudent specialStudent;
//    specialStudent.RegisterCourse(new Course("Computer Science", 1, 3));
//    specialStudent.RegisterCourse(new Course("Chemistry", 3, 4));
//
//    std::cout << "General Student Expenses: " << generalStudent.CalculateExpenses() << " EGP" << std::endl;
//    std::cout << "Special Student Expenses: " << specialStudent.CalculateExpenses() << " EGP" << std::endl;
//
//    return 0;
//}
