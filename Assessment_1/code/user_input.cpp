
#include <iostream>

int main() {
    double groceries, rent, utilities, budget;

    // Get input for expenses
    std::cout << "Enter weekly Groceries expense: $";
    std::cin >> groceries;

    std::cout << "Enter weekly Rent expense: $";
    std::cin >> rent;

    std::cout << "Enter weekly Utilities expense: $";
    std::cin >> utilities;

    // Get input for budget
    std::cout << "Enter your weekly budget limit: $";
    std::cin >> budget;

    // Calculate total expenses
    double totalExpenses = groceries + rent + utilities;

    // Display results
    std::cout << "\n--- Weekly Expense Summary ---" << std::endl;
    std::cout << "Groceries: $" << groceries << std::endl;
    std::cout << "Rent: $" << rent << std::endl;
    std::cout << "Utilities: $" << utilities << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Total Expenses: $" << totalExpenses << std::endl;
    std::cout << "Budget Limit: $" << budget << std::endl;

    // Compare expenses with budget
    if (totalExpenses <= budget) {
        std::cout << "You are within budget!" << std::endl;
    } else {
        double overBudget = totalExpenses - budget;
        std::cout << "budget exceeded by $" << overBudget << std::endl;
    }

    return 0;
}