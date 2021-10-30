#include <iostream>
#include <fstream>
#include <conio.h>

// This Program has been modified by :
// Maulana Luthfi Nasution (001202100065)
// Class 2 - CIT 2021

using namespace std;

struct book {
    int bCode, year, pages;
    int rent = 3000;
    string title, author;
}book[10];

struct borrowbook {
    int borrowbook, days, bdays, rdays, tdays, cb, tpays;
    int rent = 3000;
    char status;
}borrowbook[10];

int main()
{
    int menu, main, s, d, bb, br, cb, b, r, pinCode, dateReturn, search, ld, tp, index;
    string username, password, inUsername, inPassword, registerUsername, registerPassword, confirm;
    char ch;
    int data = 6;

    // book data
    book[0].bCode = 101;
    book[0].year = 2009;
    book[0].pages = 928;
    book[0].title = "1Q84";
    book[0].author = "Haruki Murakami";

    book[1].bCode = 102;
    book[1].year = 1920;
    book[1].pages = 730;
    book[1].title = "Ulysses";
    book[1].author = "James Joyce";

    book[2].bCode = 103;
    book[2].year = 2021;
    book[2].pages = 310;
    book[2].title = "Wonder";
    book[2].author = "R. J. Palacio";

    book[3].bCode = 104;
    book[3].year = 1956;
    book[3].pages = 178;
    book[3].title = "Night";
    book[3].author = "Elie Wiesel";

    book[4].bCode = 105;
    book[4].year = 1998;
    book[4].pages = 195;
    book[4].title = "Saman";
    book[4].author = "Ayu Utami";

    book[5].bCode = 106;
    book[5].year = 2007;
    book[5].pages = 290;
    book[5].title = "Edensor";
    book[5].author = "Andrea Hirata";

    book[6].bCode = 107;
    book[6].year = 2020;
    book[6].pages = 376;
    book[6].title = "Nebula";
    book[6].author = "Tere Liye";

    StartMenu:
    cout << " -------- Welcome To Dubstic Library App -------- " << endl;
    cout << "\n 1. Register As A New Member \n";
    cout << " 2. Login As A Member \n";
    cout << " 3. Exit The App \n";
    cout << " Choose menu : ";
    cin >> menu;
    system("cls");

    if (menu == 1)
    {
    Register:
        cout << "----- Register Menu -----" << endl;
        cout << "\nNew Username \t\t : ";
        cin >> registerUsername;
        cout << "New Password \t\t : ";
        ch = _getch();
        while (ch != 13)
        {
            registerPassword.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        cout << endl;
        ofstream n(registerUsername + ".txt");
        if (!n.is_open())
        {
            return 0;
        }
        n << registerUsername;
        n << '\n';
        n << registerPassword;
        n.close();
        cout << "\n\nYour registration was successful" << endl;
        system("pause");
        system("cls");
        goto StartMenu;
    }
    else if (menu == 2)
    {
        ifstream l(registerUsername + ".txt");
        if (!l.is_open())
        {
            return 0;
        }
        getline(l, username, '\n');
        getline(l, password, '\n');
        l.close();
        while (true)
        {
            cout << "----- Login Menu -----" << endl;
            cout << "Username \t\t : ";
            cin >> inUsername;
            cout << "Password \t\t : ";
            ch = _getch();
            while (ch != 13)
            {
                inPassword.push_back(ch);
                cout << '*';
                ch = _getch();
            }
            cout << endl;

            if (inUsername == username && inPassword == password)
            {
                cout << "\nLogin successful!\n";
                system("pause");
                system("cls");
                goto MainMenu;
                break;
            }
            cout << "\nIncorrect Username or Password. Please try again!\n";
            system("pause");
            system("cls");
            goto StartMenu;
        }
    }
    else
    {
        return 1;
    }

MainMenu:
    cout << "------ Welcome " << username << ", to Dubstic Library! ------\n\n";
    cout << "1. Search a book\n";
    cout << "2. Borrow a book\n";
    cout << "3. Return a book\n";
    cout << "4. Logout\n";
    cout << "Enter menu : ";
    cin >> main;
    system("cls");

    if (main == 1)
    {
        SearchBook :
        cout << "Search Book Menu\n\n";

        cout << "List of available books in library\n";
        
        cout << "----------------------------\n";
        cout << "No\tBook Code\tTitle Book\n";
        cout << "----------------------------\n";
        for(data=0;data<=6;data++) {
            cout << data+1 << "\t" << book[data].bCode << "\t\t" << book[data].title << endl;
        }

        
        cout << "\nEnter book code to see the book's details : ";
        cin >> search;
        cout << "--------------------------------------------------------------------" << endl;

        for(s=0;s<=data;s++) {
        
            if(search == book[s].bCode) {
                cout << "Book Code : " << book[s].bCode << endl;
                cout << "Title : " << book[s].title << endl;
                cout << "Author : " << book[s].author << endl;
                cout << "Pages : " << book[s].pages << endl;
                cout << "Year : " << book[s].year << endl;
                system("pause");
            }
        }


        cout << "\n\nDo you want to search another book (y/n)? ";
        cin >> confirm; 

        if(confirm == "y") {
            goto SearchBook;
            system("cls");
        } else {
            goto MainMenu;
            system("cls");
        }

        
    }
    else if (main == 2)
    {
        BorrowProcess:
        cout << "Borrow Book Menu\n\n";
        cout << "Enter borrow code : "; cin >> borrowbook[bb].borrowbook;
        cout << "Enter book code : "; cin >> borrowbook[bb].cb;

        for(s=0;s<=data;s++) {
            if(borrowbook[bb].cb == book[s].bCode) {
                cout << "Book Code : " << book[s].bCode << endl;
                cout << "Title : " << book[s].title << endl;
                cout << "Author : " << book[s].author << endl;
                cout << "Pages : " << book[s].pages << endl;
                cout << "Year : " << book[s].year << endl;
            }
        }

        cout << "Borrow date (DDMMYYYY) : "; cin >> borrowbook[bb].bdays;
        cout << "Borrow return (DDMMYYYY) : "; cin >> borrowbook[bb].rdays;
        borrowbook[bb].tdays = (borrowbook[bb].rdays - borrowbook[bb].bdays)/1000000;
        cout << "Borrow book : " << borrowbook[bb].tdays << " days\n";
        borrowbook[bb].tpays = borrowbook[bb].tdays * borrowbook[bb].rent;
        cout << "Total Payment : Rp " << borrowbook[bb].tpays << endl;
        cout << " Change  book status to in borrow (y) ?";cin>>borrowbook[bb].status;

        cout << "\n\nDo you want to borrow another book (y/n)? ";
        cin >> confirm; 

        if(confirm == "y") {
            goto BorrowProcess;
            system("cls");
        } else {
            goto MainMenu;
            system("cls");
        }
        
    }
    else if (main == 3)
    {
        cout << "Return Book Menu\n\n";

        cout << "Enter your borrowing code : ";cin >> pinCode;

        for(r=0;r<=data;r++) {
            if(borrowbook[r].borrowbook == pinCode) {
                if(book[r].bCode == borrowbook[r].cb) {
                    cout << "title : " << book[r].title << endl;
                }
                cout << "Borrow date : " << borrowbook[r].bdays << endl;
                cout << "Return date (DDMMYYYY) : "; cin >> dateReturn;

                //ld = (dateReturn - borrowbook[r].rdays)/1000000;

                if(borrowbook[r].rdays >= dateReturn) {
                    cout << "You return book on time at\n\n " << borrowbook[r].rdays;
                } else {
                    ld = (dateReturn - borrowbook[r].rdays)/1000000; 
                    cout << "You late " << ld << " days to return book" << endl;
                    tp = borrowbook[bb].tpays + (ld * 1000);
                    cout << "Total payment : Rp " << tp << endl;
                }

                cout << "Status : " << borrowbook[r].status;
                if(borrowbook[r].status == 'y') {
                    cout << "(Borrowed)" << endl;
                } else {
                    cout << "(Returned)" << endl;
                }
                cout <<endl;

                cout << "Do you want to return this book? (y/n) : "; cin >> confirm;

                if(confirm == "y") {
                    cout << "Change Status (n) : "; cin >> borrowbook[r].status;
                    cout << "\n\n Save data succesfully!\n";
                    system("pause");
                    system("cls");
                    goto MainMenu;
                } else {
                    goto MainMenu;
                }
            }
        }
    }

    else
    {
        cout << "Thanks you for using our library app !\n";
        system("pause");
        system("cls");
        goto StartMenu;
    }
}