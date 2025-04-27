/******************************************************************
** Program: Serendipity Booksellers POS and inventory management software 
** Description: program will help employees sell and manage inventory


** Course: CS226 CRN 32842
** Professor: Huseyin Aygun
** Student: Thien Dinh
** Due Date: 04/27/2025
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
    double checkoutPrice = 0;
    int checkoutQuantity{0}, ISBNIndex{-1};
    char userInput = '\0';
    string cashierISBN = "";

    while(exitModule == false){

        menuHelper.menuOutput("Cashier");
            cin.ignore();
            getline(cin, cashierISBN);
        menuHelper.separateText();


        ISBNIndex = ISBNLookup(cashierISBN);

        if(invbook.getQty() <= 0){
            cout << "\n\n" << setw(15) << ' ' << "This book is not in stock." << setw(15) << ' ' << "\nExiting cashier module...\n";

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
                //exit
                cout << "\nExiting cashier module...\n";
                exitModule = true;
                return;
            }
        }


    //ISBN is found ask user for quantity
            if(ISBNIndex >=0){
                cout << "Book quantity? ";
                cin >> checkoutQuantity;

                // 0 < userQuantity < actualBookQuantity
                while(checkoutQuantity < 0 || checkoutQuantity > invbook.getQty() && !isdigit(checkoutQuantity)){
                    cout <<"\nInvalid Quantity. Try again: ";
                    cin >> checkoutQuantity;
                }

                //subtract user quantity from store inventory
                invbook.setQty(invbook.getQty()-checkoutQuantity);

                //write new quantity to file
                bookFile.bookWrite(invbook, ISBNIndex);
            }


    //requesting multiple book purchasing functionality

    checkoutPrice = (invbook.getRetail() * checkoutQuantity);


    //output sale information for user
    menuHelper.cashierOutput("Transaction", checkoutQuantity, checkoutPrice);

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

    for(int bookIndex =0; bookIndex<bookFile.storageSize(); bookIndex++){

    //read each book structure
    invbook = bookFile.bookRead(invbook, bookIndex);

        if(invbook.getISBN() == ISBN){
       //returns ISBN index 
            return bookIndex;
        }
    }
    //returns invalid ISBN index
    return -1;
}



