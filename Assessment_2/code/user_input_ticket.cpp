#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char movieType;
    char ticketCategory;
    int numTickets;
    double ticketPrice = 0.0;
    double totalCost = 0.0;

    // Get user input
    cout << "Select a movie type ('A' for Action, 'C' for Comedy, 'D' for Drama): ";
    cin >> movieType;
    
    cout << "Select ticket category ('R' for Regular, 'P' for Premium): ";
    cin >> ticketCategory;
    
    cout << "Enter the number of tickets: ";
    cin >> numTickets;

    // Calculate ticket price using switch statements
    switch(toupper(movieType)) {
        case 'A': // Action
            switch(toupper(ticketCategory)) {
                case 'R': ticketPrice = 10.00; break;
                case 'P': ticketPrice = 15.00; break;
                default: 
                    cout << "Invalid ticket category!" << endl;
                    return 1;
            }
            break;
        case 'C': // Comedy
            switch(toupper(ticketCategory)) {
                case 'R': ticketPrice = 8.00; break;
                case 'P': ticketPrice = 12.00; break;
                default: 
                    cout << "Invalid ticket category!" << endl;
                    return 1;
            }
            break;
        case 'D': // Drama
            switch(toupper(ticketCategory)) {
                case 'R': ticketPrice = 7.00; break;
                case 'P': ticketPrice = 10.00; break;
                default: 
                    cout << "Invalid ticket category!" << endl;
                    return 1;
            }
            break;
        default:
            cout << "Invalid movie type selected!" << endl;
            return 1;
    }

    // Calculate total cost
    totalCost = ticketPrice * numTickets;

    // Display all details
    cout << fixed << setprecision(2);
    cout << "\nMovie Type: ";
    switch(toupper(movieType)) {
        case 'A': cout << "Action"; break;
        case 'C': cout << "Comedy"; break;
        case 'D': cout << "Drama"; break;
    }
    
    cout << "\nTicket Category: ";
    switch(toupper(ticketCategory)) {
        case 'R': cout << "Regular"; break;
        case 'P': cout << "Premium"; break;
    }
    
    cout << "\nNumber of Tickets: " << numTickets;
    cout << "\nTotal Cost: £" << totalCost << endl;

    return 0;
}