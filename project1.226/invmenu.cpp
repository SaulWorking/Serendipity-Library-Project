#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;


//ifstream -> you read
//ofstream -> you write



void invMenu(){


std::ofstream writeFile;
std::ifstream readFile;

int userChoice;

 cout << setw(20) << " " << " Serendipity Booksellers" << endl;
 cout << setw(23) << " " << "Inventory Database\n\n";
 cout << setw(15) << " " << "1.	Look Up a Book"        << endl;
 cout << setw(15) << " " << "2.       Add a Book"      << endl;
 cout << setw(15) << " " << "3.	Edit a Book's Record"  << endl;
 cout << setw(15) << " " << "4.	Delete a Book"         << endl;
 cout << setw(15) << " " << "5.	Return to the Main Menu"  << endl;


cout << '\n' << setw(15) << " " << "Enter your choice: ";

    cin >> userChoice;

while(userChoice != 5){
 


       if(userChoice <1 || userChoice >5){

                    cout << "\n\n\n" << setw(15) << " " << "Please enter a valid number 1-5.\n\n\n";

        }



   

}





    switch(userChoice){

            case 1:

            cout << '\n' << setw(15) << "You selected item 1\n\n";

                break;
            case 2:
            cout << '\n' << setw(15) << "You selected item 2\n\n";

                break;
            case 3:
                cout << '\n' << setw(15) << "You selected item 3\n\n";

                break;
            case 4:
                cout << '\n' << setw(15) << "You selected item 4\n\n";

                break;

            case 5:
            cout << '\n' << setw(15) << "You selected item 5\n\n";

                break;

        }


    return;
}




