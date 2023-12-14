#include <iostream>
#include <string>

class Course {
protected:
    std::string name;
    std::string code;
    int minStudentLevel;
    int creditHours;

public:
    Course() : name(""), code(""), minStudentLevel(0), creditHours(0) {}

    Course(std::string name, int level, int creditHours)
        : name(name), minStudentLevel(level), creditHours(creditHours) {
        // Generate code based on class type
        code = name + "_N" + std::to_string(level);
    }

    friend std::ostream& operator<<(std::ostream& os, const Course& course) {
        os << "Code: " << course.code << ", Name: " << course.name
            << ", Credit Hours: " << course.creditHours
            << ", Min Student Level: " << course.minStudentLevel;
        return os;
    }
};

class NormalCourse : public Course {
public:
    NormalCourse() : Course() {
        // Additional initialization for NormalCourse
        code = "Default_N0";
    }

    NormalCourse(std::string name, int level, int creditHours)
        : Course(name, level, creditHours) {
        // Additional initialization for NormalCourse
        code = name + "_N" + std::to_string(level);
    }
};

class SummerCourse : public Course {
public:
    SummerCourse() : Course() {
        // Additional initialization for SummerCourse
        code = "Default_S0";
    }

    SummerCourse(std::string name, int level, int creditHours)
        : Course(name, level, creditHours) {
        // Additional initialization for SummerCourse
        code = name + "_S" + std::to_string(level);
    }
};

int main() {
    // Example usage
    Course genericCourse("Generic", 1, 3);
    std::cout << genericCourse << std::endl;

    NormalCourse mathNormal("Math", 2, 4);
    std::cout << mathNormal << std::endl;

    SummerCourse physicsSummer("Physics", 3, 5);
    std::cout << physicsSummer << std::endl;

    return 0;
}
