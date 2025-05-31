#include <iostream>
#include <string>
using namespace std;

int main() {
    string title, author, genre;
    char choice;
    
    cout << "Library Management System" << endl;
    cout << "------------------------" << endl;
    
    do {
        cout << "\nMenu:" << endl;
        cout << "a. Add a new book" << endl;
        cout << "q. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        // Clear input buffer
        cin.ignore();
        
        switch(choice) {
            case 'a':
            case 'A':
                cout << "\nEnter the book's title: ";
                getline(cin, title);
                
                cout << "Enter the author's name: ";
                getline(cin, author);
                
                cout << "Enter the book's genre: ";
                getline(cin, genre);
                
                cout << "\nBook added successfully!" << endl;
                cout << "Book Details:" << endl;
                cout << "Title: " << title << endl;
                cout << "Author: " << author << endl;
                cout << "Genre: " << genre << endl;
                break;
                
            case 'q':
            case 'Q':
                cout << "Exiting program..." << endl;
                break;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 'q' && choice != 'Q');
    
    return 0;
}