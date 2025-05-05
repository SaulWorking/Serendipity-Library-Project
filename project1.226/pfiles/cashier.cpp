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
#include <new>
#include "../include/allheaders.h"

double SoldBook::taxRate =0.06;
double SoldBook::total = 0.0;

//calculates price of book and asks for a repeat if possible
void cashier(){



    bool exitModule = false;
    int ISBNIndex{-1};
    char userInput = '\0';
    int purchasingQuanity{0}, bookQuantity{0};
    SoldBook* customerPurchases = nullptr;


    std::string cashierISBN = "";

    while(exitModule == false){

        menuHelper.separateText();
        menuHelper.menuOutput("Cashier");
        
        std::cin >> purchasingQuanity;

            if(purchasingQuanity <=0){
                std::cout << "\nGoodbye!";
                 exitModule = true;
                 break;
            }else{

                try{
                customerPurchases = new SoldBook[purchasingQuanity];
                }
                //fixed warning: catching polymorphic type 'class std::bad_alloc' by value [-Wcatch-value=]
                catch(std::bad_alloc&){
                      std::cout << "\nInsufficient memory, exiting program." << std::endl;
                exitModule = true;

                }
            }


        

    for(int i =0; i < purchasingQuanity; i++){

        std::cout << "\nBook ISBN: ";


        std::cin.ignore();
        std::getline(std::cin, cashierISBN);

        
        menuHelper.separateText();
        ISBNIndex = ISBNLookup(cashierISBN, customerPurchases[i]);




//PROBLEM WITH CODE: INVBOOK MUST BE READ BEFORE
//PROBLEM WITH CODE: INVBOOK MUST BE READ BEFORE
//PROBLEM WITH CODE: INVBOOK MUST BE READ BEFORE
//PROBLEM WITH CODE: INVBOOK MUST BE READ BEFORE
//PROBLEM WITH CODE: INVBOOK MUST BE READ BEFORE
//PROBLEM WITH CODE: INVBOOK MUST BE READ BEFORE
//PROBLEM WITH CODE: INVBOOK MUST BE READ BEFORE
//PROBLEM WITH CODE: INVBOOK MUST BE READ BEFORE




        if(invbook.getQty() <= 0){
            std::cout << "\n\n" << std::setw(15) << ' ' << "This book is not in stock." << std::setw(15) << ' ' << "\nExiting cashier module...\n";

            return;
        }

    //locate ISBN if user's ISBN is invalid
        while(ISBNIndex == -1){
            std::cout << "Cannot locate ISBN.";
            std::cout << "\nDo you want to retry?(y/n)";
            std::cin >> userInput;

            if(toupper(userInput) == 'Y'){
                std::cin.ignore();
                std::cout << "\nISBN:";
                std::getline(std::cin, cashierISBN);
                ISBNIndex = ISBNLookup(cashierISBN, customerPurchases[i]);
            }else{
                //exit
                std::cout << "\nExiting cashier module...\n";
                exitModule = true;
                return;
            }
        }


    //ISBN is found ask user for quantity
            if(ISBNIndex >=0){
                std::cout << "Book quantity? ";
                std::cin >> bookQuantity;


                // 0 < userQuantity < actualBookQuantity
                while( (bookQuantity < 0 || bookQuantity > customerPurchases[i].getQty()) && (!isdigit(bookQuantity)) ){
                    std::cout <<"\nInvalid Quantity. Try again: ";
                    std::cin >> bookQuantity;               
                                        
                }
                
                customerPurchases[i].setQtySold(bookQuantity);


                //subtract user quantity from store inventory

                //write new quantity to file

                
                invbook.setQty(customerPurchases[i].getQty() - customerPurchases[i].getQtySold());

                bookFile.bookWrite(invbook, ISBNIndex);
            }


            customerPurchases[i].setSubTotal(invbook.getRetail() * bookQuantity);

//end of foor loop            
        }




    //requesting multiple book purchasing functionality

    

    //output sale information for user
    menuHelper.cashierOutput("Transaction");





double accumulator =0.0;


for(int i =0; i<purchasingQuanity;i++){

    accumulator += customerPurchases[i].getSubTotal();
  



    std::cout << '\n' << std::setw(4)  << std::left << std::fixed << std::setprecision(2) << customerPurchases[i].getQtySold() << std::setw(20) << customerPurchases[i].getISBN() << std::setw(40) << customerPurchases[i].getTitle()  << " $" << std::setw(9) << customerPurchases[i].getRetail() << "$"  << customerPurchases[i].getSubTotal() << std::endl;
    std::cout << "\n\n\n";
        }


        customerPurchases[0].setTotal(accumulator + (accumulator * customerPurchases->getTaxRate()));


        std::cout << std::setw(61)  << "\t\tSubtotal" << "$" << accumulator << std::endl; 
        std::cout << std::setw(61)  << "\t\tTax"      << "$" << accumulator * customerPurchases->getTaxRate() << std::endl;
        std::cout << std::setw(61)  << "\t\tTotal"    << "$" << customerPurchases[0].getTotal() << std::endl;  





        std::cout << "\n\n" << std::setw(15) << ' ' << "Thank you for shopping at Serendipity\n\n" << std::endl;
        std::cout << "\n" << std::setw(15) << ' ' << "Do you have another transaction? (Y/N): ";

        std::cin >> userInput;

    if(toupper(userInput) == 'N'){
        exitModule = true;
        delete[] customerPurchases;

    }else{
        continue;
    }
        return;
    }

}

int ISBNLookup(std::string ISBN, SoldBook & books){

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



