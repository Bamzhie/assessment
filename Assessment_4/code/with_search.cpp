#include <iostream>
#include <string>
#include <algorithm> // for transform
using namespace std;

const int MAX_BOOKS = 5;

// Function to convert string to lowercase for case-insensitive comparison
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

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
        cout << "c. Search for a book" << endl;
        cout << "y. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;
        
        // Clear input buffer
        cin.ignore();
        
        switch(tolower(choice)) {
            case 'a':
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
                
            case 'c':
                if (bookCount == 0) {
                    cout << "\nNo books in the library to search." << endl;
                    break;
                }
                
                {
                    string searchTitle;
                    cout << "\nEnter the book title to search: ";
                    getline(cin, searchTitle);
                    
                    bool found = false;
                    for (int i = 0; i < bookCount; i++) {
                        if (toLower(bookTitles[i]) == toLower(searchTitle)) {
                            cout << "\nBook found!" << endl;
                            cout << "Title: " << bookTitles[i] << endl;
                            cout << "Author: " << bookAuthors[i] << endl;
                            cout << "Genre: " << bookGenres[i] << endl;
                            found = true;
                            break;
                        }
                    }
                    
                    if (!found) {
                        cout << "\nBook not found." << endl;
                    }
                }
                break;
                
            case 'y':
                cout << "Exiting program..." << endl;
                break;
                
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while(tolower(choice) != 'y');
    
    return 0;
}