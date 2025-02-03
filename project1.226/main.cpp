#include "cashier.cpp"
#include "inventory.cpp"
#include "report.cpp"


int main(){

int userInut;





inventoryCheck();

double userPayment = userTransaction();

cout << "\n\n\n\nYou pay " << fixed << setprecision(2) << userPayment << endl;




    return 0;
}