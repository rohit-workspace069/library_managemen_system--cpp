#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class Book
{
private:
    string isbn, title, author, edition, publication;
    // private Data members.

public:
    void setIsbn(string a) { isbn = a; }
    void setTitle(string b) { title = b; }
    void setAuthor(string c) { author = c; }
    void setEdition(string d) { edition = d; }
    void setPublication(string e) { publication = e; }
    // setters
    string getIsbn() { return isbn; }
    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getEdition() { return edition; }
    string getPublication() { return publication; }
    // getters
};

void addBook(int counter);
void deleteBook(int counter);
void editBook(int counter);
void searchBook(int counter);
void viewAllBook(int counter);
void quit();

int counter = 0;

void increament(int a)
{
    a++;
    counter = a;
}

void decrement(int a)
{
    a--;
    counter = a;
}

Book books[10];

int main()
{
    string choice;
    system("CLS");
    cout << "LIBRARY MANAGEMENT SYSTEM\n\n";
    cout << "[1]ADD BOOK\n";
    cout << "[2]DELETE BOOK\n";
    cout << "[3]EDIT BOOK\n";
    cout << "[4]SEARCH BOOK\n";
    cout << "[5]VIEW ALL BOOK\n";
    cout << "[6]QUIT\n\n";

    cout << "ENTER CHOICE: ";
    getline(cin, choice);
    system("CLS");

    if (choice == "1")
    {
        addBook(counter);
    }
    else if (choice == "2")
    {
        deleteBook(counter);
    }
    else if (choice == "3")
    {
        editBook(counter);
    }
    else if (choice == "4")
    {
        searchBook(counter);
    }
    else if (choice == "5")
    {
        viewAllBook(counter);
    }
    else if (choice == "6")
    {
        quit();
    }
    else
    {
        main();
    }

    getch();
    return 0;
}

void addBook(int counter)
{
    string isbn, title, author, edition, publication;
    cout << "ADD BOOK\n\n";
    if (counter < 10)
    {
        cout << "Enter ISBN: ";
        getline(cin, isbn);
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);
        cout << "Enter Edition: ";
        getline(cin, edition);
        cout << "Enter Publication: ";
        getline(cin, publication);

        books[counter].setIsbn(isbn);
        books[counter].setTitle(title);
        books[counter].setAuthor(author);
        books[counter].setEdition(edition);
        books[counter].setPublication(publication);
        increament(counter);
        cout << "\nBOOK ADDED SUCCESSFULLY!\n\nPress any key to continue . . .";
        getch();
        main();
    }
    else
    {
        cout << "YOU HAVE REACHED THE MAXIMUM NUMBER OF BOOKS TO BE ADDED!\n\nPress any key to continue . . .";
        getch();
        main();
    }
}

void deleteBook(int counter)
{
    string isbn;
    int choice;
    cout << "DELETE BOOK\n\n";
    if (counter == 0)
    {
        cout << "THERE IS NO BOOK TO DELETE!\n\nPress any key to continue . . .";
        getch();
        main();
    }
    cout << "Enter ISBN: ";
    getline(cin, isbn);

    for (int i = 0; i < counter; i++)
    {
        if (books[i].getIsbn() == isbn)
        {
            cout << "\nBook Found\n\n";
            cout << "Do you want to delete?\n[1]Yes\n[2]No\n\nEnter Choice: ";
            cin >> choice;
            if (choice == 1)
            {
                books[i].setIsbn("");
                books[i].setTitle("");
                books[i].setAuthor("");
                books[i].setEdition("");
                books[i].setPublication("");
                for (int a = i; a < counter; a++)
                {
                    books[a] = books[a + 1];
                }
                books[9].setIsbn("");
                books[9].setTitle("");
                books[9].setAuthor("");
                books[9].setEdition("");
                books[9].setPublication("");
                decrement(counter);
                cout << "\n BOOK SUCCESSFULLY DELETED!\n\nPress any key to continue  . . .";
                getch();
                main();
            }
            else
            {
                main();
            }
        }
    }
    cout << "\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
    getch();
    main();
}

void editBook(int counter)
{
    system("CLS");
    string editIsbn, choice;
    string isbn, title, author, edition, publication;
    cout << "\nEDIT BOOK\n\n";
    if (counter == 0)
    {
        cout << "THERE IS NO BOOK TO EDIT!\n\nPress any key to continue . . .";
        getch();
        main();
    }
    cout << "Enter ISBN: ";
    getline(cin, editIsbn);
    for (int i = 0; i < counter; i++)
    {
        if (books[i].getIsbn() == editIsbn)
        {
            cout << "\nBOOK FOUND!\n\n";
            cout << "ISBN: " << books[i].getIsbn() << endl;
            cout << "TITLE: " << books[i].getTitle() << endl;
            cout << "AUTHOR: " << books[i].getAuthor() << endl;
            cout << "EDITION: " << books[i].getEdition() << endl;
            cout << "PUBLICATION: " << books[i].getPublication() << endl;
            cout << "\nDo you want to edit?\n[1]Yes\n[2]No\n\nEnter choice: ";
            getline(cin, choice);
            if (choice == "1")
            {
                cout << "Enter ISBN: ";
                getline(cin, isbn);
                cout << "Enter Title: ";
                getline(cin, title);
                cout << "Enter Author: ";
                getline(cin, author);
                cout << "Enter Edition: ";
                getline(cin, edition);
                cout << "Enter Publication: ";
                getline(cin, publication);
                books[i].setIsbn(isbn);
                books[i].setTitle(title);
                books[i].setAuthor(author);
                books[i].setEdition(edition);
                books[i].setPublication(publication);
                cout << "\nBOOK EDITED SUCCESSFULLY!\n\nPress any key to continue . . .";
                getch();
                editBook(counter);
            }
            else
            {
                main();
            }
        }
    }
    cout << "\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
    getch();
    main();
}

void searchBook(int counter)
{
    string isbn;
    int choice;
    bool print = false;
    cout << "SEARCH BOOK\n\n";
    if (counter == 0)
    {
        cout << "THERE IS NO BOOK TO SEARCH!\n\nPress any key to continue . . .";
        getch();
        main();
    }
    cout << "Enter ISBN: ";
    getline(cin, isbn);
    for (int i = 0; i < counter; i++)
    {
        // finding a match using for loop
        if (books[i].getIsbn() == isbn)
        {
            cout << "\nBOOK FOUND!\n\n";
            cout << "ISBN: " << books[i].getIsbn() << endl;
            cout << "TITLE: " << books[i].getTitle() << endl;
            cout << "AUTHOR: " << books[i].getAuthor() << endl;
            cout << "EDITION: " << books[i].getEdition() << endl;
            cout << "PUBLICATION: " << books[i].getPublication() << endl;
            print = true;
        }
    }
    if (print)
    {
        cout << "\n\nPress any key to continue . . .";
        getch();
        main();
    }
    else
    {
        cout << "\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
        getch();
        main();
    }
}

void viewAllBook(int counter)
{
    // iterating all the values on the library using book array
    cout << "VIEW ALL BOOKS\n\n";
    for (int i = 0; i < counter; i++)
    {
        cout << "BOOK DETAILS\n\n";
        cout << "ISBN: " << books[i].getIsbn() << endl;
        cout << "TITLE: " << books[i].getTitle() << endl;
        cout << "AUTHOR: " << books[i].getAuthor() << endl;
        cout << "EDITION: " << books[i].getEdition() << endl;
        cout << "PUBLICATION: " << books[i].getPublication() << endl
             << endl;
    }
    cout << "Press any key to continue . . .";
    getch();
    main();
}

void quit()
{
    exit(1);
}