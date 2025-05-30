#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    double kilometers, miles;
    
    // Prompt user for input
    std::cout << "Enter the distance in kilometers: ";
    std::cin >> kilometers;
    
    // Convert kilometers to miles
    miles = kilometers * 0.621371;
    
    // Display the result with 2 decimal places
    std::cout << "Converted distance: " << std::fixed << std::setprecision(2) << miles << " miles\n";
    
    return 0;
}

