/******************************************************************
** Program: Serendipity Booksellers POS and inventory management software 
** Description: program will help employees sell and manage inventory


** Course: CS226 CRN 32842
** Professor: Huseyin Aygun
** Student: Thien Dinh
** Due Date: 03/9/2025
******************************************************************/

#include <iostream>
#include <iomanip>
#include "allheaders.h"
using namespace std;


int reports(){

    int userChoice;

    cout << setw(20) << " " << "Serendipity Booksellers\n";
    cout << setw(25) << " " << "Reports\n\n";
    cout << setw(15) << " " << "1.	Inventory Listing\n";
    cout << setw(15) << " " << "2.	Inventory Wholesale Value\n";
    cout << setw(15) << " " <<" 3.	Inventory Retail Value\n";
    cout << setw(15) << " " <<" 4.	Listing by Quantity\n";
    cout << setw(15) << " " <<" 5.	Listing by Cost\n";
    cout << setw(15) << " " <<" 6.	Listing by Age\n";
    cout << setw(15) << " " <<" 7.	Return to Main Menu\n";
    cout << setw(15) << " " << "Enter Your Choice: ";

        cin >> userChoice;

        cout << '\n';

        while(userChoice <1 || userChoice >7){

                cout << "\n" << setw(15) << ' ' << "Please enter a valid number 1-7.\n";

                cin >> userChoice;
            }
            reportsCheck(userChoice);

    return userChoice;
}










void reportsCheck(int userInput){

    switch(userInput){

        case 1:
     repListing();        
     reports();
            break;
        case 2:
    repWholesale();
    reports();
            break;
        case 3:
    repRetail();
    reports();
            break;
        case 4:
    repQty();
    reports();
            break;

         case 5:   
    repCost();
    reports();
            break;
        case 6:
    repAge();
    reports();
            break;
        case 7:
           
        break;


    }

}



void repListing(){

    string wait;
       


       cout << setw(55) << "Inventory Report\n"; 
        displayDate();

        for(int i =0; i< 100;i++){
            cout << '-';
        }

        cout << '\n';

        for(int i =0; i<20; i++){
            
            if(bookTitle[i][0] != '\0'){
                cout << left << "Title: "  <<  bookTitle[i]  << '\n' << "ISBN: " <<   isbn[i] << '\n';
                cout << "Author: " << author[i] << '\n' << "Date added: " << dateAdded[i] << '\n';
                cout << "Publisher: "  << publisher[i]  << '\n' << "Quantity: " << qtyOnHand[i] << '\n'; 
                cout << "Wholesale value: " << wholeSale[i] << '\n' << "Retail price: " <<retail[i] << "\n\n"; 
            }

        }
        
        for(int i =0; i< 100;i++){
            cout << '-';
        }


        cout << '\n';
        cout << "\nPress enter to continue.";
        cin.ignore();
        getline(cin, wait);
        cout << '\n';
}
void repWholesale(){



string wait;
double WholesaleValue{0.0};

    cout << '\n';

       cout << '\n' << setw(55) << "Wholesale report\n";
        cout << '\n' << setw(55); 
        displayDate();

        for(int i =0; i< 100;i++){
            cout << '-';
        }

        cout << '\n';


        
        for(int i =0; i<20; i++){

            if(bookTitle[i][0] != '\0'){
            cout << left << "Title: "  <<  bookTitle[i]  << '\n' << "ISBN: " <<   isbn[i] << endl;
            cout << "Wholesale value: " << wholeSale[i] << "\n\n";
            WholesaleValue += wholeSale[i] * qtyOnHand[i];
            
            }
        }
        
        cout << '\n';
        for(int i =0; i< 100;i++){
            cout << '-';
        }

        cout << '\n' << setw(55); 
        cout << "Wholesale value: " << WholesaleValue;
        cout << '\n';
        cout << "\nPress enter to continue.";
        cin.ignore();
        getline(cin, wait);
        cout << '\n';
}

void repRetail(){

string wait;
double retailValue{0.0};

    cout << '\n';

       cout << '\n' << setw(55) << "Retail report\n";
        cout << '\n' << setw(55); 
        displayDate();


        for(int i =0; i< 100;i++){
            cout << '-';
        }

        cout << '\n';



        for(int i =0; i<20; i++){

            if(bookTitle[i][0] != '\0'){
            cout << left << "Title: "  <<  bookTitle[i]  << '\n' << "ISBN: " <<   isbn[i] << endl;
            cout << "Retail price: " <<retail[i] << "\n\n"; 

            retailValue += retail[i] * qtyOnHand[i];
            
            }
        }


        cout << '\n';
        for(int i =0; i< 100;i++){
            cout << '-';
        }

        cout << '\n' << setw(55); 
        cout << "Retail value: " << retailValue;
        cout << '\n';
        cout << "\nPress enter to continue.";
        cin.ignore();
        getline(cin, wait);
        cout << '\n';

}


