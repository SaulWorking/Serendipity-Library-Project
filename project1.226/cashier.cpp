#include <iostream>
#include <string>
#include <iomanip>
#include "cashier.h"
#include "inventory.h"
using namespace std;



//calculates price of book and asks for a repeat if possible
int cashier(){

    const double salesTax = 0.06;
    double totalPrice, bookPrice;
    int bookQuantity, bookChosen{-1};
    string userDate, bookISBN, book;
    char userRepeat{' '};
    bool ISBNCheck = true;

    cout << '\n' << setw(20) << " " <<"Serenpidity Booksellers" << endl;
    cout << setw(25) << " " << "Cashier Module\n";




    cout << setw(15) << ' ' << "Date:"; 
        cin.ignore();
        getline(cin, userDate);


    cout << setw(15) << ' ' <<"ISBN:";
        getline(cin, bookISBN);


    bookChosen = ISBNLookup(bookISBN);

    if(qtyOnHand[bookChosen] <=0){
        cout << "No book " << bookTitle[bookChosen] << " in stock.\nExiting program...\n";
        return -1;
    }
    

    while(bookChosen == -1){
        cout << "Cannot locate ISBN.";
        cout << "\nDo you want to retry?(y/n)";
         cin >> userRepeat;

         if(userRepeat == 'y'){
            cout << "\nISBN: ";
            
            cin.ignore();
            getline(cin, bookISBN);
            bookChosen = ISBNLookup(bookISBN);
         }


    }

     if(bookChosen >=0){
    book = bookTitle[bookChosen];
    bookPrice = retail[bookChosen];
        cout << "book quantity? ";
        cin >> bookQuantity;

        while(bookQuantity <0){

            cout <<"\nQuanity cant be less than 0. Try again: ";
            cin >> bookQuantity;
        }

    }





    totalPrice = (bookPrice * bookQuantity);

    cout << "\n\nDate: " << userDate << "\n\n";
    cout  << left<< setw(5) << "Qty" << setw(20) << "ISBN" << setw(40) << "Title" << setw(10) << "Price"  << setw(3) << "Total"<< endl;


    for (int i =0; i<85; i++){
        cout << "_";
    }

    cout << '\n' << setw(4)  << left << fixed << setprecision(2) << bookQuantity << setw(20) << bookISBN << setw(40) << book  << " $" << setw(9) << bookPrice << "$"  << totalPrice << endl;
    cout << "\n\n\n";



    cout << setw(61)  << "\t\tSubtotal" << "$" << totalPrice << endl; 
    cout << setw(61)  << "\t\tTax" <<  "$" << totalPrice * salesTax << endl;
    cout << setw(61)  << "\t\tTotal" << "$" << totalPrice + (totalPrice * salesTax) << endl;

    cout << "\n\n" << setw(15) << " " << "Thank you for shopping at Serendipity\n\n" << endl;
    cout << "\n" << setw(15) << " " << "Do you have another transaction? (Y/N): ";
        cin >> userRepeat;

        if(userRepeat == 'y' || userRepeat == 'Y'){
            cin.ignore();
            cashier();
            }else{
                    cout << '\n' << setw(15) << ' ' << "Goodbye!";
                 }

        return 0;


}

int ISBNLookup(string ISBN){

    for(int i =0; i<20; i++){

        if(isbn[i] == ISBN){
        
            return i;
        }
        


    }

    return -1;
}