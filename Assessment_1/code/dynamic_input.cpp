#include <iostream>
#include <iomanip>
#include <limits> // Needed for input validation
using namespace std;

int main() {
    int numCategories = 0;
    
    // Input validation for number of categories
    while (true) {
        cout << "Enter number of expense categories (must be at least 1): ";
        if (cin >> numCategories && numCategories >= 1) {
            break; // Valid input, exit the loop
        } else {
            cout << "Invalid input. Please enter a positive integer.\n";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
        }
    }

    string categories[numCategories];
    double week1[numCategories], week2[numCategories];

    // Get category names in a loop
    for (int i = 0; i < numCategories; i++) {
        cout << "Enter name for category " << i+1 << ": ";
        cin >> categories[i];
    }

    // Get Week 1 expenses with validation
    cout << "\n--- Week 1 Expenses ---\n";
    for (int i = 0; i < numCategories; i++) {
        while (true) {
            cout << categories[i] << ": $";
            if (cin >> week1[i] && week1[i] >= 0) {
                break;
            } else {
                cout << "Invalid amount. Please enter a positive number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }

    // Get Week 2 expenses with validation
    cout << "\n--- Week 2 Expenses ---\n";
    for (int i = 0; i < numCategories; i++) {
        while (true) {
            cout << categories[i] << ": $";
            if (cin >> week2[i] && week2[i] >= 0) {
                break;
            } else {
                cout << "Invalid amount. Please enter a positive number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }

    // Display weekly comparison
    cout << "\n--- Expense Comparison ---\n";
    for (int i = 0; i < numCategories; i++) {
        double diff = week2[i] - week1[i];
        cout << categories[i] << ":\n";
        cout << "  Week 1: $" << fixed << setprecision(2) << week1[i] << "\n";
        cout << "  Week 2: $" << week2[i] << "\n";
        cout << "  Difference: ";
        
        if (diff > 0)
            cout << "Increased by $" << diff << "\n";
        else if (diff < 0)
            cout << "Decreased by $" << -diff << "\n";
        else
            cout << "No change\n";
        
        cout << endl;
    }

    // Calculate and compare totals
    double total1 = 0, total2 = 0;
    for (int i = 0; i < numCategories; i++) {
        total1 += week1[i];
        total2 += week2[i];
    }

    cout << "\n--- Weekly Totals ---\n";
    cout << "Week 1 Total: $" << total1 << "\n";
    cout << "Week 2 Total: $" << total2 << "\n";
    
    if (total2 > total1)
        cout << "Overall: Increased by $" << total2 - total1 << "\n";
    else if (total2 < total1)
        cout << "Overall: Decreased by $" << total1 - total2 << "\n";
    else
        cout << "Overall: No change\n";

    return 0;
}