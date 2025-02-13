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
int userChoice;


 cout << setw(20) << " " << " Serendipity Booksellers" << endl;
 cout << setw(23) << " " << "Inventory Database\n"  << endl;
 cout << setw(15) << " " << "1.	Look Up a Book"  << endl;
 cout << setw(15) << " " << "2.       Add a Book"  << endl;
 cout << setw(15) << " " << "3.	Edit a Book's Record"  << endl;
 cout << setw(15) << " " << "4.	Delete a Book"  << endl;
 cout << setw(15) << " " << "5.	Return to the Main Menu"  << endl;


cout << setw(15) << " " << "Enter your choice: ";


while(userChoice <1 || userChoice >5){
    cin >> userChoice;

    if(userChoice <1 || userChoice >5){

        cout << '\n' << setw(15) << "Enter a number 1-5: \n";

    }

}



switch(userChoice){

    case 1:

    cout << '\n' << setw(15) << "You selected item 1";

        break;
    case 2:
    cout << '\n' << setw(15) << "You selected item 2";

        break;
    case 3:
        cout << '\n' << setw(15) << "You selected item 3";

        break;
    case 4:
        cout << '\n' << setw(15) << "You selected item 4";

        break;

    case 5:
    cout << '\n' << setw(15) << "You selected item 5";

        break;

}


    return;
}






void bookLookup();
void bookAdd();
void bookEdit();
void bookDelete();