void repQty(){


    string wait;
    int indices[9];   


       cout << setw(55) << "Inventory Report\n"; 
        displayDate();

        for(int i =0; i< 100;i++){
            cout << '-';
        }

        cout << '\n';


        
        qtsort(indices);

        

        for (int i = 0; i < 10; i++) {

            int index = indices[i];

            if(bookTitle[i][0] != '\0'){
                cout << left << "Title: "  <<  bookTitle[index];
                cout << '\n' << "ISBN: " <<   isbn[index] << endl;
                cout << "Quantity: " << qtyOnHand[index] << endl;
                cout << '\n';
                
                }


        }
          
        

        for(int i =0; i< 100;i++){
            cout << '-';
        }


        cout << '\n';
        cout << "\nPress enter to continue.";
        cin.ignore();
        getline(cin, wait);
        cout << '\n';



}
void repCost(){

        
    string wait;
    int indices[9];   


       cout << setw(55) << "Inventory Report\n"; 
        displayDate();

        for(int i =0; i< 100;i++){
            cout << '-';
        }

        cout << '\n';


        
        costSort(indices);

        

        for (int i = 0; i < 10; i++) {

            int index = indices[i];

            if(bookTitle[i][0] != '\0'){
                cout << left << "Title: "  <<  bookTitle[index];
                cout << '\n' << "ISBN: " <<   isbn[index] << endl;
                cout << "wholesale cost: " << wholeSale[index] << endl;
                cout << '\n';
                
                }


        }
          
        

        for(int i =0; i< 100;i++){
            cout << '-';
        }


        cout << '\n';
        cout << "\nPress enter to continue.";
        cin.ignore();
        getline(cin, wait);
        cout << '\n';


}
void repAge(){



    string wait;
    int indices[9];  



       cout << setw(55) << "Inventory Report\n"; 
        displayDate();

        for(int i =0; i< 100;i++){
            cout << '-';
        }

        cout << '\n';

        dateSort(indices);

        for (int i = 0; i < 10; i++) {

            int index = indices[i];

            if(bookTitle[i][0] != '\0'){
                cout << left << "Title: "  <<  bookTitle[index];
                cout << '\n' << "ISBN: " <<   isbn[index] << endl;
                cout << "Date Added: " << dateAdded[index] << endl;
                cout << '\n';
                
                }
        }
          
        

        for(int i =0; i< 100;i++){
            cout << '-';
        }


        cout << '\n';
        cout << "\nPress enter to continue.";
        cin.ignore();
        getline(cin, wait);
        cout << '\n';

}



/*  guide for displaying c++ date

https://www.w3schools.com/cpp/cpp_date.asp
    
    */

void displayDate(){

    time_t day;

    time(&day);

    cout << ctime(&day);


}


void swap(int &num1, int &num2){

    int temp = num1;
    num1 = num2;
    num2 = temp;



}



void qtsort(int indices[]){

    const int SIZE = 10;

    for(int i=0; i<SIZE; i++)
        indices[i] = i;

    for (int i = 0; i < SIZE - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (qtyOnHand[indices[j]] > qtyOnHand[indices[maxIndex]]) {
                maxIndex = j;
            }
        }


        int temp = indices[i];
        indices[i] = indices[maxIndex];
        indices[maxIndex] = temp;
    }

  }



  void costSort(int indices[]){

    const int SIZE = 10;

    for(int i=0; i<SIZE; i++)
        indices[i] = i;

    for (int i = 0; i < SIZE - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (wholeSale[indices[j]] > wholeSale[indices[maxIndex]]) {
                maxIndex = j;
            }
        }


        int temp = indices[i];
        indices[i] = indices[maxIndex];
        indices[maxIndex] = temp;
    }

  }
  

  void dateSort(int indices[]){

    const int SIZE = 10;


    string dates[SIZE];

    for(int i =0; i<SIZE; i++){
        dates[i] = dateAdded[i];
    }

//code from https://www.geeksforgeeks.org/removing-punctuations-given-string/


    for(int index =0; index<SIZE; index++){

        for (int i = 0, len = dates[index].size(); i < len; i++)
        {
            // check whether parsing character is punctuation or not
            if (ispunct(dates[index][i]))
            {
                dates[index].erase(i--, 1);
                len = dates[index].size();
            }
        }

    }  

    // indexes
    for(int i=0; i<SIZE; i++)
        indices[i] = i;

    

    

    for (int i = 0; i < SIZE - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (dateAdded[indices[j]] > dateAdded[indices[maxIndex]]) {
                maxIndex = j;
            }
        }


        int temp = indices[i];
        indices[i] = indices[maxIndex];
        indices[maxIndex] = temp;
    }


  }





    





