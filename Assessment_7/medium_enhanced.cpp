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

// Function prototypes
void loadStudents(vector<Student>& students);
void saveStudents(const vector<Student>& students);
int addStudent(vector<Student>& students, int id, const string& name, char grade);
void displayStudents(const vector<Student>& students);
bool idExists(const vector<Student>& students, int id);
bool isValidGrade(char grade);
int searchStudent(const vector<Student>& students, int searchId);
int updateStudent(vector<Student>& students, int id, const string& newName, char newGrade);

int main() {
    vector<Student> students;
    loadStudents(students);
    
    int choice;
    do {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Exit\n";
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
                
                int result = addStudent(students, id, name, grade);
                if (result == 1) {
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
                int position = searchStudent(students, searchId);
                if (position != -1) {
                    cout << "\nStudent Found:\n";
                    cout << "--------------------\n";
                    cout << "Student ID: " << students[position].id << endl;
                    cout << "Student Name: " << students[position].name << endl;
                    cout << "Grade: " << students[position].grade << endl;
                    cout << "--------------------\n";
                } else {
                    cout << "Student with ID " << searchId << " not found.\n";
                }
                break;
            }
            case 4: {
                int id;
                string newName;
                char newGrade;
                
                cout << "Enter Student ID to update: ";
                cin >> id;
                cout << "Enter New Name: ";
                cin.ignore();
                getline(cin, newName);
                cout << "Enter New Grade (A-F): ";
                cin >> newGrade;
                
                int result = updateStudent(students, id, newName, newGrade);
                if (result == 1) {
                    cout << "Student record updated successfully!\n";
                } else {
                    cout << "Failed to update student. ID not found or grade is invalid.\n";
                }
                break;
            }
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 5);
    
    return 0;
}

void loadStudents(vector<Student>& students) {
    ifstream inFile("students.txt");
    if (!inFile) return;
    
    Student s;
    string line;
    while (getline(inFile, line)) {
        size_t pipePos = line.find('|');
        size_t spacePos = line.find(' ');
        
        if (pipePos != string::npos && spacePos != string::npos) {
            s.id = stoi(line.substr(0, spacePos));
            s.name = line.substr(spacePos + 1, pipePos - spacePos - 1);
            s.grade = line[pipePos + 1];
            students.push_back(s);
        }
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

int addStudent(vector<Student>& students, int id, const string& name, char grade) {
    if (idExists(students, id)) {
        return 0; // ID already exists
    }
    
    grade = toupper(grade);
    if (!isValidGrade(grade)) {
        return 0; // Invalid grade
    }
    
    Student newStudent;
    newStudent.id = id;
    newStudent.name = name;
    newStudent.grade = grade;
    
    students.push_back(newStudent);
    saveStudents(students);
    return 1; // Success
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

int searchStudent(const vector<Student>& students, int searchId) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == searchId) {
            return i; // Return position if found
        }
    }
    return -1; // Return -1 if not found
}

int updateStudent(vector<Student>& students, int id, const string& newName, char newGrade) {
    newGrade = toupper(newGrade);
    if (!isValidGrade(newGrade)) {
        return 0; // Invalid grade
    }
    
    for (auto& s : students) {
        if (s.id == id) {
            s.name = newName;
            s.grade = newGrade;
            saveStudents(students);
            return 1; // Success
        }
    }
    return 0; // ID not found
}