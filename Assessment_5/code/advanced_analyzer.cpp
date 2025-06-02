#include <iostream>
#include <cctype>  // For toupper()
#include <algorithm> // For sort()
using namespace std;

const int MAX_STUDENTS = 30;
const int PASSING_GRADE = 50;
const int SENTINEL = -1; // Sentinel value to stop input

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
        cout << "4. Analyze performance (Pass/Fail)\n";
        cout << "5. Sort and display grades\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;
        
        // Convert to uppercase for case-insensitive comparison
        choice = toupper(choice);
        
        switch(choice) {
            case '1': { // Input student grades
                numStudents = 0; // Reset student count
                cout << "\nEnter grades one by one (enter " << SENTINEL << " to stop):\n";
                
                while (numStudents < MAX_STUDENTS) {
                    cout << "Grade for student " << (numStudents + 1) << ": ";
                    int grade;
                    cin >> grade;
                    
                    // Check for sentinel value
                    if (grade == SENTINEL) {
                        break;
                    }
                    
                    // Validate grade input
                    while (grade < 0 || grade > 100) {
                        cout << "Invalid grade. Please enter a value between 0 and 100 (or " 
                             << SENTINEL << " to stop): ";
                        cin >> grade;
                        if (grade == SENTINEL) break;
                    }
                    
                    if (grade != SENTINEL) {
                        grades[numStudents] = grade;
                        studentIDs[numStudents] = 1000 + numStudents;
                        numStudents++;
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
                
            case '4': { // Analyze performance (Pass/Fail)
                if (numStudents == 0) {
                    cout << "\nNo student data available. Please input grades first.\n";
                    break;
                }
                
                int passCount = 0;
                int failCount = 0;
                
                for (int i = 0; i < numStudents; i++) {
                    if (grades[i] >= PASSING_GRADE) {
                        passCount++;
                    } else {
                        failCount++;
                    }
                }
                
                cout << "\nPERFORMANCE ANALYSIS:\n";
                cout << "Passing students (≥" << PASSING_GRADE << "%): " << passCount << "\n";
                cout << "Failing students (<" << PASSING_GRADE << "%): " << failCount << "\n";
                break;
            }
                
            case '5': { // Sort and display grades
                if (numStudents == 0) {
                    cout << "\nNo student data available. Please input grades first.\n";
                    break;
                }
                
                // Create a temporary array for sorting
                int sortedGrades[MAX_STUDENTS];
                for (int i = 0; i < numStudents; i++) {
                    sortedGrades[i] = grades[i];
                }
                
                // Sort the array in ascending order
                sort(sortedGrades, sortedGrades + numStudents);
                
                cout << "\nGRADES SORTED IN ASCENDING ORDER:\n";
                for (int i = 0; i < numStudents; i++) {
                    cout << sortedGrades[i] << " ";
                }
                cout << "\n";
                break;
            }
                
            case '6': // Exit
                cout << "\nExiting program. Goodbye!\n";
                break;
                
            default:
                cout << "\nInvalid choice. Please enter a number between 1 and 6.\n";
        }
    } while (choice != '6');
    
    return 0;
}