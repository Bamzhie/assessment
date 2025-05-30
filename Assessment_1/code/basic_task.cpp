#include <iostream>

int main() {

    // variables for groceries, rent, and utilities
    double groceries = 125.50;
    double rent = 800.00;
    double utilities = 150.75;
    
    // Calculate total weekly expense
    double totalWeeklyExpense = groceries + rent + utilities;
    
    // Print total weekly expense
    std::cout << "Weekly Expenses Breakdown:" << std::endl;
    std::cout << "Groceries: $" << groceries << std::endl;
    std::cout << "Rent: $" << rent << std::endl;
    std::cout << "Utilities: $" << utilities << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Total Weekly Expense: $" << totalWeeklyExpense << std::endl;
    
    return 0;
}