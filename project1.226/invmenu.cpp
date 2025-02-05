#include <fstream>
#include <string>
#include <iostream>
using namespace std;
//ifstream -> you read
//ofstream -> you write
void inventoryCheck(){

std::ofstream writeFile;
std::ifstream readFile;

 cout << " Serendipity Booksellers Inventory Database "  << endl;
 cout << "1.	Look Up a Book"  << endl;
 cout << "2.	Add a Book"  << endl;
 cout << "3.	Edit a Book’s Record"  << endl;
 cout << "4.	Delete a Book"  << endl;
 cout << "5.	Return to the Main Menu"  << endl;

int userChoice;
cin >> userChoice;
cin.ignore();

switch(userChoice){

    case 1:


        break;
    case 2:

        break;
    case 3:
        break;
    case 4:
        break;

    case 5:
        break;
    default:

    cout << "Restart. "<<endl;

}


    return;
}

void bookLookup();
void bookAdd();
void bookEdit();
void bookDelete();
