#include <iostream>
#include <string>
using namespace std;

int main() {
    string productNames[] = {"Laptop", "Phone", "Tablet", "Monitor", "Keyboard", "Mouse", "Headphones"};
    double productPrices[] = {99.99, 49.50, 12.75, 150.00, 29.99, 75.25, 10.50};
    int size = 7; // Number of products
    
    for (int i = 0; i < 3; i++) { // Only first 3 iterations as per example
        cout << "Product: " << productNames[i] << ", Price: " << productPrices[i] 
             << " | Adjacent Product: " << productNames[i+1] << ", Price: " << productPrices[i+1] << endl;
    }
    
    return 0;
}