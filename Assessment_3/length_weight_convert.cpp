#include <iostream>
#include <iomanip>
#include <limits> // For std::numeric_limits

int main() {
    int choice;
    char continueChoice;
    int conversionCount = 0;

    do {
        // Display menu
        std::cout << "Select a conversion type:\n";
        std::cout << "1: Length (Kilometers to Miles)\n";
        std::cout << "2: Weight (Kilograms to Pounds)\n";
        std::cout << "3: Time (Hours to Minutes)\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Validate input
        while (std::cin.fail() || choice < 1 || choice > 3) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter 1, 2, or 3: ";
            std::cin >> choice;
        }

        double inputValue, convertedValue;
        std::string inputUnit, outputUnit;

        switch (choice) {
            case 1: // Kilometers to Miles
                std::cout << "Enter the distance in kilometers: ";
                inputUnit = "kilometers";
                outputUnit = "miles";
                break;
            case 2: // Kilograms to Pounds
                std::cout << "Enter the weight in kilograms: ";
                inputUnit = "kilograms";
                outputUnit = "pounds";
                break;
            case 3: // Hours to Minutes
                std::cout << "Enter the time in hours: ";
                inputUnit = "hours";
                outputUnit = "minutes";
                break;
        }

        std::cin >> inputValue;

        // Perform conversion
        switch (choice) {
            case 1:
                convertedValue = inputValue * 0.621371;
                break;
            case 2:
                convertedValue = inputValue * 2.20462;
                break;
            case 3:
                convertedValue = inputValue * 60;
                break;
        }

        // Display result
        std::cout << "Converted " << inputUnit << ": " << std::fixed;
        if (choice == 1 || choice == 2) {
            std::cout << std::setprecision(2) << convertedValue;
        } else {
            std::cout << std::setprecision(0) << convertedValue;
        }
        std::cout << " " << outputUnit << std::endl;

        conversionCount++;

        // Ask if user wants to continue
        std::cout << "Do you want to perform another conversion? (y/n): ";
        std::cin >> continueChoice;

        // Clear input 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (continueChoice == 'y' || continueChoice == 'Y');

    // Display total conversions
    std::cout << "You performed " << conversionCount << " conversion" 
              << (conversionCount != 1 ? "s" : "") << ".\n";

    return 0;
}