#include <iostream>
#include <string>
#include <iomanip>
#include "cashier.h"
using namespace std;



//calculates price of book and asks for a repeat if possible
void cashier(){

    const double salesTax = 0.06;
    double totalPrice, bookPrice;
    int bookQuantity;
    string userDate, bookISBN, bookTitle;
    char userRepeat{' '};

    cout << '\n' << setw(20) << " " <<"Serenpidity Booksellers" << endl;
    cout << setw(25) << " " << "Cashier Module\n";


    cout << setw(15) << " " << "Date:"; 
        cin.ignore();
        getline(cin, userDate);

    cout << setw(15) << " " << "Quantity:" ;
        cin >> bookQuantity;
        cin.ignore();


    cout << setw(15) << " " <<"ISBN:";
        getline(cin, bookISBN);


    cout << setw(15) << " " <<"Title:";
        getline(cin, bookTitle);    

    cout << setw(15) << " " <<"Price:";
        cin >> bookPrice;


    totalPrice = (bookPrice * bookQuantity);

    cout << "\n\nDate: " << userDate << "\n\n";
    cout  << left<< setw(5) << "Qty" << setw(20) << "ISBN" << setw(40) << "Title" << setw(10) << "Price"  << setw(3) << "Total"<< endl;


    for (int i =0; i<85; i++){
        cout << "_";
    }
    cout << '\n' << setw(4)  << left << fixed << setprecision(2) << bookQuantity << setw(20) << bookISBN << setw(40) << bookTitle  << " $" << setw(9) << bookPrice << "$"  << totalPrice << endl;
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

        return;


}

