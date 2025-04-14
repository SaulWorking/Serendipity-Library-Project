/******************************************************************
** Program: Serendipity Booksellers POS and inventory management software 
** Description: program will help employees sell and manage inventory


** Course: CS226 CRN 32842
** Professor: Huseyin Aygun
** Student: Thien Dinh
** Due Date: 04/13/2025
******************************************************************/




//thank you for fixing this 

#include <iostream>
#include <iomanip>
#include <cstring>
#include "allheaders.h"
using namespace std;



void printError(){

    static int counter{1};
    cout << "\nERROR! input/output doesnt work/\n\n" << "\n counter: " << counter << endl;
    counter++;
}



void invMenu(){

    int inventoryChoice{0};
    bool exitModule = false;
    
   while(exitModule == false){
    cout << setw(20) << ' ' << " Serendipity Booksellers" << endl;
    cout << setw(23) << ' ' << "Inventory Database\n\n";
    cout << setw(15) << ' ' << "1.	Look Up a Book"        << endl;
    cout << setw(15) << ' ' << "2.       Add a Book"      << endl;
    cout << setw(15) << ' ' << "3.	Edit a Book's Record"  << endl;
    cout << setw(15) << ' ' << "4.	Delete a Book"         << endl;
    cout << setw(15) << ' ' << "5.	Return to the Main Menu"  << endl;
    cout << '\n' << setw(15) << ' ' << "Enter your choice: ";
        
        cin >> inventoryChoice;
        switch (inventoryChoice) {
            case 1:
              lookUpBook();
              break;
            case 2:
              addBook();
              break;
            case 3:
              editBook();
              break;
            case 4:
              deleteBook();
              break;
            case 5:
              exitModule = true;
              break;
            default:
              cout << "Please enter a number in the range 1-5" << endl;
              break;
            }

    }
          
}

void lookUpBook() {

    int bookIndex = -1;
    string bookName;
        
            cout << "Title of book to look up: ";

            cin.ignore();
            getline(cin, bookName);
 
            cout << bookIndex;
            bookIndex = findBookIndex(bookName);
                
            cout << bookIndex << endl;

            if (bookIndex >=0) {
                  // look up book
                cout << "\n\nThe only book matching your title is...\n\n";
                
                bookIndexInformation(bookIndex);
                cout << '\n';
            } else {
                  cout << "Book not in inventory\n\n"; 
            }
}

//simple choice checking for user Inventory Database options.

//check if book space is available
//if available add book
//books can have the same title, unfortunately
void addBook() {
    double priceInput;
    int quantityInput;
    char userInput[51];
    cout << "\nAdding Book...\n" << endl;
  
    //set reading position to end of file
    bookFile.seekp(0L, ios::end);



    //find amount of books available
    int totalRecords = bookFile.tellp()/ sizeof(invbook);

    cout << "\nBooks in storage: " << totalRecords << endl;


    for (int i = 0; i < totalRecords; i++) {

        
        //prepare for file reading
        bookFile.clear();

        //try and find an empty book space
        bookFile.seekg(i*sizeof(invbook), ios::beg);

        //read from file if not at end and read to struct -> BookData invbook
        if (!bookFile.eof()) {
            bookFile.read(reinterpret_cast<char *>(&invbook), sizeof(invbook));
        }
    


        //check if invbook is empty
      if (isEmpty()){

        cin.ignore();
        cout << "ISBN: ";
        cin.getline(userInput, 14);
        strUpper((userInput));
        setISBN(userInput);
        
  
        cout << "Title: ";
        cin.getline(userInput, 51);
        strUpper((userInput));
        setTitle(userInput);
  
        cout << "Author: ";
        cin.getline(userInput, 31);
        strUpper((userInput));
        setAuthor(userInput);
  
        cout << "Publisher: ";
        cin.getline(userInput, 31);
        strUpper((userInput));
        setPub(userInput);
  
        cout << "Date: ";
        cin.getline(userInput, 11);
        setDateAdded(userInput);
  
        cout << "Quantity: ";
        cin >> quantityInput;
        cin.ignore();
        setQty(quantityInput);
  
        cout << "Wholesale cost: ";
        cin >> priceInput;
        cin.ignore();
        setWholesale(priceInput);
  
        cout << "Retail cost: ";
        cin >> priceInput;
        cin.ignore();
        setRetail(priceInput);
  

 
//https://stackoverflow.com/questions/38607754/how-to-force-file-flushing

        bookFile.clear();
        bookFile.seekp(0L, ios::end);
        bookFile.write(reinterpret_cast<char *>(&invbook), sizeof(invbook));
        bookFile.flush();



        return;
      
    }

    }



    cin.ignore();

    cout << "ISBN: ";
    cin.getline(userInput, 14);
    strUpper((userInput));
    setISBN(userInput);
    

    cout << "Title: ";
    cin.getline(userInput, 51);
    strUpper((userInput));
    setTitle(userInput);

    cout << "Author: ";
    cin.getline(userInput, 31);
    strUpper((userInput));
    setAuthor(userInput);

    cout << "Publisher: ";
    cin.getline(userInput, 31);
    strUpper((userInput));
    setPub(userInput);

    cout << "Date: ";
    cin.getline(userInput, 11);
    setDateAdded(userInput);

    cout << "Quantity: ";
    cin >> quantityInput;
    cin.ignore();
    setQty(quantityInput);

    cout << "Wholesale cost: ";
    cin >> priceInput;
    cin.ignore();
    setWholesale(priceInput);

    cout << "Retail cost: ";
    cin >> priceInput;
    cin.ignore();
    setRetail(priceInput);

  
  //https://stackoverflow.com/questions/37034247/ofstream-creating-file-but-not-writing-to-it-in-c
  
    bookFile.clear();
    bookFile.seekp(0L, ios::end);
    bookFile.write(reinterpret_cast<char *>(&invbook), sizeof(invbook));
    bookFile.flush();


  }
  








       


