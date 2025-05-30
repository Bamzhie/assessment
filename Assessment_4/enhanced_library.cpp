#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 5;

int main() {
    string bookTitles[MAX_BOOKS];
    string bookAuthors[MAX_BOOKS];
    string bookGenres[MAX_BOOKS];
    int bookCount = 0;
    char choice;
    
    cout << "Library Management System" << endl;
    cout << "------------------------" << endl;
    
    do {
        cout << "\nMenu:" << endl;
        cout << "a. Add a new book" << endl;
        cout << "b. View all books" << endl;
        cout << "y. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;
        
        // Clear input buffer
        cin.ignore();
        
        switch(choice) {
            case 'a':
            case 'A':
                if (bookCount >= MAX_BOOKS) {
                    cout << "\nLibrary is full! Cannot add more books." << endl;
                    break;
                }
                
                cout << "\nEnter the book's title: ";
                getline(cin, bookTitles[bookCount]);
                
                cout << "Enter the author's name: ";
                getline(cin, bookAuthors[bookCount]);
                
                cout << "Enter the book's genre: ";
                getline(cin, bookGenres[bookCount]);
                
                cout << "\nBook added successfully!" << endl;
                bookCount++;
                break;
                
            case 'b':
            case 'B':
                if (bookCount == 0) {
                    cout << "\nNo books in the library yet." << endl;
                } else {
                    cout << "\nBooks in the Library:" << endl;
                    for (int i = 0; i < bookCount; i++) {
                        cout << i+1 << ". Title: " << bookTitles[i] 
                             << ", Author: " << bookAuthors[i] 
                             << ", Genre: " << bookGenres[i] << endl;
                    }
                }
                break;
                
            case 'y':
            case 'Y':
                cout << "Exiting program..." << endl;
                break;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 'y' && choice != 'Y');
    
    return 0;
}