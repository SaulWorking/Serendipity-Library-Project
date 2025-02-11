#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
//ifstream -> you read
//ofstream -> you write
void inventoryCheck(){

std::ofstream writeFile;
std::ifstream readFile;

 cout << setw(20) << " " << " Serendipity Booksellers" << endl;
 cout << setw(23) << " " << "Inventory Database\n"  << endl;
 cout << setw(15) << " " << "1.	Look Up a Book"  << endl;
 cout << setw(15) << " " << "2.       Add a Book"  << endl;
 cout << setw(15) << " " << "3.	Edit a Book's Record"  << endl;
 cout << setw(15) << " " << "4.	Delete a Book"  << endl;
 cout << setw(15) << " " << "5.	Return to the Main Menu"  << endl;




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

 // mainMenu(); 
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