// search to check if book is in
//edit book if book exists
void editBook(){

    string bookName;
    int bookIndex = -1;

    cout << '\n' << setw(15) << "You selected edit book\n\n";
    cout << '\n' << setw(15) << "Title of book to edit: ";

    cin.ignore();
    getline(cin, bookName);   

        bookIndex = findBookIndex(bookName);



    if (bookIndex >=0) {
        // look up book
        cout << "\nYour book is...\n";

        bookIndexInformation(bookIndex);
        editInventoryInput(bookIndex);
    } else {
        cout << "Book not in inventory\n\n";
    }

     //checks for one of eight categories for book Information 
}




//tests for book availability in storage and deletes book
void deleteBook(){
    string bookName;
    char user;
    int bookIndex = -1;

    cout << '\n' << setw(15) << ' ' << "You selected delete book\n\n";
    cout << '\n' << setw(15) << ' ' << "which book will you delete? : ";
    

        cin.ignore();
        getline(cin, bookName);

        bookIndex = findBookIndex(bookName);

        if(bookIndex >=0){
            cout << '\n' << setw(20) << ' ' << "Do you really want to delete this?(Y/N): ";
    
                cin >> user;
                    cin.ignore();

            if(toupper(user) == 'Y'){
                removeBook(bookIndex);
                    
                
            bookFile.clear();
            bookFile.seekp(sizeof(invbook) * bookIndex, ios::beg);
            bookFile.write(reinterpret_cast<char *>(&invbook), sizeof(invbook));
            bookFile.flush();

            }else{
                cout << setw(25) << ' ' << "Book doesnt exist.\n";

            }
         }  
    return;
}


void editInventoryInput(int index){

    char userInput[51];
    int userQuantity = 0;
    int userEditChoice = 0;
    double userPrice = 0.0;
    bool exitModule = false;

    while(exitModule == false){
        cout << setw(20) << ' ' << " Serendipity Booksellers";
        cout << setw(23) << ' ' << "Inventory Database\n";
        cout << setw(15) << ' ' << "1   Title\n";
        cout << setw(15) << ' ' << "2.  ISBN\n";
        cout << setw(15) << ' ' << "3.	Author\n" ;
        cout << setw(15) << ' ' << "4.	Publisher\n";
        cout << setw(15) << ' ' << "5.	Date Added\n";
        cout << setw(15) << ' ' << "6.	Quantity\n";
        cout << setw(15) << ' ' << "7.	Wholesale price\n" ;
        cout << setw(15) << ' ' << "8.	Retail Price\n";
        cout << setw(15) << ' ' << "9.	Exit\n\n";


        cout << "Which book value do you want to edit? ";
        cin >> userEditChoice;
        cin.ignore();

    switch(userEditChoice){
        case 1:
            cout <<"\n Changing TITLE to: ";
            cin.getline(userInput, 51);
            strUpper(userInput);
            setTitle(userInput);
            break;
        case 2:
            cout <<"\n Changing ISBN to: ";
            cin.getline(userInput, 14);
            strUpper(userInput);
            setISBN(userInput);

            break;
        case 3:
            cout <<"\n Changing author to: ";
            cin.getline(userInput, 31);
            strUpper(userInput);
            setAuthor(userInput);

            break;
        case 4:
            cout <<"\n Changing publisher to: ";
            cin.getline(userInput, 31);
            strUpper(userInput);
            setPub(userInput);

            break;
         case 5:
            cout <<"\n Changing date added to: ";
            cin.getline(userInput, 11);
            strUpper(userInput);
            setDateAdded(userInput);
            break;
         case 6:
            cout <<"\n Changing quantity to: ";
            cin >> userQuantity;
            setQty(userQuantity);
            break;
         case 7:
            cout <<"\n Changing wholesale value to: ";
            cin >> userPrice;
            setWholesale(userPrice);
            break;
        case 8:
            cout <<"\n Changing retail value to: ";
            cin >> userPrice;
            setRetail(userPrice);
            break;
        case 9:

            exitModule = true;
            cout <<"goodbye!\n";
            break;
        default:
            cout << "\nTry again!\n";
    }   

        bookFile.clear();
        bookFile.seekp(sizeof(invbook) * index, ios::beg);
        bookFile.write(reinterpret_cast<char *>(&invbook), sizeof(invbook));
        bookFile.flush();

    }    

}






