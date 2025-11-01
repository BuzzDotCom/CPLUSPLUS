#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------



class Book{

  public:

     string get_name();

     int get_page();
     void set_page(int p);
     

     void set_mark(bool flag);
     bool bookmarked();
    
     Book (string book)                                : book_name(book) , page(0) ,  marked(false)      { }
     Book (string book , int page_)                    : book_name(book) , page(page_) , marked(false)   { }
     Book (string book , int page_ , bool marked_)     : book_name(book) , page(page_) , marked(marked_) { }

     friend istream& operator>>(istream& is , Book& book);
     friend ostream& operator<<(ostream& os , const Book& book);

  private:

    string book_name;
    int page;
    bool marked;





};


istream& operator>>(istream& is , Book& book){

    
    is >> book.book_name >> book.page >> book.marked;
    return is;
}


ostream& operator<<(ostream& os , const Book& book){

    os << "\"" << book.book_name << "\"" << endl 
       << "Page: " << book.page;
    return os;


}



void Book::set_page(int p){

      page = p;




}


int Book::get_page(){

     return page;








}


string Book::get_name(){


    return book_name;


}

void Book::set_mark(bool flag){

    marked = flag;

}


bool Book::bookmarked(){

    return marked;

}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class BookRack{

    

    public:

            void set_max(int max);
            int get_max();

            void load_books(string file_name);
            void save_books(string file_name);
            void list_books();

            void mark_unmark(string book_name);
            void list_bookmarks();
            
            void add_book(string book_name);
            void update_book();
            void remove_book();


    private:
            int max_books;
            int book_count;
            vector<Book> book_container;
            




};

void BookRack::set_max(int max){

        max_books = max;




}

int BookRack::get_max(){

        return max_books;




}


void BookRack::load_books(string file_name){

        ifstream input_file;
        input_file.open(file_name);

        
        if(!input_file.is_open()){
            cerr << "error\n";
            return;

        }

        Book book("");
        while(input_file >> book){
             book_container.push_back(book);
             ++book_count;
        }
        input_file.close();
}


void BookRack::save_books(string file_name){

        ofstream output_file;
        output_file.open(file_name);

        if(!output_file.is_open()){
             
            cerr << "error\n";
            return;

        }

        for(Book& book : book_container ){

                output_file << book.get_name() << ' ' << book.get_page() << ' ' << book.bookmarked() << endl;




        }











        output_file.close();

}



void BookRack::list_books(){

        int entry = 1;
        for(Book& book : book_container){

                cout << entry << ". " <<  book << "\n";
                ++entry;


        }




}




void BookRack::mark_unmark(string book_name){


     for(Book& book : book_container){

        if(book_name == book.get_name()){

            book.set_mark(!(book.bookmarked()) );

        }

     }




}

void BookRack::list_bookmarks(){

      int entry = 1;
      for(Book book : book_container){
            if(book.bookmarked()){

                cout << entry << ". " <<  book << "\n";
                ++entry;
            }
      }
}




void BookRack::add_book(string book_name){

     for(Book book : book_container){
            if(book_name == book.get_name()){
                  return;
            }
     }
     book_container.emplace_back(Book(book_name));
}



void BookRack::update_book(){

    int entry = 0;
    int page = 0;

     cout << "Enter book number: "; cin >> entry;
     
     if(entry < 1 || entry > book_count){
           return;
     }

     cout << "Update \"" << book_container[entry - 1].get_name() << "\" to page: "; cin >>  page;
     book_container[entry - 1].set_page(page);

}



void BookRack::remove_book(){


     int entry = 0;
     string temp;
     cout << "Enter book number to be removed: "; cin >> entry;

     if(entry < 1 || entry  > book_count){
              return;
     }
     
     temp = book_container[entry - 1].get_name();
     book_container.erase(book_container.begin() + entry - 1);

     
     cout << "\"" << temp << "\" removed";
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------







int main(){
  
    void getBuffered();
    
    
    BookRack rack;
    rack.load_books("books.txt");
    rack.set_max(500);
 
    char choice = '0';
   
    while(true){
    
        cout << "\x1b[H\x1b[2J";
        cout << "\nMenu:\n";
        
        
        cout << "f. Fill Daily Reading Target\n";
        cout << "l. Bookmarks List\n";
        cout << "x. Mark or Unmark A Book\n";
        cout << "b. Books List\n";
        cout << "a. Add A Book\n";
        cout << "u. Update A Book\n";
        cout << "r. Remove A Book\n";
        cout << "q. Quit\n";
        
        
        cout << "\nEnter menu choice: "; cin >> choice; cout << '\n';
        
        switch(choice){
            
            
            case 'f' :
            
            {
              
               rack.list_bookmarks();
              
               rack.save_books("books.txt");
               
               rack.list_bookmarks();
               break;
              
            }
            
            
            
            case 'l' :
            {
               rack.list_bookmarks();
               break;
              
            }
            
            
            case 'x' :
            {
               
               string book_name;
              
              
               rack.list_books();
               
               cout << "Enter book to change: "; cin >> book_name;
               
               rack.mark_unmark(book_name);
               
               rack.save_books("books.txt");
               
               rack.list_bookmarks();
               break;
              
            }
            
            
            case 'b' :
            {
               rack.list_books();
               break;
              
            }
            
            
            case 'a' :
            {
               string book_name
               
               rack.list_books();
               
               cout << "Enter the name of the book you want to add: "; cin >> book_name;
               rack.add_book(book_name);
               rack.save_books("books.txt");
               
               rack.list_books();
              
            }
            
            
            case 'u' :
            {
                 rack.list_books();
                 rack.update_book();
                 rack.save_books("books.txt");
                 rack.list_books();
                 break;
              
              
            }
            
            
            case 'r' :
            {
                 rack.list_books();
                 rack.remove_book();
                 rack.save_books("books.txt");
                 rack.list_books();
                 break;
              
            }
            
            
            case 'q' :
            {
              
                 return 0;
              
            }
            
            default:
            
            cout << "\ninvalid choice. please try again!\n";
              
        }
        
    }
    
    return 0;
    
}
