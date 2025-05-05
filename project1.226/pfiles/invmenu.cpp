/******************************************************************
** Program: Serendipity Booksellers POS and inventory management software 
** Description: program will help employees sell and manage inventory


** Course: CS226 CRN 32842
** Professor: Huseyin Aygun
** Student: Thien Dinh
** Due Date: 04/27/2025
******************************************************************/


#include <iostream>
#include <iomanip>
#include <cstring>
#include "../include/allheaders.h"

void invMenu(){
    int inventoryChoice{0};
    bool exitModule = false;
    
   while(exitModule == false){

    menuHelper.menuOutput("Inventory");
        
    std::cin >> inventoryChoice;
        
    menuHelper.separateText();

        switch (inventoryChoice){
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
            std::cout << "Please enter a number in the range 1-5" << std::endl;
              break;
            }
    }
}

void lookUpBook() {
    int bookIndex = -1;
    std::string bookName;
        
    std::cout << "Title of book to look up: ";

    std::cin.ignore();
    std::getline(std::cin, bookName);

        menuHelper.separateText();

            bookIndex = findBookIndex(bookName);
            
        if (bookIndex >=0) {
            std::cout << "\n\nThe only book matching your title is...\n\n";
            invbook.bookIndexInformation();
            std::cout << '\n';
        } else {
            std::cout << "Book not in inventory\n\n"; 
        }
}

//simple choice checking for user Inventory Database options.

//check if book space is available
//if available add book
//books can have the same title, unfortunately

//make this function shorter soon
void addBook() {
    double priceInput =0.0;
    int quantityInput =0;
    char userInput[51];
    bool writeCheck = false;
    std::cout << "\nAdding Book...\n" << std::endl;
    std::cout << "\nBooks in storage: " << bookFile.storageSize() << std::endl;

    for (int i = 0; i < bookFile.storageSize(); i++) {

        bookFile.bookRead(invbook, i);

        if (invbook.isEmpty()){

            std::cin.ignore();
            std::cout << "ISBN: ";
            std::cin.getline(userInput, 14);
            menuHelper.separateText();
            strUpper((userInput));
            invbook.setISBN(userInput);
            
            std::cout << "Title: ";
            std::cin.getline(userInput, 51);
            menuHelper.separateText();
            strUpper((userInput));
            invbook.setTitle(userInput);
    
            std::cout << "Author: ";
            std::cin.getline(userInput, 31);
            menuHelper.separateText();
            strUpper((userInput));
            invbook.setAuthor(userInput);
    
            std::cout << "Publisher: ";
            std::cin.getline(userInput, 31);
            menuHelper.separateText();
            strUpper((userInput));
            invbook.setPub(userInput);
    
            std::cout << "Date: ";
            std::cin.getline(userInput, 11);
            menuHelper.separateText();
            invbook.setDateAdded(userInput);
    
            std::cout << "Quantity: ";
            std::cin >> quantityInput;
            menuHelper.separateText();
            std::cin.ignore();
            invbook.setQty(quantityInput);
    
            std::cout << "Wholesale cost: ";
            std::cin >> priceInput;
            menuHelper.separateText();
            std::cin.ignore();
            invbook.setWholesale(priceInput);
    
            std::cout << "Retail cost: ";
            std::cin >> priceInput;
            menuHelper.separateText();
            std::cin.ignore();
            invbook.setRetail(priceInput);
            
        if((priceInput > -1 && priceInput <2147483647) && (quantityInput > -1) && (userInput[0] != '\0')){
        writeCheck = true;
        }


        
    //https://stackoverflow.com/questions/38607754/how-to-force-file-flushing

            if(writeCheck){
                bookFile.bookWrite(invbook);
            }else{
                invbook.removeBook();
                std::cout << "Failure to write...\n";
            }
            return;
        
        }
    }


    if(bookFile.storageSize() < 20){
        std::cin.ignore();

        std::cout << "ISBN: ";
        std::cin.getline(userInput, 14);
        menuHelper.separateText();
        strUpper((userInput));
        invbook.setISBN(userInput);
        
        std::cout << "Title: ";
        std::cin.getline(userInput, 51);
        menuHelper.separateText();
        strUpper((userInput));
        invbook.setTitle(userInput);

        std::cout << "Author: ";
        std::cin.getline(userInput, 31);
        menuHelper.separateText();
        strUpper((userInput));
        invbook.setAuthor(userInput);

        std::cout << "Publisher: ";
        std::cin.getline(userInput, 31);
        menuHelper.separateText();
        strUpper((userInput));
        invbook.setPub(userInput);

        std::cout << "Date: ";
        std::cin.getline(userInput, 11);
        menuHelper.separateText();
        invbook.setDateAdded(userInput);

        std::cout << "Quantity: ";
        std::cin >> quantityInput;
        menuHelper.separateText();
        std::cin.ignore();
        invbook.setQty(quantityInput);

        std::cout << "Wholesale cost: ";
        std::cin >> priceInput;
        menuHelper.separateText();
        std::cin.ignore();
        invbook.setWholesale(priceInput);

        std::cout << "Retail cost: ";
        std::cin >> priceInput;
        menuHelper.separateText();
        std::cin.ignore();
        invbook.setRetail(priceInput);

    //https://stackoverflow.com/questions/37034247/ofstream-creating-file-but-not-writing-to-it-in-c

    
    if((priceInput > -1 && priceInput <2147483647) && (quantityInput > -1) && (userInput[0] != '\0')){
        writeCheck = true;
        }


        
    //https://stackoverflow.com/questions/38607754/how-to-force-file-flushing

            if(writeCheck){
                bookFile.bookWrite(invbook);
            }else{
                invbook.removeBook();
                std::cout << "Failure to write...\n";
            }
            return;
        
        

    
    }
}


