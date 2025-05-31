#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

// Global constants
const string FILENAME = "students.txt";
const char DELIMITER = '|';

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
int deleteStudent(vector<Student>& students, int id);

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
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
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
            case 5: {
                int id;
                cout << "Enter Student ID to delete: ";
                cin >> id;
                int result = deleteStudent(students, id);
                if (result == 1) {
                    cout << "Student record deleted successfully!\n";
                } else {
                    cout << "Failed to delete student. ID not found.\n";
                }
                break;
            }
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 6);
    
    return 0;
}

void loadStudents(vector<Student>& students) {
    ifstream inFile(FILENAME);
    if (!inFile) return;
    
    students.clear(); // Clear existing data before loading
    
    string line;
    while (getline(inFile, line)) {
        size_t delimiterPos = line.find(DELIMITER);
        size_t spacePos = line.find(' ');
        
        if (delimiterPos != string::npos && spacePos != string::npos) {
            Student s;
            s.id = stoi(line.substr(0, spacePos));
            s.name = line.substr(spacePos + 1, delimiterPos - spacePos - 1);
            s.grade = line[delimiterPos + 1];
            students.push_back(s);
        }
    }
    inFile.close();
}

void saveStudents(const vector<Student>& students) {
    ofstream outFile(FILENAME);
    for (const auto& s : students) {
        outFile << s.id << " " << s.name << DELIMITER << s.grade << endl;
    }
    outFile.close();
}

int addStudent(vector<Student>& students, int id, const string& name, char grade) {
    if (idExists(students, id)) {
        return 0;
    }
    
    grade = toupper(grade);
    if (!isValidGrade(grade)) {
        return 0;
    }
    
    Student newStudent = {id, name, grade};
    students.push_back(newStudent);
    saveStudents(students);
    return 1;
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
    return any_of(students.begin(), students.end(), 
        [id](const Student& s) { return s.id == id; });
}

bool isValidGrade(char grade) {
    grade = toupper(grade);
    return grade >= 'A' && grade <= 'F';
}

int searchStudent(const vector<Student>& students, int searchId) {
    auto it = find_if(students.begin(), students.end(),
        [searchId](const Student& s) { return s.id == searchId; });
    
    return (it != students.end()) ? distance(students.begin(), it) : -1;
}

int updateStudent(vector<Student>& students, int id, const string& newName, char newGrade) {
    newGrade = toupper(newGrade);
    if (!isValidGrade(newGrade)) {
        return 0;
    }
    
    auto it = find_if(students.begin(), students.end(),
        [id](const Student& s) { return s.id == id; });
    
    if (it != students.end()) {
        it->name = newName;
        it->grade = newGrade;
        saveStudents(students);
        return 1;
    }
    return 0;
}

int deleteStudent(vector<Student>& students, int id) {
    auto it = find_if(students.begin(), students.end(),
        [id](const Student& s) { return s.id == id; });
    
    if (it != students.end()) {
        students.erase(it);
        saveStudents(students);
        return 1;
    }
    return 0;
}