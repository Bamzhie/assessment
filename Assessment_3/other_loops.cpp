#include <iostream>
#include <iomanip>
#include <limits> // Required for input validation
#include <cctype> // For toupper() function

/*
* Enhanced Unit Conversion Program
* Features:
* - Multiple conversion types (length, weight, time)
* - Input validation
* - Different output formatting per conversion type
* - Conversion counter
* - Uses while loop with initial priming read
*/

int main() {
    int choice;
    char continueChoice = 'Y'; // Initialize for while loop
    int conversionCount = 0;

    // Explanation of loop choice:
    /*
    * Using a while loop with priming read instead of do-while:
    * - The loop condition is checked BEFORE each iteration
    * - Requires initializing continueChoice to 'Y' to enter first iteration
    * - Provides more explicit control over loop entry
    * - Avoids potential issues with uninitialized variables
    * - Better demonstrates the concept of loop control variables
    * 
    * Comparison to original do-while:
    * - Do-while executes body first, then checks condition
    * - While loop checks condition first, then executes body
    * - Both can achieve same functionality with proper setup
    * - While loop makes the continuation condition more visible
    */

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
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
            std::cout << "Invalid input. Please enter 1, 2, or 3: ";
            std::cin >> choice;
        }

        double inputValue, convertedValue;
        std::string inputUnit, outputUnit;

        // Get appropriate input prompt based on conversion type
        switch (choice) {
            case 1: // Length conversion
                std::cout << "Enter the distance in kilometers: ";
                inputUnit = "kilometers";
                outputUnit = "miles";
                break;
            case 2: // Weight conversion
                std::cout << "Enter the weight in kilograms: ";
                inputUnit = "kilograms";
                outputUnit = "pounds";
                break;
            case 3: // Time conversion
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
            case 1: convertedValue = inputValue * 0.621371; break; // km to miles
            case 2: convertedValue = inputValue * 2.20462; break; // kg to lbs
            case 3: convertedValue = inputValue * 60; break;      // hours to mins
        }

        // Display formatted result
        std::cout << "Converted " << inputUnit << ": " << std::fixed;
        if (choice == 1 || choice == 2) {
            std::cout << std::setprecision(2) << convertedValue; // 2 decimal places for length/weight
        } else {
            std::cout << std::setprecision(0) << convertedValue; // whole numbers for time
        }
        std::cout << " " << outputUnit << std::endl;

        conversionCount++; // Track total conversions

        // Prompt for continuation
        std::cout << "\nDo you want to perform another conversion? (y/n): ";
        std::cin >> continueChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
    }

    // Final output showing total conversions
    std::cout << "\nYou performed " << conversionCount << " conversion" 
              << (conversionCount != 1 ? "s" : "") << ".\n";

    return 0;
}