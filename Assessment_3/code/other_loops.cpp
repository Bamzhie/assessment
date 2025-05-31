#include <iostream>
#include <iomanip>
#include <limits> 
#include <cctype> 


int main() {
    int choice;

    // Initialize for while loop
    char continueChoice = 'Y'; 
    int conversionCount = 0;


    while (toupper(continueChoice) == 'Y') {
        // Display conversion menu
        std::cout << "\nSelect a conversion type:\n";
        std::cout << "1: Length (Kilometers to Miles)\n";
        std::cout << "2: Weight (Kilograms to Pounds)\n";
        std::cout << "3: Time (Hours to Minutes)\n";
        std::cout << "Enter your choice (1-3): ";
        std::cin >> choice;

        // Input validation - ensures choice is between 1-3
        while (std::cin.fail() || choice < 1 || choice > 3) {
            std::cin.clear(); 

            // Discard bad input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input. Please enter 1, 2, or 3: ";
            std::cin >> choice;
        }

        double inputValue, convertedValue;
        std::string inputUnit, outputUnit;

        // Get  input  based on conversion type
        switch (choice) {
            // Length conversion
            case 1: 
                std::cout << "Enter the distance in kilometers: ";
                inputUnit = "kilometers";
                outputUnit = "miles";
                break;

             // Weight conversion
            case 2:
                std::cout << "Enter the weight in kilograms: ";
                inputUnit = "kilograms";
                outputUnit = "pounds";
                break;
            // Time conversion
            case 3:
                std::cout << "Enter the time in hours: ";
                inputUnit = "hours";
                outputUnit = "minutes";
                break;
        }

        // Get input value with validation
        while (!(std::cin >> inputValue) || inputValue < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a positive number: ";
        }

        // Perform the conversion
        switch (choice) {
            case 1: convertedValue = inputValue * 0.621371; break;
            case 2: convertedValue = inputValue * 2.20462; break;
            case 3: convertedValue = inputValue * 60; break;      
        }

        // Display formatted result
        std::cout << "Converted " << inputUnit << ": " << std::fixed;
        if (choice == 1 || choice == 2) {
            std::cout << std::setprecision(2) << convertedValue; 
        } else {
            std::cout << std::setprecision(0) << convertedValue;
        }
        std::cout << " " << outputUnit << std::endl;


         // Track total conversions
        conversionCount++;

        // Prompt for continuation
        std::cout << "\nDo you want to perform another conversion? (y/n): ";
        std::cin >> continueChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    }

    // Final output showing total conversions
    std::cout << "\nYou performed " << conversionCount << " conversion" 
              << (conversionCount != 1 ? "s" : "") << ".\n";

    return 0;
}