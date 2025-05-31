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

vector<Student> students; // Global vector to hold student data

void loadStudents();
void saveStudents();
void addStudent();
void displayStudents();
bool idExists(int id);
bool isValidGrade(char grade);

int main() {
    loadStudents(); // Load existing data at startup
    
    int choice;
    do {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 3);
    
    return 0;
}

void loadStudents() {
    ifstream inFile("students.txt");
    if (!inFile) return; // File doesn't exist yet
    
    Student s;
    while (inFile >> s.id) {
        inFile.ignore(); // Skip whitespace after ID
        getline(inFile, s.name, '|'); // Read until delimiter
        inFile >> s.grade;
        students.push_back(s);
    }
    inFile.close();
}

void saveStudents() {
    ofstream outFile("students.txt");
    for (const auto& s : students) {
        outFile << s.id << " " << s.name << "|" << s.grade << endl;
    }
    outFile.close();
}

bool idExists(int id) {
    for (const auto& s : students) {
        if (s.id == id) return true;
    }
    return false;
}

bool isValidGrade(char grade) {
    grade = toupper(grade);
    return grade >= 'A' && grade <= 'F';
}

void addStudent() {
    Student s;
    
    // ID input with validation
    while (true) {
        cout << "\nEnter Student ID: ";
        if (cin >> s.id) {
            if (!idExists(s.id)) break;
            cout << "Error: ID already exists. Please enter a different ID.\n";
        } else {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    
    // Name input
    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, s.name);
    
    // Grade input with validation
    while (true) {
        cout << "Enter Student Grade (A-F): ";
        cin >> s.grade;
        s.grade = toupper(s.grade);
        if (isValidGrade(s.grade)) break;
        cout << "Error: Grade must be between A and F.\n";
    }
    
    students.push_back(s);
    saveStudents();
    cout << "Student record added successfully!\n";
}

void displayStudents() {
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