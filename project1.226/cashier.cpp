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




void userTransaction(){

const double salesTax = 0.06;
double totalPrice, bookPrice;
int bookQuantity;
string userDate, bookISBN, bookTitle;

cout << "Serenpidity Booksellers" << endl;
cout << "Cashier Action\n\n";



cout <<" The date: " << endl;
getline(cin, userDate);

cout << "\n BOOK Quantity : " << endl;
cin >> bookQuantity;
cin.ignore();

cout << "\nbook ISBN:" << endl;
getline(cin, bookISBN);

cout << "\nbook Title:" << endl;
getline(cin, bookTitle);


cout << "\nbook Price: " << endl;
cin >> bookPrice;

totalPrice = (bookPrice * bookQuantity);

cout << "\n\nDate: " << userDate << "\n\n";
cout  << left<< setw(5) << "Qty" << setw(20) << "ISBN" << setw(40) << "Title" << setw(10) << "Price"  << setw(3) << "Total"<< endl;


for (int i =0; i<85; i++){
    cout << "_";
}
cout << '\n' << setw(4)  <<left <<fixed <<setprecision(2)  << bookQuantity << setw(20) << bookISBN << setw(40) << bookTitle  <<" $"  <<setw(9) << bookPrice << "$"  << totalPrice << endl;
cout << "\n\n\n";
cout << setw(61)  << "\t\tSubtotal" << "$" << totalPrice << endl; 
cout << setw(61)  << "\t\tTax" <<  "$" << totalPrice * salesTax << endl;
cout << setw(61)  << "\t\tTotal" << "$" << totalPrice + (totalPrice * salesTax) << endl;

cout << "\n\nThank you for shopping at Serendipity\n\n" << endl;


    return;
}
