/******************************************************************
** Program: Serendipity Booksellers POS and inventory management software 
** Description: program will help employees sell and manage inventory


** Course: CS226 CRN 32842
** Professor: Huseyin Aygun
** Student: Thien Dinh
** Due Date: 03/9/2025
******************************************************************/


#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>

#include "allheaders.h"
using namespace std;



//calculates price of book and asks for a repeat if possible
int cashier(){

    const double salesTax = 0.06;
    double totalPrice, bookPrice;

    //book quantity & book index
    int bookQuantity{0}, bookChosen{-1};


    
    char userDate[11], bookISBN[14], bookName[51];
    char userYN{' '};





    cout << '\n' << setw(20) << " " <<"Serenpidity Booksellers" << endl;
    cout << setw(25) << " " << "Cashier Module\n";





    cout << setw(15) << ' ' <<"ISBN:";

        cin.ignore();
        cin.getline(bookISBN, 14);


    bookChosen = ISBNLookup(bookISBN);

    if(qtyOnHand[bookChosen] <= 0 && !bookChosen){
        cout << "No book " << bookTitle[bookChosen] << " in stock.\nExiting cashier module...\n";
        //exit to main menu
        return -2;
    }
    

    while(bookChosen == -1){
        cout << "Cannot locate ISBN.";
        cout << "\nDo you want to retry?(y/n)";
         cin >> userYN;

         if(userYN == 'y'){
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



        


        while(bookQuantity < 0 || bookQuantity > qtyOnHand[bookChosen]){

            cout <<"\nInvalid Quantity. Try again: ";
            cin >> bookQuantity;
        }


        qtyOnHand[bookChosen] -= bookQuantity;

    
    }

    cout << "Do you want to purchase another book?(y/n)";
    cin >> userYN;







    totalPrice = (bookPrice * bookQuantity);

    cout << "\nDate:\t";
    displayDate();
    
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
        cin >> userYN;

        if(userYN == 'y' || userYN == 'Y'){
            cashier();
            }else{
                    cout << '\n' << setw(15) << ' ' << "Goodbye!";
                 }
            

        // return to main menu
        return -2;


}

int ISBNLookup(char ISBN[]){

    for(int i =0; i<20; i++){

        
        if(strstr(isbn[i], ISBN) == ISBN){
        
            return i;
        }
        


    }
    //returns invalid ISBN index
    return -1;
}