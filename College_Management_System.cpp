#include <iostream>
#include <cstring>

using namespace std;

const int MAX_STUDENTS = 10;
const int MAX_COURSES = 10;

class Student {
public:
    int id;
    char name[50];
    char program[30];
    float gpa;

    void input() {
        cout << "Enter ID: " ;
        cin >> id;
        cin.ignore();
        cout<<" Enter your NAME: "<<endl;
        cin.getline(name, 50);
        cout<<"Enter your PROGRAM: "<<endl;
        cin.getline(program, 30);
        cout<<"Enter your gpa: "<<endl;
        cin >> gpa;
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Program: " << program << ", GPA: " << gpa << endl;
    }
};

class Course {
public:
    int code;
    char name[50];
    int credits;

    void input() {
        cout << "Enter your course code "<<endl;
        cin >> code;
        cin.ignore();
        cout<<"Enter your course name "<<endl;
        cin.getline(name, 50);
        cout<<"Enter your course credits "<<endl;
        cin >> credits;
    }

    void display() const {
        cout << "Code: " << code << ", Name: " << name << ", Credits: " << credits << endl;
    }
};

Student students[MAX_STUDENTS];
Course courses[MAX_COURSES];
int numStudents = 0;
int numCourses = 0;

void addStudent() {
    if (numStudents == MAX_STUDENTS) {
        cout << "Error: Maximum number of students reached!" << endl;
        return;
    }
    students[numStudents].input();
    numStudents++;
    cout << "Student added successfully!" << endl;
}

void displayStudents() {
    if (numStudents == 0) {
        cout << "No students found!" << endl;
        return;
    }
    for (int i = 0; i < numStudents; i++) {
        students[i].display();
    }
}

void searchStudent() {
    if (numStudents == 0) {
        cout << "No students found!" << endl;
        return;
    }
    int searchID;
    cout << "Enter student ID to search: ";
    cin >> searchID;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == searchID) {
            cout << "Student found: ";
            students[i].display();
            return;
        }
    }
    cout << "Student with ID " << searchID << " not found." << endl;
}

void updateStudent() {
    if (numStudents == 0) {
        cout << "No students found!" << endl;
        return;
    }
    int updateID;
    cout << "Enter student ID to update: ";
    cin >> updateID;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == updateID) {
            cout << "Enter new information:" << endl;
            students[i].input();
            cout << "Student information updated." << endl;
            return;
        }
    }
    cout << "Student with ID " << updateID << " not found." << endl;
}

void deleteStudent() {
    if (numStudents == 0) {
        cout << "No students found!" << endl;
        return;
    }
    int deleteID;
    cout << "Enter student ID to delete: ";
    cin >> deleteID;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == deleteID) {
            for (int j = i; j < numStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            numStudents--;
            cout << "Student with ID " << deleteID << " deleted." << endl;
            return;
        }
    }
    cout << "Student with ID " << deleteID << " not found." << endl;
}

void addCourse() {
    if (numCourses == MAX_COURSES) {
        cout << "Error: Maximum number of courses reached!" << endl;
        return;
    }
    courses[numCourses].input();
    numCourses++;
    cout << "Course added successfully!" << endl;
}

void displayCourses() {
    if (numCourses == 0) {
        cout << "No courses found!" << endl;
        return;
    }
    for (int i = 0; i < numCourses; i++) {
        courses[i].display();
    }
}

void searchCourse() {
    if (numCourses == 0) {
        cout << "No courses found!" << endl;
        return;
    }
    int searchCode;
    cout << "Enter course code to search: ";
    cin >> searchCode;
    for (int i = 0; i < numCourses; i++) {
        if (courses[i].code == searchCode) {
            cout << "Course found: ";
            courses[i].display();
            return;
        }
    }
    cout << "Course with code " << searchCode << " not found." << endl;
}

void updateCourse() {
    if (numCourses == 0) {
        cout << "No courses found!" << endl;
        return;
    }
    int updateCode;
    cout << "Enter course code to update: ";
    cin >> updateCode;
    for (int i = 0; i < numCourses; i++) {
        if (courses[i].code == updateCode) {
            cout << "Enter new information:" << endl;
            courses[i].input();
            cout << "Course information updated." << endl;
            return;
        }
    }
    cout << "Course with code " << updateCode << " not found." << endl;
}

void deleteCourse() {
    if (numCourses == 0) {
        cout << "No courses found!" << endl;
        return;
    }
    int deleteCode;
    cout << "Enter course code to delete: ";
    cin >> deleteCode;
    for (int i = 0; i < numCourses; i++) {
        if (courses[i].code == deleteCode) {
            for (int j = i; j < numCourses - 1; j++) {
                courses[j] = courses[j + 1];
            }
            numCourses--;
            cout << "Course with code " << deleteCode << " deleted." << endl;
            return;
        }
    }
    cout << "Course with code " << deleteCode << " not found." << endl;
}

void displayMenu() {
    cout << "\nUniversity Management System\n";
    cout << "1. Add Student\n";
    cout << "2. Display Students\n";
    cout << "3. Search Student\n";
    cout << "4. Update Student\n";
    cout << "5. Delete Student\n";
    cout << "6. Add Course\n";
    cout << "7. Display Courses\n";
    cout << "8. Search Course\n";
    cout << "9. Update Course\n";
    cout << "10. Delete Course\n";
    cout << "0. Exit\n";
}

int main() {
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                addCourse();
                break;
            case 7:
                displayCourses();
                break;
            case 8:
                searchCourse();
                break;
            case 9:
                updateCourse();
                break;
            case 10:
                deleteCourse();
                break;
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}
