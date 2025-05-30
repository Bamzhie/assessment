#include <iostream>
#include <iomanip>
using namespace std;

void displayMenu();
void bookTickets();
void viewPrices();

int main() {
    int choice;
    
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                bookTickets();
                break;
            case 2:
                viewPrices();
                break;
            case 3:
                cout << "Thank you for using the Movie Ticket Booking System!\n";
                break;
            default:
                cout << "Invalid choice! Please enter 1, 2, or 3.\n";
                cin.clear();
                cin.ignore(100, '\n');
        }
    } while (choice != 3);
    
    return 0;
}

void displayMenu() {
    cout << "\n--- Movie Ticket Booking System ---\n";
    cout << "1. Book Tickets\n";
    cout << "2. View Ticket Prices\n";
    cout << "3. Exit\n";
}

void viewPrices() {
    char backOption;
    do {
        cout << "\n--- Ticket Prices ---\n";
        cout << "Action: £10 (Regular), £15 (Premium)\n";
        cout << "Comedy: £8 (Regular), £12 (Premium)\n";
        cout << "Drama: £7 (Regular), £10 (Premium)\n";
        cout << "\nPress 'B' to go back to menu or any other key to view prices again: ";
        cin >> backOption;
        backOption = toupper(backOption);
    } while (backOption != 'B');
}

void bookTickets() {
    char movieType, ticketCategory, wantSnacks, backOption;
    int numTickets;
    double ticketPrice = 0.0, totalCost = 0.0, discount = 0.0, snacksCost = 0.0, finalTotal = 0.0;

    cout << "\nEnter 'B' at any time to go back to menu\n";

    // Get movie type
    while (true) {
        cout << "Select a movie type ('A' for Action, 'C' for Comedy, 'D' for Drama or 'B' to go back): ";
        cin >> movieType;
        movieType = toupper(movieType);
        if (movieType == 'B') return;
        if (movieType == 'A' || movieType == 'C' || movieType == 'D') break;
        cout << "Invalid input! Please enter A, C, D, or B to go back.\n";
        cin.clear();
        cin.ignore(100, '\n');
    }

    // Get ticket category
    while (true) {
        cout << "Select ticket category ('R' for Regular, 'P' for Premium or 'B' to go back): ";
        cin >> ticketCategory;
        ticketCategory = toupper(ticketCategory);
        if (ticketCategory == 'B') return;
        if (ticketCategory == 'R' || ticketCategory == 'P') break;
        cout << "Invalid input! Please enter R, P, or B to go back.\n";
        cin.clear();
        cin.ignore(100, '\n');
    }

    // Get number of tickets
    while (true) {
        cout << "Enter the number of tickets (or 0 to go back): ";
        if (cin >> numTickets) {
            if (numTickets == 0) return;
            if (numTickets > 0) break;
        }
        cout << "Invalid input! Please enter a positive integer or 0 to go back.\n";
        cin.clear();
        cin.ignore(100, '\n');
    }

    // Get snacks choice
    while (true) {
        cout << "Do you want snacks (y/n) or 'B' to go back: ";
        cin >> wantSnacks;
        wantSnacks = toupper(wantSnacks);
        if (wantSnacks == 'B') return;
        if (wantSnacks == 'Y' || wantSnacks == 'N') break;
        cout << "Invalid input! Please enter y, n, or B to go back.\n";
        cin.clear();
        cin.ignore(100, '\n');
    }

    // Calculate ticket price
    switch(movieType) {
        case 'A':
            ticketPrice = (ticketCategory == 'R') ? 10.00 : 15.00;
            break;
        case 'C':
            ticketPrice = (ticketCategory == 'R') ? 8.00 : 12.00;
            break;
        case 'D':
            ticketPrice = (ticketCategory == 'R') ? 7.00 : 10.00;
            break;
    }

    // Calculate costs
    totalCost = ticketPrice * numTickets;
    discount = (numTickets > 5) ? totalCost * 0.10 : 0.0;
    snacksCost = (wantSnacks == 'Y') ? 5.00 * numTickets : 0.0;
    finalTotal = totalCost - discount + snacksCost;

    // Display booking summary
    cout << fixed << setprecision(2);
    cout << "\n--- Booking Summary ---\n";
    cout << "Movie Type: ";
    switch(movieType) {
        case 'A': cout << "Action"; break;
        case 'C': cout << "Comedy"; break;
        case 'D': cout << "Drama"; break;
    }
    cout << "\nTicket Category: " << ((ticketCategory == 'R') ? "Regular" : "Premium");
    cout << "\nNumber of Tickets: " << numTickets;
    cout << "\nTotal Cost Before Discount: £" << totalCost;
    if (discount > 0) cout << "\nBulk Discount: £" << discount;
    if (snacksCost > 0) cout << "\nSnacks Cost: £" << snacksCost;
    cout << "\nFinal Total Cost: £" << finalTotal << endl;

    cout << "\nPress any key to return to menu...";
    cin.ignore();
    cin.get();
}