/******************************************************************
** Program: Serendipity Booksellers POS and inventory management software 
** Description: program will help employees sell and manage inventory


** Course: CS226 CRN 32842
** Professor: Huseyin Aygun
** Student: Thien Dinh
** Due Date: 04/27/2025
******************************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>
#include "../include/headers.h"

double SoldBook::taxRate = 0.06;
double SoldBook::total = 0.0;

//calculates price of book and asks for a repeat if possible
void cashier(){
    bool exitModule = false;
    int ISBNIndex{-1};
    char userInput = '\0';
    int purchasingQuanity{0}, bookQuantity{0};
    SoldBook* customerPurchases = nullptr;
    string cashierISBN = "";

    while(exitModule == false){
        menuHelper.separateText();
        menuHelper.menuOutput("Cashier");
        
        cin >> purchasingQuanity;

            if(purchasingQuanity <=0){
                 cout << "\nGoodbye!";
                 exitModule = true;
                 break;
            }else{
                try{
                customerPurchases = new SoldBook[purchasingQuanity];
                }
                //fixed warning: catching polymorphic type 'class bad_alloc' by value [-Wcatch-value=]
                catch(bad_alloc&){
                      cout << "\nInsufficient memory, exiting program." << endl;
                exitModule = true;
                }
            }

    for(int i =0; i < purchasingQuanity; i++){
        cout << "\nBook ISBN: ";

        cin.ignore();
        getline(cin, cashierISBN);

        menuHelper.separateText();
        ISBNIndex = ISBNLookup(cashierISBN, customerPurchases[i]);

//ISSUE WITH CODE: INVBOOK MUST BE READ BEFORE

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
                cout << "\nISBN:";
                getline(cin, cashierISBN);
                ISBNIndex = ISBNLookup(cashierISBN, customerPurchases[i]);
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
                cin >> bookQuantity;

                // 0 < userQuantity < actualBookQuantity
                while( (bookQuantity < 0 || bookQuantity > customerPurchases[i].getQty()) && (!isdigit(bookQuantity)) ){
                    cout <<"\nInvalid Quantity. Try again: ";
                    cin >> bookQuantity;               
                                        
                }
                customerPurchases[i].setQtySold(bookQuantity);
                //subtract user quantity from store inventory
                //write new quantity to file
                invbook.setQty(customerPurchases[i].getQty() - customerPurchases[i].getQtySold());
                bookFile.bookWrite(invbook, ISBNIndex);
            }
            customerPurchases[i].setSubTotal(invbook.getRetail() * bookQuantity);
        }

    //requesting multiple book purchasing functionality
    //output sale information for user
    menuHelper.cashierOutput("Transaction");

double accumulator =0.0;

for(int i =0; i<purchasingQuanity;i++){
    accumulator += customerPurchases[i].getSubTotal();

    cout << '\n' << setw(4)  << left << fixed << setprecision(2) << customerPurchases[i].getQtySold() << setw(20) << customerPurchases[i].getISBN() << setw(40) << customerPurchases[i].getTitle()  << " $" << setw(9) << customerPurchases[i].getRetail() << "$"  << customerPurchases[i].getSubTotal() << endl;
    cout << "\n\n\n";
     }
        customerPurchases[0].setTotal(accumulator + (accumulator * customerPurchases->getTaxRate()));

        cout << setw(61)  << "\t\tSubtotal" << "$" << accumulator << endl; 
        cout << setw(61)  << "\t\tTax"      << "$" << accumulator * customerPurchases->getTaxRate() << endl;
        cout << setw(61)  << "\t\tTotal"    << "$" << customerPurchases[0].getTotal() << endl;  
        cout << "\n\n" << setw(15) << ' ' << "Thank you for shopping at Serendipity\n\n" << endl;
        cout << "\n" << setw(15) << ' ' << "Do you have another transaction? (Y/N): ";
        cin >> userInput;

        if(toupper(userInput) == 'N'){
            exitModule = true;
            delete[] customerPurchases;
        }else{
            continue;
        }
        return;
    }
}

int ISBNLookup(string ISBN, SoldBook & books){
    for(int bookIndex =0; bookIndex<bookFile.storageSize(); bookIndex++){
    //read each book structure

    bookFile.bookRead(books, bookIndex);
    bookFile.bookRead(invbook, bookIndex);
        if(books.getISBN() == ISBN){
       //returns ISBN index 
            return bookIndex;
        }
    }
    //returns invalid ISBN index
    return -1;
}



