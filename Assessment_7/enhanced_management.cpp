#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

struct Student {
    int id;
    string name;
    char grade;
};

// Function prototypes with parameters
void loadStudents(vector<Student>& students);
void saveStudents(const vector<Student>& students);
bool addStudent(vector<Student>& students, int id, const string& name, char grade);
void displayStudents(const vector<Student>& students);
bool idExists(const vector<Student>& students, int id);
bool isValidGrade(char grade);
void searchStudent(const vector<Student>& students, int searchId);

int main() {
    vector<Student> students;
    loadStudents(students);
    
    int choice;
    do {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                int id;
                string name;
                char grade;
                
                cout << "\nEnter Student ID: ";
                cin >> id;
                cout << "Enter Student Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Student Grade (A-F): ";
                cin >> grade;
                
                if (addStudent(students, id, name, grade)) {
                    cout << "Student record added successfully!\n";
                } else {
                    cout << "Failed to add student. ID may already exist or grade is invalid.\n";
                }
                break;
            }
            case 2:
                displayStudents(students);
                break;
            case 3: {
                int searchId;
                cout << "Enter Student ID to search: ";
                cin >> searchId;
                searchStudent(students, searchId);
                break;
            }
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 4);
    
    return 0;
}

void loadStudents(vector<Student>& students) {
    ifstream inFile("students.txt");
    if (!inFile) return;
    
    Student s;
    while (inFile >> s.id) {
        inFile.ignore();
        getline(inFile, s.name, '|');
        inFile >> s.grade;
        students.push_back(s);
    }
    inFile.close();
}

void saveStudents(const vector<Student>& students) {
    ofstream outFile("students.txt");
    for (const auto& s : students) {
        outFile << s.id << " " << s.name << "|" << s.grade << endl;
    }
    outFile.close();
}

bool addStudent(vector<Student>& students, int id, const string& name, char grade) {
    if (idExists(students, id)) {
        return false;
    }
    
    grade = toupper(grade);
    if (!isValidGrade(grade)) {
        return false;
    }
    
    Student newStudent;
    newStudent.id = id;
    newStudent.name = name;
    newStudent.grade = grade;
    
    students.push_back(newStudent);
    saveStudents(students);
    return true;
}

void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nNo student records found.\n";
        return;
    }
    
    cout << "\nStudent Records:\n";
    cout << "--------------------\n";
    for (const auto& s : students) {
        cout << "Student ID: " << s.id << endl;
        cout << "Student Name: " << s.name << endl;
        cout << "Grade: " << s.grade << endl;
        cout << "--------------------\n";
    }
    cout << "Total students: " << students.size() << endl;
}

bool idExists(const vector<Student>& students, int id) {
    for (const auto& s : students) {
        if (s.id == id) return true;
    }
    return false;
}

bool isValidGrade(char grade) {
    grade = toupper(grade);
    return grade >= 'A' && grade <= 'F';
}

void searchStudent(const vector<Student>& students, int searchId) {
    for (const auto& s : students) {
        if (s.id == searchId) {
            cout << "\nStudent Found:\n";
            cout << "--------------------\n";
            cout << "Student ID: " << s.id << endl;
            cout << "Student Name: " << s.name << endl;
            cout << "Grade: " << s.grade << endl;
            cout << "--------------------\n";
            return;
        }
    }
    cout << "Student with ID " << searchId << " not found.\n";
}