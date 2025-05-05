
/******************************************************************
** Program: Serendipity Booksellers POS and inventory management software 
** Description: program will help employees sell and manage inventory


** Course: CS226 CRN 32842
** Professor: Huseyin Aygun
** Student: Thien Dinh
** Due Date: 04/27/2025
******************************************************************/

#include <iostream>
#include "../include/allheaders.h"

//prints out all book information like title and price
void bookInfo(char Title[51], char ISBN[14], char Author[31], char Date[11], char Publisher[31], int Quantity, double WholesalePrice, double RetailPrice){
    
    
    std::cout << std::left << "Title: "  <<  Title;
    std::cout << '\n' << "ISBN: " <<   ISBN << '\n';
    std::cout <<         "Author: " << Author;
    std::cout <<'\n'  << "Date added: " << Date << '\n';
    std::cout <<         "Publisher: "  << Publisher;
    std::cout <<'\n'  << "Quantity: " << Quantity << '\n'; 
    std::cout <<         "Wholesale value: " << WholesalePrice;
    std::cout <<'\n' <<  "Retail price: " << RetailPrice;
    std::cout << "\n\n"; 
    menuHelper.separateText();
        return; 
}
