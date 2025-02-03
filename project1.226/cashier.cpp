#include <iostream>
#include <string>
#include <iomanip>

/*The Cashier module allows the computer to act as a cash register. 
The user enters information for the books being purchased and the program calculates
 the sales tax and the total price. In addition, the books being purchased are automatically
  subtracted from the Inventory Database.*/

/*When the program runs, a menu will be displayed on the screen, 
which allows the user to activate any of the modules.
 A discussion of each module follows:*/

 /*Serendipity Booksellers is a small bookstore located in a shopping mall. They have a cashier station equipped with a personal computer. The manager wants you to develop a point-of-sale (POS) software package that will make the computer function as a cash register and keep an inventory file. The inventory file will be a database of all the books in the bookstore. In general, the software is to perform the following tasks:

•	Calculate the total of a sale, including sales tax
•	When a book is purchased, subtract it from the inventory 
*/
using namespace std;




double userTransaction(){

const double salesTax = 1.06;
double totalPrice, bookPrice;
int bookQuantity;
string userDate, bookISBN, bookTitle;


cout <<" The date: " << endl;
getline(cin, userDate);

cout << "\nbbook Quantity : " << endl;
cin >> bookQuantity;
cin.ignore();

cout << "\nbookISBN" << endl;
cin >> bookISBN;
cin.ignore();



cout << "\nbookTitel" << endl;
cin >> bookTitle;
cin.ignore();


cout << "\nbookPrice" << endl;
cin >> bookPrice;

totalPrice = (bookPrice * bookQuantity) * salesTax;

cout << "\n\nDate: " << userDate << "\n\n";
cout  << "Qty\tISBN\t\t\tTitle\t\tPrice\tTotal"<<endl;
for (int i =0; i<75; i++){
    cout << "_";
}
cout << left << "\n" << bookQuantity << "\t" << bookISBN << "\t\t\t" << bookTitle <<"\t\t$ " << bookPrice << "\t$ " << totalPrice;



    return totalPrice;
}
