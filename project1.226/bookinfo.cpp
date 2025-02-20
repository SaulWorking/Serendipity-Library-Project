#include <iostream>
#include <string>
using namespace std;



void bookInfo(string ISBN, string Title, string Author, string Publisher, string Date, string Quanity, string WholesalePrice, string RetailPrice){

cout << "Serendipity Booksellers Book Information " << endl;

 cout << "ISBN: " << ISBN << endl;
 cout << "Title: " << Title << endl;
 cout << "Author: " << Author << endl;
 cout << "Publisher: " << Publisher << endl;
 cout << "Date Added: " << Date << endl;
 cout << "Quantity-On-Hand: " << Quanity << endl;
 cout << "Wholesale Cost: " << WholesalePrice << endl;
 cout << "Retail Price: " << RetailPrice << endl;

    return;
}

