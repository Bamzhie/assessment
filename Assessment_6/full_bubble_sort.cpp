#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void printProducts(string names[], double prices[], int size) {
    for (int i = 0; i < size; i++) {
        cout << names[i] << " - " << fixed << setprecision(2) << prices[i];
        if (i != size - 1) cout << ", ";
    }
    cout << endl;
}

void bubbleSort(string names[], double prices[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (prices[j] > prices[j + 1]) {
                // Swap prices
                swap(prices[j], prices[j + 1]);
                // Swap corresponding names
                swap(names[j], names[j + 1]);
            }
        }
    }
}

int main() {
    string productNames[] = {"Laptop", "Phone", "Tablet", "Monitor", "Keyboard", "Mouse", "Headphones"};
    double productPrices[] = {99.99, 49.50, 12.75, 150.00, 29.99, 75.25, 10.50};
    int size = sizeof(productPrices) / sizeof(productPrices[0]);

    cout << "Before Sorting:\n";
    printProducts(productNames, productPrices, size);

    bubbleSort(productNames, productPrices, size);

    cout << "After Sorting:\n";
    printProducts(productNames, productPrices, size);

    return 0;
}