void strUpper(char * wordToBeUppercase){

        int counter =0;
        while( *(wordToBeUppercase+counter) != '0' && isalpha(*(wordToBeUppercase + counter))){
 
            *(wordToBeUppercase+counter) = toupper(wordToBeUppercase[counter]);
                counter++;
    
            


        }
}

int findBookIndex(string bookWant){

    //prepare bookfile for operation
    

    //i.e input free -> convert to FREE c-string 
    //check for "FREE" substring
        int bookIndex{-1};

        char bookToBeSearched[51];
        char found[51];
        char userInput{' '};
        //covert userInput to c-string 
        //convert to uppercase
        //general tip-> use strncpy to prevent segfaults/something similar

        strncpy(bookToBeSearched, bookWant.c_str(), 51);
        strUpper(bookToBeSearched);


    
        //ending byte
        bookFile.seekp(0L, ios::end);
        int totalRecords = bookFile.tellp()/ sizeof(invbook);

        cout << "\nBooks in storage: " << totalRecords << endl;


    


        for(int i =0; i <totalRecords;i++){
            
            bookFile.clear();
            bookFile.seekg(sizeof(invbook) * i, ios::beg);
            if (!bookFile.eof()) {
                bookFile.read(reinterpret_cast<char *>(&invbook), sizeof(invbook));
            }


            if(strstr(invbook.Title, bookToBeSearched)){
                strncpy(found, strstr(invbook.Title, bookToBeSearched), 51);



                }else{
                    continue;
            }

            if(found[0] != '\0'){

                //check if substring and book title are valid 
                if(!strcmp(found, invbook.Title) && invbook.Title[0] != '\0'){


                    
                    bookIndex = i;
                        bookIndexInformation(bookIndex);
                        cout << "\nIs this your book(Y/N)?";
                            cin >> userInput;
                    //if book is intended book exit loop
                        if(isalpha(userInput) && userInput == 'Y' || userInput == 'y'){
                            return bookIndex;
                        }else {
                            //else continue searching
                            cout << "\nNext book...\n\n";
                        }
                }    

        }

    }

    
    bookIndex = -1;

    return bookIndex;
}    //premature check











/*The lookUpBook function currently requires the user to enter 
                    the full name of the book to search for. 
Modify it so the user only has to enter part of the book title. 
Hint: Use the strstr function to search the title in the database.*/

void bookIndexInformation(const int bookIndex){
    bookInfo(
    invbook.Title, 
    invbook.ISBN,
    invbook.Author,  
    invbook.Publisher, 
    invbook.DateAdded, 
    invbook.QtyOnHand,
    invbook.WholesaleValue, 
    invbook.RetailValue);
}




void setTitle(char *Title){
    
    strncpy(invbook.Title, Title, 51); 

}

void setISBN(char *ISBN){
    strncpy(invbook.ISBN, ISBN, 14);
}
void setAuthor(char *Author){
    strncpy(invbook.Author, Author, 31);
}		 
void setPub(char *Publisher){
    strncpy(invbook.Publisher, Publisher, 31);
}
void setDateAdded(char *DateAdded){
    strncpy(invbook.DateAdded, DateAdded, 11);
}

void setQty(int bookQuantity){
    invbook.QtyOnHand = bookQuantity;
}
void setWholesale(double wholesalePrice){
    invbook.WholesaleValue = wholesalePrice;
} 
void setRetail(double retailPrice){
    invbook.RetailValue = retailPrice;
}
int isEmpty(){
        //checks for first character of Title at specified book index
    if(invbook.Title[0] == '\0'){
        return true;
    }else{
        return false;
    }

    
}

void removeBook(int bookIndex){
    invbook.Title[0] = '\0';
    invbook.ISBN[0] = '\0';
    invbook.Author[0]= '\0';
    invbook.Publisher[0] = '\0';
    invbook.DateAdded[0]= '\0';
    invbook.QtyOnHand = 0;
    invbook.RetailValue = 0.0;
    invbook.WholesaleValue = 0.0;
}

