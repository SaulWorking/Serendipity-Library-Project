#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;


struct BookData{
    char Title[51];
    char ISBN[14];    
    char Author[31];
    char Publisher[31];
    char DateAdded[11]; 

    int QtyOnHand;     
    double WholesaleValue;
    double RetailValue;


};  



int main(){

    fstream homophobia("reports.txt", ios::binary | ios::out | ios::in);
char read;


    BookData invbook;

    cout << sizeof(invbook);

    

    return 0;
}