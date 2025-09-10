#ifndef GLOBAL_header
#define GLOBAL_header

#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iomanip>

//general purpose functions/variables
    //swap

    

    
//bookinfo header 
    //regurgitates book information 
    void bookInfo(char[], char[], char[], char[], char[], int, double, double);
//inventory header
    //sorting quantity
    void quantitySort(int []);
    //sorting cost
    void costSort(int []);
    //sorting date
    void dateSort(int[]);
    //displaye date
    void displayDate();
    //convert entire c-string to uppercase
    void strUpper(char *word);
//connect inventory to entire program



class BookData{
    //Inventory book member variables/members
    protected:
        char bookTitle[51];
        char bookISBN[14];    
        char bookAuthor[31];
        char bookPublisher[31];


        
    public:
        //set functions for data
        void setTitle(char * title)
            { std::strncpy(bookTitle, title, 51);}  
        void setISBN(char *ISBN)
            { std::strncpy(bookISBN, ISBN, 14);}
        void setAuthor(char *author)
            { std::strncpy(bookAuthor, author, 31);}	 
        void setPub(char *publisher)
            { std::strncpy(bookPublisher, publisher, 31);}

        //overloaded functions for characters
            void setTitle(const char title)
            {bookTitle[0] = title;}
            void setISBN(const char ISBN)
            {bookISBN[0] = ISBN;}
            void setAuthor(const char author)
            {bookAuthor[0] = author;}
            void setPub(const char publisher)
            {bookPublisher[0] = publisher;}

        //get functions
        //char * is c-string
        char * getTitle() 
            {return bookTitle;}
        char * getISBN()
            {return bookISBN;}
        char * getAuthor()
            {return bookAuthor;}
        char * getPub()
            {return bookPublisher;}

        
        //initialize with null values
        BookData() noexcept {
            bookTitle[0] = '\0';
            bookISBN[0] = '\0'; 
            bookAuthor[0] = '\0';
            bookPublisher[0] = '\0';
        }



        bool bookMatch(std::string bookName){
            char userSearch[51];
            std::strcpy(userSearch, bookName.c_str());
                strUpper(userSearch);

            if ( std::strstr(bookTitle, userSearch)){return true;}

            return false;

        }

        //print book information at book index


        void printReport(std::string);
};







class InventoryBook: public BookData{
    private:

        double bookWholesaleValue;
        double bookRetailValue;
        int bookQtyOnHand;  
        char bookDateAdded[11]; 
   
 

       
        public:


        InventoryBook(): BookData(){

            bookDateAdded[0] = '\0';
            bookQtyOnHand = 0;    
            bookWholesaleValue = 0.0;
            bookRetailValue = 0.0;

        }

        
    
        ~InventoryBook(){}
        
        char * getDateAdded() {return bookDateAdded;}
         int getQty() const {return bookQtyOnHand;}
        double getWholesale() const {return bookWholesaleValue;}
        double getRetail() const {return bookRetailValue;}

        void setDateAdded(char *date){strncpy(bookDateAdded, date, 11);}
        void setDateAdded(char date){bookDateAdded[0] = date;}

        void setQty(int quantity) {bookQtyOnHand = quantity;}
        void setWholesale(double wholesale) {bookWholesaleValue = wholesale;}	 
        void setRetail(double retail) {bookRetailValue = retail;}


        bool isEmpty(){
            //checks for first character of Title at specified book index
            if(getTitle()[0] == '\0'){
                return true;
            }else{
                return false;
            }
        }


        void removeBook()
        {
            //remember to 
             
            setTitle('\0');
            setISBN('\0');
            setAuthor('\0');
            setPub('\0');

            bookDateAdded[0]= '\0';
            bookQtyOnHand = 0;
            bookRetailValue = 0.0;
            bookWholesaleValue = 0.0;
        }


        void bookIndexInformation(){
            bookInfo(bookTitle, 
                bookISBN, 
                bookAuthor, 
                bookDateAdded,
                bookPublisher,
                bookQtyOnHand, 
                bookWholesaleValue, 
                bookRetailValue);
        }
};