// search to check if book is in
//edit book if book exists
void editBook(){
    std::string bookName;
    int bookIndex = -1;

    std::cout << '\n' << std::setw(15) << "You selected edit book\n\n";
    std::cout << '\n' << std::setw(15) << "Title of book to edit: ";

    std::cin.ignore();
    std::getline(std::cin, bookName);   
    menuHelper.separateText();
        bookIndex = findBookIndex(bookName);


    if (bookIndex >=0) {
        // look up book
        std::cout << "\nYour book is...\n";

        invbook.bookIndexInformation();
        editInventoryInput(bookIndex);
    } else {
        std::cout << "Book not in inventory\n\n";
    }

     //checks for one of eight categories for book Information 
}


//tests for book availability in storage and deletes book
void deleteBook(){
    std::string bookName;
    char user;
    int bookIndex = -1;

    std::cout << '\n' << std::setw(15) << ' ' << "You selected delete book\n\n";
    std::cout << '\n' << std::setw(15) << ' ' << "which book will you delete? : ";
    

    std::cin.ignore();
        std::getline(std::cin, bookName);
        menuHelper.separateText();

            bookIndex = findBookIndex(bookName);

        if(bookIndex >=0){
            std::cout << '\n' << std::setw(20) << ' ' << "Do you really want to delete this?(Y/N): ";
    
            std::cin >> user;
                std::cin.ignore();

            if(toupper(user) == 'Y'){
                invbook.removeBook();
                // at book Index and then Write to file
                //book Index Byte
                    
                bookFile.bookWrite(invbook, bookIndex);
                
            }else{
                std::cout << std::setw(25) << ' ' << "Book doesnt exist.\n";
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
    bool writeCheck = false;

    while(exitModule == false){

        menuHelper.menuOutput("InventoryEdit");
        invbook.bookIndexInformation();


        std::cout << "Which book value do you want to edit? ";
        std::cin >> userEditChoice;
        menuHelper.separateText();

        std::cin.ignore();



    switch(userEditChoice){
        case 1:
        std::cout <<"\n Changing TITLE to: ";
            std::cin.getline(userInput, 51);
            strUpper(userInput);
            menuHelper.separateText();
            invbook.setTitle(userInput);      
            if(userInput[0] != '\0'){writeCheck = true;}
    

            break;
        case 2:
        std::cout <<"\n Changing ISBN to: ";
            std::cin.getline(userInput, 14);
            strUpper(userInput);
            menuHelper.separateText();
            invbook.setISBN(userInput);
            if(userInput[0] != '\0'){writeCheck = true;}

            break;
        case 3:
        std::cout <<"\n Changing AUTHOR to: ";
            std::cin.getline(userInput, 31);
            strUpper(userInput);
            menuHelper.separateText();
            invbook.setAuthor(userInput);
            if(userInput[0] != '\0'){writeCheck = true;}

            break;
        case 4:
        std::cout <<"\n Changing DATE to: ";
            std::cin.getline(userInput, 11);
            strUpper(userInput);
            menuHelper.separateText();
            invbook.setDateAdded(userInput); 
            if(userInput[0] != '\0'){writeCheck = true;}
            break;
         case 5:
         std::cout <<"\n Changing PUBLISHER added to: ";
            std::cin.getline(userInput, 31);
            strUpper(userInput);
            menuHelper.separateText();
            invbook.setPub(userInput);
            if(userInput[0] != '\0'){writeCheck = true;}
            break;
         case 6:
         std::cout <<"\n Changing QUANTITY to: ";
            std::cin >> userQuantity;
            menuHelper.separateText();
            invbook.setQty(userQuantity);
                if(userQuantity > -1){writeCheck = true;}

            break;
         case 7:
         std::cout <<"\n Changing WHOLESALE value to: ";
            std::cin >> userPrice;
            menuHelper.separateText();
            invbook.setWholesale(userPrice);
            if(userPrice > -1 && userPrice <2147483647){writeCheck = true;}
            break;
        case 8:
            std::cout <<"\n Changing RETAIL value to: ";
            std::cin >> userPrice;
            menuHelper.separateText();
            invbook.setRetail(userPrice);
            if(userPrice > -1 && userPrice <2147483647){writeCheck = true;}
            break;
        case 9:



        if(writeCheck){
            bookFile.bookWrite(invbook, index);
        }else{
            invbook.removeBook();
            std::cout << "Failure to write...\n";
        }

            exitModule = true;
        std::cout <<"goodbye!\n";
            break;
        default:
        std::cout << "\nTry again!\n";
    }   
}

            
//https://stackoverflow.com/questions/38607754/how-to-force-file-flushing



}




void strUpper(char * wordToBeUppercase){
        int counter =0;
        while( *(wordToBeUppercase+counter) != '0' &&  std::isalpha(*(wordToBeUppercase + counter))){
            *(wordToBeUppercase+counter) =  std::toupper(wordToBeUppercase[counter]);
                counter++;
        }
}

int findBookIndex(std::string bookWant){
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

        std::strncpy(bookToBeSearched, bookWant.c_str(), 51);
        strUpper(bookToBeSearched);

        //ending byte

        std::cout << "\nBooks in storage: " << bookFile.storageSize() << std::endl;
        for(int i =0; i <bookFile.storageSize();i++){
            

            
            bookFile.bookRead(invbook, i);



            if(invbook.bookMatch(bookToBeSearched)){
                std::strncpy(found,  std::strstr(invbook.getTitle(), bookToBeSearched), 51);
            }else{
            
                continue;
            }

            if(found[0] != '\0'){

                //check if substring and book title are valid 
                if(!strcmp(found, invbook.getTitle()) && invbook.getTitle()[0] != '\0'){

                    bookIndex = i;

                        invbook.bookIndexInformation();
                        std::cout << "\nIs this your book(Y/N)?";
                        std::cin >> userInput;
                            menuHelper.separateText();
                    //if book is intended book exit loop
                        if((isalpha(userInput) && userInput == 'Y') ||(userInput == 'y')){
                            return bookIndex;
                        }else {
                            //else continue searching
                            std::cout << "\nNext book...\n\n";
                        }
                }    

        }

    }

    
    bookIndex = -1;

    return bookIndex;
}    //premature check