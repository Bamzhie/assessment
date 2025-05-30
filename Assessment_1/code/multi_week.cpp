#include <iostream>

int main() {
    // Define weekly expenses
    double groceries_week1, rent_week1, utilities_week1;
    double groceries_week2, rent_week2, utilities_week2;

    // Input for Week 1
    std::cout << "--- Week 1 Expenses ---" << std::endl;
    std::cout << "Enter Groceries expense: $";
    std::cin >> groceries_week1;
    std::cout << "Enter Rent expense: $";
    std::cin >> rent_week1;
    std::cout << "Enter Utilities expense: $";
    std::cin >> utilities_week1;

    // Input for Week 2
    std::cout << "\n--- Week 2 Expenses ---" << std::endl;
    std::cout << "Enter Groceries expense: $";
    std::cin >> groceries_week2;
    std::cout << "Enter Rent expense: $";
    std::cin >> rent_week2;
    std::cout << "Enter Utilities expense: $";
    std::cin >> utilities_week2;

    // Calculate totals
    double total_week1 = groceries_week1 + rent_week1 + utilities_week1;
    double total_week2 = groceries_week2 + rent_week2 + utilities_week2;

    // Print results
    std::cout << "\n--- Expense Summary ---" << std::endl;
    std::cout << "Week 1 Total: $" << total_week1 << std::endl;
    std::cout << "Week 2 Total: $" << total_week2 << std::endl;

    // Compare weeks
    if (total_week2 > total_week1) {
        double increase = total_week2 - total_week1;
        std::cout << "Spending INCREASED by $" << increase << std::endl;
    } else if (total_week2 < total_week1) {
        double decrease = total_week1 - total_week2;
        std::cout << "Spending DECREASED by $" << decrease << std::endl;
    } else {
        std::cout << "Spending remained the SAME." << std::endl;
    }

    return 0;
}