class SoldBook : public InventoryBook{

    private:
    static double taxRate;
    int qtySold;
    double subtotal;
    static double total;

    public:


    SoldBook(): InventoryBook(){
        taxRate = 0.06;
        qtySold = 0;
        subtotal = 0.0;
        total = 0.0;

    }


    void setTaxRate(double rate)
    {taxRate = rate;}
    void setQtySold(double qty)
    { qtySold = qty;}
    void setSubTotal(double subcost)
    {subtotal = subcost;}
    void  setTotal(double totalcost)
    {total = totalcost;}

    double getTaxRate() const{return taxRate;}
    int getQtySold()        const{return qtySold;};
    double getSubTotal() const{return subtotal;}
    double getTotal() const {return total;}


};





class BookStorage{

        private:

        std::fstream bookFile;
        public:

        BookStorage(){bookFile.open("../bin/binbooks.txt", std::ios::binary | std::ios::out | std::ios::in);}



        void bookWrite(InventoryBook &book, int bookIndex){
            this->bookFile.clear();
            this->bookFile.seekp(sizeof(InventoryBook) * bookIndex, std::ios::beg);
            this->bookFile.write(reinterpret_cast<char *>(&book), sizeof(InventoryBook));
            this->bookFile.flush();
        } 

        void bookWrite(InventoryBook &book){
            this->bookFile.clear();
            this->bookFile.seekp(0L, std::ios::end);
            this->bookFile.write(reinterpret_cast<char *>(&book), sizeof(InventoryBook));
            this->bookFile.flush();

        } 



        int storageSize(){
            this->bookFile.clear();
            this->bookFile.seekp(0L, std::ios::end);
            return this->bookFile.tellp()/sizeof(InventoryBook);
        }


  
        void bookRead(InventoryBook &book, int bookIndex) {
            this->bookFile.clear();
            this->bookFile.seekg(sizeof(InventoryBook) * bookIndex, std::ios::beg);
            if (this->bookFile.read(reinterpret_cast<char *>(&book), sizeof(InventoryBook))) {
            }
        }


        ~BookStorage(){bookFile.close();}




};


// Bookdata Object 
extern InventoryBook invbook;

//Inventory File -> "reports.txt"
extern BookStorage bookFile;





//cashier header
    //prompts user to purchase book
    void cashier();
    //finds index of book ISBN
    int ISBNLookup(std::string, SoldBook &);



class Menu: public SoldBook{
    private:
    std::string userInput;
    public:

    Menu() noexcept{
        userInput = "";
    }



    void displayDate() noexcept{
        time_t day;
        time(&day);
        std::cout << ctime(&day);
    }


    
    void separateText() noexcept {
        for(int i =0; i< 100; i++){std::cout << '-';}
        std::cout << '\n';
    }



    void forcedUserWait(){
        char userInput;
        std::cout << '\n';
        std::cout << "\nPress enter to continue.";
            std::cin.get(userInput);
            std:: cout << "\n\n\n";
      }
        

