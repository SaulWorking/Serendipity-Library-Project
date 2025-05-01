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
    int ISBNIndex{-1};
    char userInput = '\0';
    int userQuantity{0};
    SoldBook* customerPurchases = nullptr;


    string cashierISBN = "";

    while(exitModule == false){

        menuHelper.separateText();
        menuHelper.menuOutput("Cashier");
        
            cin >> userQuantity;

            if(customerPurchases <=0){
                cout << "\nGoodbye!";
                 exitModule = true;
                 break;
            }else{
                customerPurchases = new SoldBook[userQuantity];
            }

        
        cout << "\nBook ISBN: ";


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
                cin >> userQuantity;


                // 0 < userQuantity < actualBookQuantity
                while(userQuantity < 0 || userQuantity > invbook.getQty() && !isdigit(userQuantity)){
                    cout <<"\nInvalid Quantity. Try again: ";
                    cin >> userQuantity;               
                                        
                }
                customerPurchases[0].setQtySold(userQuantity);
    
                customerPurchases[0].setQtySold(invbook.getQty() - customerPurchases[0].getQtySold());
                //subtract user quantity from store inventory

                //write new quantity to file
                bookFile.bookWrite(customerPurchases[0], ISBNIndex);
            }





    //requesting multiple book purchasing functionality
customerPurchases[0].setSubTotal(invbook.getRetail() * userQuantity);

    

    //output sale information for user
    menuHelper.cashierOutput("Transaction", userQuantity, customerPurchases[0].getSubTotal());

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



