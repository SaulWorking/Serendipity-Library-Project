
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
#include "allheaders.h"
using namespace std;


//prints out all book information like title and price
void bookInfo(char title[51], char ISBN[14], char author[31], char publisher[31], char date[11], int quanity, double wholesalePrice, double retailPrice){


    cout << "Serendipity Booksellers Book Information " << endl;

    cout << "Title: " << title << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << "Author: " << author << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Date Added: " << date << endl;
    cout << "Quantity-On-Hand: " << quanity << endl;
    cout << "Wholesale Cost: " << wholesalePrice << endl;
    cout << "Retail Price: " << retailPrice << endl;

        return; 
}