    void menuOutput(std::string input) noexcept {

        if(input == "MainMenu"){
            std::cout << "\n\n\n";
            std::cout << std::setw(20) << ' ' << "Serendipity Booksellers " <<  std::endl;
            std::cout << std::setw(25) << ' ' << "Main Menu" << "\n\n";
            std::cout << std::setw(15) << ' ' << "1.	Cashier Module" <<  std::endl;
            std::cout << std::setw(15) << ' ' << "2.	Inventory Database Module" <<  std::endl;
            std::cout << std::setw(15) << ' ' << "3.	Report Module" <<  std::endl;
            std::cout << std::setw(15) << ' ' << "4.	Exit" <<  std::endl;
            std::cout << "\n\n" << std::setw(15) << ' ' << "Enter your choice: ";
        }

        if(input == "Cashier"){
            std::cout << '\n' << std::setw(20) << ' ' << "Serenpidity Booksellers" <<  std::endl;
            std::cout <<         std::setw(25) << ' ' << "Cashier Module" << std::endl;        
            std::cout << "How many books do you want?"<<  std::endl;
            std::cout << "# of books purchased today: ";

        }
        if(input == "Inventory"){
            std::cout << std::setw(20) << ' ' << " Serendipity Booksellers" <<  std::endl;
            std::cout << std::setw(23) << ' ' << "Inventory Database\n\n";
            std::cout << std::setw(15) << ' ' << "1.	Look Up a Book"        <<  std::endl;
            std::cout << std::setw(15) << ' ' << "2.       Add a Book"      <<  std::endl;
            std::cout << std::setw(15) << ' ' << "3.	Edit a Book's Record"  <<  std::endl;
            std::cout << std::setw(15) << ' ' << "4.	Delete a Book"         <<  std::endl;
            std::cout <<std:: setw(15) << ' ' << "5.	Return to the Main Menu"  <<  std::endl;
            std::cout << '\n' << std::setw(15) << ' ' << "Enter your choice: ";
        }
        if(input == "Report"){
            std::cout << std::setw(20) << ' ' << "Serendipity Booksellers" <<  std::endl;
            std::cout << std::setw(25) << ' ' << "Reports\n\n";
            std::cout << std::setw(15) << ' ' << "1.	Inventory Listing" <<  std::endl;
            std::cout << std::setw(15) << ' ' << "2.\tInventory Wholesale Value" <<  std::endl;
            std::cout << std::setw(15) << ' ' << "3.	Inventory Retail Value" <<  std::endl;
            std::cout << std::setw(15) << ' ' << "4.	Listing by Quantity" <<  std::endl;
            std::cout << std::setw(15) << ' ' << "5.	Listing by Cost" <<  std::endl;
            std::cout << std::setw(15) << ' ' << "6.	Listing by Age" <<  std::endl;
            std::cout << std::setw(15) << ' ' << "7.	Return to Main Menu" <<  std::endl;
            std::cout << std::setw(15) << ' ' << "Enter Your Choice: ";
        }

        if(input == "InventoryEdit"){
            
            std::cout << std::setw(20) << ' ' << " Serendipity Booksellers" <<  std::endl;
            std::cout << std::setw(23) << ' ' << "Inventory Database" <<  std::endl;
            std::cout << std::setw(15) << ' ' << "1   Title" <<  std::endl;
            std::cout << std::setw(15) << ' ' << "2.  ISBN" <<  std::endl;
            std::cout << std::setw(15) << ' ' << "3.	Author" <<  std::endl;
            std::cout << std::setw(15) << ' ' << "4.	Publisher" <<  std::endl;
            std::cout << std::setw(15) << ' ' << "5.	Date Added" <<  std::endl;
            std::cout << std::setw(15) << ' ' << "6.	Quantity" <<  std::endl;
            std::cout << std::setw(15) << ' ' << "7.	Wholesale price" <<  std::endl;
            std::cout << std::setw(15) << ' ' << "8.	Retail Price" <<  std::endl;
            std::cout << std::setw(15) << ' ' << "9.	Exit\n\n";
    
        }

    }

    void cashierOutput(std::string input) noexcept{


        if(input == "Transaction"){

            std::cout << "\nDate:\t";
            displayDate();

            std::cout <<std::left<< std::setw(5) << "Qty" <<std:: setw(20) << "ISBN" << std::setw(40) << "Title" << std::setw(10) << "Price"  << std::setw(3) << "Total"<< std::endl;
            separateText();

            
        }
    }
    
    void printError(){
        static int counter{1};
        std::cout << "\nERROR! input/output doesnt work/\n\n" << "\n This is error number " << counter << std::endl;
        counter++;
    }

};


extern Menu menuHelper;




//functions for inventory management
    //inventory menu header
        void invMenu();
        void invCheck(int);
        void lookUpBook();
        void addBook();
        void editBook();
        void deleteBook();
        void editInventoryInput(int);
        int findBookIndex(std::string); 
    //report header
        void reports();
        void reportsCheck(int);
        void repListing();
        void repWholesale();
        void repRetail();
        void repQty();
        void repCost();
        void repAge();
#endif
