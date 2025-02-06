#include <iostream>
#include <string>
#include <iomanip>

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
