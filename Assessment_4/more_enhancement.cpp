#include <iostream>
#include <string>
#include <algorithm>
#include <memory> // For smart pointers
using namespace std;

const int MAX_BOOKS = 5;

struct Book {
    string title;
    string author;
    string genre;
};

// Function to convert string to lowercase
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    unique_ptr<Book[]> books(new Book[MAX_BOOKS]); // Smart pointer to array of Books
    int bookCount = 0;
    char choice;
    
    cout << "Library Management System (Pointer Enhanced)" << endl;
    cout << "------------------------------------------" << endl;
    
    do {
        cout << "\nMenu:" << endl;
        cout << "a. Add a new book" << endl;
        cout << "b. View all books" << endl;
        cout << "c. Search for a book" << endl;
        cout << "y. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;
        
        cin.ignore();
        
        switch(tolower(choice)) {
            case 'a': {
                if (bookCount >= MAX_BOOKS) {
                    cout << "\nLibrary is full! Cannot add more books." << endl;
                    break;
                }
                
                // Using pointer to access current book
                Book* currentBook = &books[bookCount];
                
                cout << "\nEnter the book's title: ";
                getline(cin, currentBook->title);
                
                cout << "Enter the author's name: ";
                getline(cin, currentBook->author);
                
                cout << "Enter the book's genre: ";
                getline(cin, currentBook->genre);
                
                cout << "\nBook added successfully!" << endl;
                bookCount++;
                break;
            }
                
            case 'b': {
                if (bookCount == 0) {
                    cout << "\nNo books in the library yet." << endl;
                    break;
                }
                
                cout << "\nBooks in the Library:" << endl;
                // Using pointer arithmetic to traverse array
                Book* bookPtr = books.get();
                for (int i = 0; i < bookCount; i++, bookPtr++) {
                    cout << i+1 << ". Title: " << bookPtr->title 
                         << ", Author: " << bookPtr->author 
                         << ", Genre: " << bookPtr->genre << endl;
                }
                break;
            }
                
            case 'c': {
                if (bookCount == 0) {
                    cout << "\nNo books in the library to search." << endl;
                    break;
                }
                
                string searchTitle;
                cout << "\nEnter the book title to search: ";
                getline(cin, searchTitle);
                
                bool found = false;
                Book* bookPtr = books.get();
                for (int i = 0; i < bookCount; i++, bookPtr++) {
                    if (toLower(bookPtr->title) == toLower(searchTitle)) {
                        cout << "\nBook found!" << endl;
                        cout << "Title: " << bookPtr->title << endl;
                        cout << "Author: " << bookPtr->author << endl;
                        cout << "Genre: " << bookPtr->genre << endl;
                        found = true;
                        break;
                    }
                }
                
                if (!found) {
                    cout << "\nBook not found." << endl;
                }
                break;
            }
                
            case 'y':
                cout << "Exiting program..." << endl;
                break;
                
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while(tolower(choice) != 'y');
    
    return 0;
}