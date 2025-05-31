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

int main() {
    string productNames[] = {"Laptop", "Phone", "Tablet", "Monitor", "Keyboard", "Mouse", "Headphones"};
    double productPrices[] = {99.99, 49.50, 12.75, 150.00, 29.99, 75.25, 10.50};
    int size = 7;

    cout << "Before Sorting: ";
    printProducts(productNames, productPrices, size);

    // Find the index of the maximum price
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (productPrices[i] > productPrices[maxIndex]) {
            maxIndex = i;
        }
    }

    // Bubble the max element to the end
    for (int i = maxIndex; i < size - 1; i++) {
        swap(productPrices[i], productPrices[i + 1]);
        swap(productNames[i], productNames[i + 1]);
    }

    cout << "After Single Pass: ";
    printProducts(productNames, productPrices, size);

    return 0;
}