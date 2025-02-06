#include <iostream>
#include "mainmenu.cpp"
#include "reports.cpp"
#include "invmenu.cpp"
#include "cashier.cpp"


using namespace std;

int main(){
int userOption;
userOption = mainMenu();

switch(userOption){

    case 1:

    userTransaction();
        break;
    case 2:
    
    inventoryCheck();
        break;
    case 3:

    reportInfo();    
        break;
    case 4:

    cout << "\n\nGoodbye!";
        break;
    default:

    cout << "Run the program again. "<<endl;

}


    return 0;
}