#include<iostream>
#include<iomanip>
using namespace std;

struct Course {
    string name;
    int credits;
    float grade;
};

float calculateGPA(Course courses[], int numCourses) {
    float totalGradePoints = 0;
    int totalCredits = 0;

    for (int i = 0; i < numCourses; i++) {
        totalGradePoints += (courses[i].grade * courses[i].credits);
        totalCredits += courses[i].credits;
    }

    if (totalCredits == 0) return 0.0;
    return totalGradePoints / totalCredits;
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    Course courses[numCourses];

    for (int i = 0; i < numCourses; i++) {
        cout << "Enter course " << i + 1 << " name: ";
        cin >> courses[i].name;
        cout << "Enter credits for " << courses[i].name << ": ";
        cin >> courses[i].credits;
        cout << "Enter grade (0.0 to 4.0) for " << courses[i].name << ": ";
        cin >> courses[i].grade;
    }

    cout << "\nCourse Grades:" << endl;
    cout << left << setw(20) << "Course Name" << setw(10) << "Credits" << setw(10) << "Grade" << endl;
    for (int i = 0; i < numCourses; i++) {
        cout << left << setw(20) << courses[i].name << setw(10) << courses[i].credits << setw(10) << fixed << setprecision(2) << courses[i].grade << endl;
    }

    float gpa = calculateGPA(courses, numCourses);
    cout << "\nTotal GPA: " << fixed << setprecision(2) << gpa << endl;

    return 0;
}

