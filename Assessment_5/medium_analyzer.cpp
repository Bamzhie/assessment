#include <iostream>
#include <cctype> // For toupper()
using namespace std;

const int MAX_STUDENTS = 30;

int main() {
    int grades[MAX_STUDENTS];
    int studentIDs[MAX_STUDENTS];
    int numStudents = 0;
    char choice;
    
    do {
        // Display menu
        cout << "\nSTUDENT GRADE ANALYZER MENU:\n";
        cout << "1. Input student grades\n";
        cout << "2. Display all student grades\n";
        cout << "3. Calculate statistics\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        
        // Convert to uppercase for case-insensitive comparison
        choice = toupper(choice);
        
        switch(choice) {
            case '1': { // Input student grades
                cout << "\nEnter the number of students (up to " << MAX_STUDENTS << "): ";
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
                    studentIDs[i] = 1000 + i; // Generate unique student ID
                    
                    // Validate grade input
                    while (grades[i] < 0 || grades[i] > 100) {
                        cout << "Invalid grade. Please enter a value between 0 and 100: ";
                        cin >> grades[i];
                    }
                }
                cout << "\nGrades successfully stored for " << numStudents << " students!\n";
                break;
            }
                
            case '2': { // Display all student grades
                if (numStudents == 0) {
                    cout << "\nNo student data available. Please input grades first.\n";
                    break;
                }
                
                cout << "\nSTUDENT GRADES LIST:\n";
                for (int i = 0; i < numStudents; i++) {
                    cout << "Student ID: " << studentIDs[i] << " - Grade: " << grades[i] << "\n";
                }
                break;
            }
                
            case '3': { // Calculate statistics
                if (numStudents == 0) {
                    cout << "\nNo student data available. Please input grades first.\n";
                    break;
                }
                
                double sum = 0;
                int highest = grades[0];
                int lowest = grades[0];
                
                for (int i = 0; i < numStudents; i++) {
                    sum += grades[i];
                    
                    if (grades[i] > highest) {
                        highest = grades[i];
                    }
                    
                    if (grades[i] < lowest) {
                        lowest = grades[i];
                    }
                }
                
                double average = sum / numStudents;
                
                cout << "\nGRADE STATISTICS:\n";
                cout << "Average grade: " << average << "\n";
                cout << "Highest grade: " << highest << "\n";
                cout << "Lowest grade: " << lowest << "\n";
                break;
            }
                
            case '4': // Exit
                cout << "\nExiting program. Goodbye!\n";
                break;
                
            default:
                cout << "\nInvalid choice. Please enter a number between 1 and 4.\n";
        }
    } while (choice != '4');
    
    return 0;
}