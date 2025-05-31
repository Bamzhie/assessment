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

void selectionSort(string names[], double prices[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (names[j] < names[minIndex]) {
                minIndex = j;
            }
        }
        // Swap names
        swap(names[i], names[minIndex]);
        // Swap corresponding prices
        swap(prices[i], prices[minIndex]);
    }
}

int main() {
    string productNames[] = {"Laptop", "Phone", "Tablet", "Monitor", "Keyboard", "Mouse", "Headphones"};
    double productPrices[] = {99.99, 49.50, 12.75, 150.00, 29.99, 75.25, 10.50};
    int size = sizeof(productPrices) / sizeof(productPrices[0]);

    cout << "Before Sorting:\n";
    printProducts(productNames, productPrices, size);

    selectionSort(productNames, productPrices, size);

    cout << "After Alphabetical Sorting:\n";
    printProducts(productNames, productPrices, size);

    return 0;
}