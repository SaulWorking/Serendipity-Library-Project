
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
using namespace std;


//prints out all book information like title and price
void bookInfo(string Title, string ISBN, string Author, string Publisher, string Date, int Quanity, double WholesalePrice, double RetailPrice){

    cout << "Serendipity Booksellers Book Information " << endl;

    cout << "Title: " << Title << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << "Author: " << Author << endl;
    cout << "Publisher: " << Publisher << endl;
    cout << "Date Added: " << Date << endl;
    cout << "Quantity-On-Hand: " << Quanity << endl;
    cout << "Wholesale Cost: " << WholesalePrice << endl;
    cout << "Retail Price: " << RetailPrice << endl;

        return; 
}

