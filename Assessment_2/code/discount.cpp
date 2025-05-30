#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char movieType, ticketCategory, wantSnacks;
    int numTickets;
    double ticketPrice = 0.0, totalCost = 0.0, discount = 0.0, snacksCost = 0.0, finalTotal = 0.0;

    // Get movie type
    while (true) {
        cout << "Select a movie type ('A' for Action, 'C' for Comedy, 'D' for Drama): ";
        cin >> movieType;
        movieType = toupper(movieType);
        if (movieType == 'A' || movieType == 'C' || movieType == 'D') break;
        cout << "Invalid input! Please enter A, C, or D.\n";
        cin.clear();
        cin.ignore(100, '\n');
    }

    // Get ticket category
    while (true) {
        cout << "Select ticket category ('R' for Regular, 'P' for Premium): ";
        cin >> ticketCategory;
        ticketCategory = toupper(ticketCategory);
        if (ticketCategory == 'R' || ticketCategory == 'P') break;
        cout << "Invalid input! Please enter R or P.\n";
        cin.clear();
        cin.ignore(100, '\n');
    }

    // Get number of tickets
    while (true) {
        cout << "Enter the number of tickets: ";
        if (cin >> numTickets && numTickets > 0) break;
        cout << "Invalid input! Please enter a positive integer.\n";
        cin.clear();
        cin.ignore(100, '\n');
    }

    // Get snacks choice
    while (true) {
        cout << "Do you want snacks (y/n): ";
        cin >> wantSnacks;
        wantSnacks = toupper(wantSnacks);
        if (wantSnacks == 'Y' || wantSnacks == 'N') break;
        cout << "Invalid input! Please enter y or n.\n";
        cin.clear();
        cin.ignore(100, '\n');
    }

    // Calculate ticket price using switch
    switch(movieType) {
        case 'A':
            switch(ticketCategory) {
                case 'R': ticketPrice = 10.00; break;
                case 'P': ticketPrice = 15.00; break;
            }
            break;
        case 'C':
            switch(ticketCategory) {
                case 'R': ticketPrice = 8.00; break;
                case 'P': ticketPrice = 12.00; break;
            }
            break;
        case 'D':
            switch(ticketCategory) {
                case 'R': ticketPrice = 7.00; break;
                case 'P': ticketPrice = 10.00; break;
            }
            break;
    }

    // Calculate costs
    totalCost = ticketPrice * numTickets;
    
    // Apply 10% discount if more than 5 tickets
    if (numTickets > 5) {
        discount = totalCost * 0.10;
    }
    
    // Calculate snacks cost
    if (wantSnacks == 'Y') {
        snacksCost = 5.00 * numTickets;
    }

    // Calculate final total
    finalTotal = totalCost - discount + snacksCost;

    // Display results
    cout << fixed << setprecision(2);
    cout << "\nMovie Type: ";
    switch(movieType) {
        case 'A': cout << "Action"; break;
        case 'C': cout << "Comedy"; break;
        case 'D': cout << "Drama"; break;
    }
    
    cout << "\nTicket Category: ";
    switch(ticketCategory) {
        case 'R': cout << "Regular"; break;
        case 'P': cout << "Premium"; break;
    }
    
    cout << "\nNumber of Tickets: " << numTickets;
    cout << "\nTotal Cost Before Discount: £" << totalCost;
    if (discount > 0) {
        cout << "\nBulk Discount: £" << discount;
    }
    if (wantSnacks == 'Y') {
        cout << "\nSnacks Cost: £" << snacksCost;
    }
    cout << "\nFinal Total Cost: £" << finalTotal << endl;

    return 0;
}