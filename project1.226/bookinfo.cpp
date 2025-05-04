
/******************************************************************
** Program: Serendipity Booksellers POS and inventory management software 
** Description: program will help employees sell and manage inventory


** Course: CS226 CRN 32842
** Professor: Huseyin Aygun
** Student: Thien Dinh
** Due Date: 04/27/2025
******************************************************************/

#include <iostream>
#include "allheaders.h"
using namespace std;

//prints out all book information like title and price
void bookInfo(char Title[51], char ISBN[14], char Author[31], char Date[11], char Publisher[31], int Quantity, double WholesalePrice, double RetailPrice){
    
    
    cout << left << "Title: "  <<  Title;
    cout << '\n' << "ISBN: " <<   ISBN << '\n';
    cout <<         "Author: " << Author;
    cout <<'\n'  << "Date added: " << Date << '\n';
    cout <<         "Publisher: "  << Publisher;
    cout <<'\n'  << "Quantity: " << Quantity << '\n'; 
    cout <<         "Wholesale value: " << WholesalePrice;
    cout <<'\n' <<  "Retail price: " << RetailPrice;
    cout << "\n\n"; 
    menuHelper.separateText();
        return; 
}
