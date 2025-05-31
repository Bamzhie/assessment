#include <iostream>
using namespace std;

const int MAX_STUDENTS = 30;

int main() {
    int grades[MAX_STUDENTS];
    int studentIDs[MAX_STUDENTS];
    int numStudents = 0;
    int choice;
    
    do {
        // Display menu
        cout << "\nStudent Grade Analyzer Menu:\n";
        cout << "1. Input student grades\n";
        cout << "2. Display all student grades\n";
        cout << "3. Calculate and display average grade\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
             // Input student grades
            case 1: {
                cout << "Enter the number of students (up to " << MAX_STUDENTS << "): ";
                cin >> numStudents;
                
                if (numStudents <= 0 || numStudents > MAX_STUDENTS) {
                    cout << "Invalid number of students. Please enter a value between 1 and " << MAX_STUDENTS << ".\n";
                    numStudents = 0;
                    break;
                }
                
                cout << "Enter grades one by one:\n";
                for (int i = 0; i < numStudents; i++) {
                    cout << "Grade for student " << (i + 1) << ": ";
                    cin >> grades[i];

                    // Assign student ID starting from 1000
                    studentIDs[i] = 1000 + i;
                    
                    // Validate grade input
                    while (grades[i] < 0 || grades[i] > 100) {
                        cout << "Invalid grade. Please enter a value between 0 and 100: ";
                        cin >> grades[i];
                    }
                }
                cout << "Grades successfully stored!\n";
                break;
            }


              // Display all student grades  
            case 2: { 
                if (numStudents == 0) {
                    cout << "No student data available. Please input grades first.\n";
                    break;
                }
                
                cout << "\nStudent Grades List:\n";
                for (int i = 0; i < numStudents; i++) {
                    cout << "Student ID: " << studentIDs[i] << " - Grade: " << grades[i] << "\n";
                }
                break;
            }

            
            // Calculate and display average grade 
            case 3: { 
                if (numStudents == 0) {
                    cout << "No student data available. Please input grades first.\n";
                    break;
                }
                
                double sum = 0;
                for (int i = 0; i < numStudents; i++) {
                    sum += grades[i];
                }
                double average = sum / numStudents;
                cout << "\nAverage grade: " << average << "\n";
                break;
            }
                
            case 4: // Exit
                cout << "Exiting program. Goodbye!\n";
                break;
                
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
    
    return 0;
}