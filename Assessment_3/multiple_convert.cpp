#include <iostream>
#include <iomanip>

int main() {
    double kilometers, miles;
    char choice;
    int conversionCount = 0;

    do {
        // Prompt user for input
        std::cout << "Enter the distance in kilometers: ";
        std::cin >> kilometers;

        // Convert kilometers to miles
        miles = kilometers * 0.621371;

        // Display the result with 2 decimal places
        std::cout << "Converted distance: " << std::fixed << std::setprecision(2) 
                  << miles << " miles\n";

        // Increment conversion count
        conversionCount++;

        // Ask if user wants to continue
        std::cout << "Do you want to convert another distance? (y/n): ";
        std::cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    // Display total conversions
    std::cout << "You performed " << conversionCount << " conversion" 
              << (conversionCount != 1 ? "s" : "") << ".\n";

    return 0;
}