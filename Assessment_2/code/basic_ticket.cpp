#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Default values
    char movieType = 'A'; // 'A' for Action
    char ticketCategory = 'R'; // 'R' for Regular
    double ticketPrice = 0.0;
    
    // Determine ticket price based on movie type and category
    switch(movieType) {
        case 'A': // Action
            switch(ticketCategory) {
                case 'R': // Regular
                    ticketPrice = 10.00;
                    break;
                case 'P': // Premium
                    ticketPrice = 15.00;
                    break;
            }
            break;
        case 'C': // Comedy
            switch(ticketCategory) {
                case 'R':
                    ticketPrice = 8.00;
                    break;
                case 'P':
                    ticketPrice = 12.00;
                    break;
            }
            break;
        case 'D': // Drama
            switch(ticketCategory) {
                case 'R':
                    ticketPrice = 7.00;
                    break;
                case 'P':
                    ticketPrice = 10.00;
                    break;
            }
            break;
        default:
            cout << "Invalid movie type selected." << endl;
            return 1;
    }
    
    // Display the default selections and price
    cout << fixed << setprecision(2);
    cout << "Movie Type: ";
    switch(movieType) {
        case 'A': cout << "Action"; break;
        case 'C': cout << "Comedy"; break;
        case 'D': cout << "Drama"; break;
    }
    cout << endl;
    
    cout << "Ticket Category: ";
    switch(ticketCategory) {
        case 'R': cout << "Regular"; break;
        case 'P': cout << "Premium"; break;
    }
    cout << endl;
    
    cout << "Total Ticket Price: £" << ticketPrice << endl;
    
    return 0;
}