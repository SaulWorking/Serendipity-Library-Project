#ifndef general_header
#define general_header

#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
//general purpose functions/variables
    //swap
    void swap(int &, int &);
    void swap(double &, double &);

//bookinfo header 
    //regurgitates book information 
    void bookInfo(char[], char[], char[], char[], char[], int, double, double);
//cashier header
    //prompts user to purchase book
    void cashier();
    //finds index of book ISBN
    int ISBNLookup(string);
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
    private:
        char bookTitle[51];
        char bookISBN[14];    
        char bookAuthor[31];
        char bookPublisher[31];
    public:
        //set functions for data
        void setTitle(char * title)
            {strncpy(bookTitle, title, 51);}  
        void setISBN(char *ISBN)
            {strncpy(bookISBN, ISBN, 14);}
        void setAuthor(char *author)
            {strncpy(bookAuthor, author, 31);}	 
        void setPub(char *publisher)
            {strncpy(bookPublisher, publisher, 31);}

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
        BookData(){
            bookTitle[0] = '\0';
            bookISBN[0] = '\0'; 
            bookAuthor[0] = '\0';
            bookPublisher[0] = '\0';
        }



        bool bookMatch(string bookName){
            char userSearch[51];
            strcpy(userSearch, bookName.c_str());
            strUpper(userSearch);

            if (strstr(bookTitle, userSearch)){return true;}

            return false;

        }

        //print book information at book index


        void printReport(string);
};

class InventoryBook: public BookData{
    private:

        char bookDateAdded[11]; 
        int bookQtyOnHand;     
        double bookWholesaleValue;
        double bookRetailValue;

    public:


        InventoryBook(): BookData(){

            bookDateAdded[0] = '\0';
            bookQtyOnHand = 0;    
            bookWholesaleValue = 0.0;
            bookRetailValue = 0.0;

        }

        
    
        ~InventoryBook(){}
        
        char * getDateAdded() {return bookDateAdded;}
        virtual int getQty() const {return bookQtyOnHand;}
        double getWholesale() const {return bookWholesaleValue;}
        double getRetail() const {return bookRetailValue;}

        void setDateAdded(char *date){strncpy(bookDateAdded, date, 11);}
        void setDateAdded(char date){bookDateAdded[0] = date;}

        virtual void setQty(int quantity) {bookQtyOnHand = quantity;}
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
            //remember to write this change in file
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
            bookInfo(
            getTitle(), 
            getISBN(), 
            getAuthor(),
            getPub(),
            
            bookDateAdded,
            bookQtyOnHand, 
            bookWholesaleValue, 
            bookRetailValue);
        }

};

class BookStorage{

        private:

        fstream bookFile;
        public:

        BookStorage(){bookFile.open("reports.txt", ios::binary | ios::out | ios::in);}


        // overwrite /\ write at any index
        void bookWrite(BookData book, int bookIndex){
            this->bookFile.clear();
            this->bookFile.seekp(sizeof(book) * bookIndex, ios::beg);
            this->bookFile.write(reinterpret_cast<char *>(&book), sizeof(book));
            this->bookFile.flush();

        } 


        //write to the end of the file
        void bookWrite(BookData book){
            this->bookFile.clear();
            this->bookFile.seekp(0L, ios::end);
            this->bookFile.write(reinterpret_cast<char *>(&book), sizeof(book));
            this->bookFile.flush();

        } 



        int storageSize(){
            bookFile.clear();
            this->bookFile.seekp(0L, ios::end);
            return this->bookFile.tellp()/sizeof(InventoryBook);
        }


        BookData bookRead(BookData book, int bookIndex){
            this->bookFile.clear();
            this->bookFile.seekg(sizeof(book) * bookIndex, ios::beg);
            if (!this->bookFile.eof()) {
                this->bookFile.read(reinterpret_cast<char *>(&book), sizeof(book));
                return book;
            }
            return book;
        }
        
        InventoryBook bookRead(InventoryBook book, int bookIndex){
            this->bookFile.clear();
            this->bookFile.seekg(sizeof(book) * bookIndex, ios::beg);
            if (!this->bookFile.eof()) {
                this->bookFile.read(reinterpret_cast<char *>(&book), sizeof(book));
                return book;
            }
            return book;
        }


        SoldBook bookRead(SoldBook book, int bookIndex){
            this->bookFile.clear();
            this->bookFile.seekg(sizeof(book) * bookIndex, ios::beg);
            if (!this->bookFile.eof()) {
                this->bookFile.read(reinterpret_cast<char *>(&book), sizeof(book));
                return book;
            }
            return book;
        }

        ~BookStorage(){bookFile.close();}




};

class SoldBook : public InventoryBook{

    private:
    static double taxRate;
    int qtySold;
    double subtotal;
    static double total;

    public:


    SoldBook(){
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


// Bookdata Object 
extern InventoryBook invbook;

//Inventory File -> "reports.txt"
extern BookStorage bookFile;







class Menu: public SoldBook{
    private:
    string userInput;
    public:

    Menu(){
        userInput = "";
    }



    void displayDate(){
        time_t day;
        time(&day);
        cout << ctime(&day);
    }


    
    void separateText(){
        for(int i =0; i< 100; i++){cout << '-';}
        cout << '\n';
    }



    void forcedUserWait(){
        string userInput;
        cout << '\n';
            cout << "\nPress enter to continue.";
            getline(cin, userInput);
        cout << "\n\n\n";
      }
        

    void menuOutput(string input){

        if(input == "MainMenu"){
            cout << "\n\n\n";
            cout << setw(20) << ' ' << "Serendipity Booksellers " << endl;
            cout << setw(25) << ' ' << "Main Menu" << "\n\n";
            cout << setw(15) << ' ' << "1.	Cashier Module" << endl;
            cout << setw(15) << ' ' << "2.	Inventory Database Module" << endl;
            cout << setw(15) << ' ' << "3.	Report Module" << endl;
            cout << setw(15) << ' ' << "4.	Exit" << endl;
            cout << "\n\n" << setw(15) << ' ' << "Enter your choice: ";
        }

        if(input == "Cashier"){
            cout << '\n' << setw(20) << ' ' << "Serenpidity Booksellers" << endl;
            cout <<         setw(25) << ' ' << "Cashier Module\n";
            cout << "How many books do you want?\n";
            cout << "Book quantity: ";

        }
        if(input == "Inventory"){
            cout << setw(20) << ' ' << " Serendipity Booksellers" << endl;
            cout << setw(23) << ' ' << "Inventory Database\n\n";
            cout << setw(15) << ' ' << "1.	Look Up a Book"        << endl;
            cout << setw(15) << ' ' << "2.       Add a Book"      << endl;
            cout << setw(15) << ' ' << "3.	Edit a Book's Record"  << endl;
            cout << setw(15) << ' ' << "4.	Delete a Book"         << endl;
            cout << setw(15) << ' ' << "5.	Return to the Main Menu"  << endl;
            cout << '\n' << setw(15) << ' ' << "Enter your choice: ";
        }
        if(input == "Report"){
            cout << setw(20) << ' ' << "Serendipity Booksellers\n";
            cout << setw(25) << ' ' << "Reports\n\n";
            cout << setw(15) << ' ' << "1.	Inventory Listing\n";
            cout << setw(15) << ' ' << "2.\tInventory Wholesale Value\n";
            cout << setw(15) << ' ' << "3.	Inventory Retail Value\n";
            cout << setw(15) << ' ' << "4.	Listing by Quantity\n";
            cout << setw(15) << ' ' << "5.	Listing by Cost\n";
            cout << setw(15) << ' ' << "6.	Listing by Age\n";
            cout << setw(15) << ' ' << "7.	Return to Main Menu\n";
            cout << setw(15) << ' ' << "Enter Your Choice: ";
        }

        if(input == "InventoryEdit"){
            
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
    
        }

    }

    void cashierOutput(string input, int checkoutQuantity, double checkoutPrice){

        const double salesTax = 0.06;

        if(input == "Transaction"){

            cout << "\nDate:\t";
            displayDate();

            cout  << left<< setw(5) << "Qty" << setw(20) << "ISBN" << setw(40) << "Title" << setw(10) << "Price"  << setw(3) << "Total"<< endl;
            separateText();

            cout << '\n' << setw(4)  << left << fixed << setprecision(2) << getQtySold() << setw(20) << invbook.getISBN() << setw(40) << invbook.getTitle()  << " $" << setw(9) << invbook.getRetail() << "$"  << getSubTotal() << endl;
            cout << "\n\n\n";

            cout << setw(61)  << "\t\tSubtotal" << "$" << checkoutPrice << endl; 
            cout << setw(61)  << "\t\tTax"      << "$" << checkoutPrice * salesTax << endl;
            cout << setw(61)  << "\t\tTotal"    << "$" << checkoutPrice + (checkoutPrice * salesTax) << endl;        
        }

    }
    
    void printError(){
        static int counter{1};
        cout << "\nERROR! input/output doesnt work/\n\n" << "\n This is error number " << counter << endl;
        counter++;
    }

};


extern Menu menuHelper;







/*
previous data structure

extern char bookTitle[20][51];
extern char bookISBN[20][14];    
extern char bookAuthor[20][31];
extern char bookPublisher[20][31];
extern char bookDateAdded[20][11]; 
extern int bookQtyOnHand[20];
extern double bookWholesaleValue[20];
extern double bookRetailValue[20];
*/




//functions for inventory management
    //inventory menu header
        void invMenu();
        void invCheck(int);
        void lookUpBook();
        void addBook();
        void editBook();
        void deleteBook();
        void editInventoryInput(int);
        int findBookIndex(string); 
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
