#include <iostream>
#include <cctype>
#include <algorithm>
#include <cstdio>
#include <limits>

using namespace std;

const int MAX_STUDENTS = 30;
const int PASSING_GRADE = 50;
const int SENTINEL = -1;

// Clear the input buffer
void clearInputBuffer() {
    cin.clear();
    while (cin.get() != '\n');
}

// Get menu choice using getchar()
char getMenuChoice() {
    cout << "Enter your choice (1-6): ";
    char choice = getchar();
    clearInputBuffer(); // Clear the newline and any other characters
    return toupper(choice);
}

int main() {
    int grades[MAX_STUDENTS];
    int studentIDs[MAX_STUDENTS];
    int numStudents = 0;
    char choice;
    
    do {
        cout << "\nSTUDENT GRADE ANALYZER MENU:\n";
        cout << "1. Input student grades\n";
        cout << "2. Display all student grades\n";
        cout << "3. Calculate statistics\n";
        cout << "4. Analyze performance (Pass/Fail)\n";
        cout << "5. Sort and display grades\n";
        cout << "6. Exit\n";
        
        choice = getMenuChoice();
        
        switch(choice) {
            case '1': {
                numStudents = 0;
                cout << "\nEnter grades one by one (enter " << SENTINEL << " to stop):\n";
                
                while (numStudents < MAX_STUDENTS) {
                    cout << "Grade for student " << (numStudents + 1) << ": ";
                    int grade;
                    cin >> grade;
                    
                    if (cin.fail()) {
                        cin.clear();
                        clearInputBuffer();
                        cout << "Invalid input. Please enter a number.\n";
                        continue;
                    }
                    
                    if (grade == SENTINEL) break;
                    
                    while (grade < 0 || grade > 100) {
                        cout << "Invalid grade (0-100). Try again or " << SENTINEL << " to stop: ";
                        cin >> grade;
                        if (cin.fail()) {
                            cin.clear();
                            clearInputBuffer();
                            grade = -1; // Force re-prompt
                            continue;
                        }
                        if (grade == SENTINEL) break;
                    }
                    
                    if (grade != SENTINEL) {
                        grades[numStudents] = grade;
                        studentIDs[numStudents] = 1000 + numStudents;
                        numStudents++;
                    }
                }
                clearInputBuffer();
                cout << "\nStored grades for " << numStudents << " students.\n";
                break;
            }
                
            case '2': {
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
                
            case '3': {
                if (numStudents == 0) {
                    cout << "\nNo student data available. Please input grades first.\n";
                    break;
                }
                
                double sum = 0;
                int highest = grades[0];
                int lowest = grades[0];
                
                for (int i = 0; i < numStudents; i++) {
                    sum += grades[i];
                    highest = max(highest, grades[i]);
                    lowest = min(lowest, grades[i]);
                }
                
                cout << "\nGRADE STATISTICS:\n";
                cout << "Average grade: " << (sum / numStudents) << "\n";
                cout << "Highest grade: " << highest << "\n";
                cout << "Lowest grade: " << lowest << "\n";
                break;
            }
                
            case '4': {
                if (numStudents == 0) {
                    cout << "\nNo student data available. Please input grades first.\n";
                    break;
                }
                
                int passCount = count_if(grades, grades + numStudents, 
                    [](int grade) { return grade >= PASSING_GRADE; });
                
                cout << "\nPERFORMANCE ANALYSIS:\n";
                cout << "Passing students (≥" << PASSING_GRADE << "%): " << passCount << "\n";
                cout << "Failing students (<" << PASSING_GRADE << "%): " << (numStudents - passCount) << "\n";
                break;
            }
                
            case '5': {
                if (numStudents == 0) {
                    cout << "\nNo student data available. Please input grades first.\n";
                    break;
                }
                
                int sortedGrades[MAX_STUDENTS];
                copy(grades, grades + numStudents, sortedGrades);
                sort(sortedGrades, sortedGrades + numStudents);
                
                cout << "\nGRADES SORTED IN ASCENDING ORDER:\n";
                for (int i = 0; i < numStudents; i++) {
                    cout << sortedGrades[i] << (i < numStudents - 1 ? ", " : "\n");
                }
                break;
            }
                
            case '6': {
                cout << "\nExiting program. Goodbye!\n";
                break;
            }
                
            default: {
                cout << "\nInvalid choice. Please enter a number between 1 and 6.\n";
                break;
            }
        }
    } while (choice != '6');
    
    return 0;
}