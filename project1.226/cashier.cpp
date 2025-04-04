/******************************************************************
** Program: Serendipity Booksellers POS and inventory management software 
** Description: program will help employees sell and manage inventory


** Course: CS226 CRN 32842
** Professor: Huseyin Aygun
** Student: Thien Dinh
** Due Date: 04/6/2025
******************************************************************/


//defo fix this 


#include <iostream>
#include <iomanip>
#include <cstring>

#include "allheaders.h"
using namespace std;


//calculates price of book and asks for a repeat if possible
void cashier(){

    bool exitModule = false;
    const double salesTax = 0.06;
    double checkoutPrice = 0;
    int checkoutQuantity{0}, ISBNIndex{-1};
    char userInput;
    string cashierISBN;

    
    while(exitModule == false){
        cout << '\n' << setw(20) << ' ' << "Serenpidity Booksellers" << endl;
        cout <<         setw(25) << ' ' << "Cashier Module\n";
        cout <<         setw(15) << ' ' << "ISBN:";

        //get book ISBN from user
            cin.ignore();
            getline(cin, cashierISBN);
        ISBNIndex = ISBNLookup(cashierISBN);

    //check for book availability
        if(invbook[ISBNIndex].QtyOnHand <= 0){
            cout << invbook[ISBNIndex].Title;
            cout << " is not in stock.\nExiting cashier module...\n";
            return;
        }

    //locate ISBN if user's ISBN is invalid
        while(ISBNIndex == -1){
            cout << "Cannot locate ISBN.";
            cout << "\nDo you want to retry?(y/n)";
                cin >> userInput;
            if(toupper(userInput) == 'Y'){
                cin.ignore();
                getline(cin, cashierISBN);
                ISBNIndex = ISBNLookup(cashierISBN);
            }else{
                cout << "\nExiting cashier module...\n";
                exitModule = true;
                break;
            }

        }


    //if ISBN is found ask user for quantity
     if(ISBNIndex >=0){
        cout << "Book quantity? ";
        cin >> checkoutQuantity;
        while(checkoutQuantity < 0 || checkoutQuantity > invbook[ISBNIndex].QtyOnHand && !isdigit(checkoutQuantity)){
            cout <<"\nInvalid Quantity. Try again: ";
            cin >> checkoutQuantity;
        }

        //subtract user quantity from store inventory
        invbook[ISBNIndex].QtyOnHand -= checkoutQuantity;
    }

    cout << "Do you want to purchase another book?(y/n)";




    //add multiple book purchasing functionality


        checkoutPrice = (invbook[ISBNIndex].RetailValue * checkoutQuantity);



    //output sale information for user

    cout << "\nDate:\t";
        displayDate();
    
    cout  << left<< setw(5) << "Qty" << setw(20) << "ISBN" << setw(40) << "Title" << setw(10) << "Price"  << setw(3) << "Total"<< endl;
        separateText();
    cout << '\n' << setw(4)  << left << fixed << setprecision(2) << checkoutQuantity << setw(20) << invbook[ISBNIndex].ISBN << setw(40) << invbook[ISBNIndex].Title  << " $" << setw(9) << invbook[ISBNIndex].RetailValue << "$"  << checkoutPrice << endl;
    cout << "\n\n\n";

    cout << setw(61)  << "\t\tSubtotal" << "$" << checkoutPrice << endl; 
    cout << setw(61)  << "\t\tTax"      << "$" << checkoutPrice * salesTax << endl;
    cout << setw(61)  << "\t\tTotal"    << "$" << checkoutPrice + (checkoutPrice * salesTax) << endl;

    cout << "\n\n" << setw(15) << ' ' << "Thank you for shopping at Serendipity\n\n" << endl;
    cout << "\n" << setw(15) << ' ' << "Do you have another transaction? (Y/N): ";
    cin >> userInput;

    if(toupper(userInput) == 'N'){
        exitModule = true;
    }else{
        continue;
    }
        return;
    }
}




int ISBNLookup(string ISBN){

    for(int i =0; i<20; i++){
        if(invbook[i].ISBN == ISBN){
       //returns ISBN index 
            return i;
        }
    }
    //returns invalid ISBN index
    return -1;
}

