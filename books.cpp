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

     string& get_name() ;

     const int& get_page() const;
     void set_page(int p);
     

     void set_mark(bool flag);
     bool bookmarked();
    
     Book ()                                           : book_name(" ")   , page(0)     ,  marked(false)      { }
     Book (string book)                                : book_name(book) , page(0)     ,  marked(false)      { }
     Book (string book , int page_)                    : book_name(book) , page(page_) , marked(false)       { }
     Book (string book , int page_ , bool marked_)     : book_name(book) , page(page_) , marked(marked_)     { }

     friend istream& operator>>(istream& is , Book& book);
     friend ostream& operator<<(ostream& os , const Book& book);

  private:

    string book_name;
    int page;
    bool marked;





};


istream& operator>>(istream& is , Book& book){

    is >> ws;
    
    getline(is , book.book_name);
  
    is >> book.page >> book.marked;
    
    return is;
    
}


ostream& operator<<(ostream& os , const Book& book){
    
    
    
    if(book.page <= 0){
      os << "\"" << book.book_name << "\"" << endl;
    
      return os;
    }
    
    os << "\"" << book.book_name << "\"" << endl;
    os << "Page: " << book.page << endl;
    return os;


}



void Book::set_page(int p){

      page = p;




}


const int& Book::get_page() const{

     return page;








}


 string& Book::get_name() {


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
            

            const vector<Book>& get_rack() const;
            void set_max(int max);
            const int& get_max() const;
            Book& get_entry(int entry);
            
            void load_books(string file_name);
            void save_books(string file_name);
            void list_books();

            void mark_unmark(int entry);
            void list_bookmarks();
            
            void add_book(string book_name);
            void update_book(int entry , int page);
            void remove_book(int entry);
            void daily_update(int entry);
            
            Book& get_empty();

    private:
    
            int max_books;
            int book_count;
            vector<Book> book_container;
            Book empty;
            




};

const vector<Book>& BookRack::get_rack() const{
  
      return book_container;
  
}

void BookRack::set_max(int max){

        max_books = max;




}


const int& BookRack::get_max() const{

        return max_books;




}


 Book& BookRack::get_entry(int entry){
  
        if (entry < 1 || entry > book_count)
              
              return get_empty();
  
        return book_container[entry - 1];
  
  
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

                output_file << book.get_name() << '\n' << book.get_page() << ' ' << book.bookmarked() << '\n';

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




void BookRack::mark_unmark(int entry){
     if(entry >= 1 && entry <= book_count)
        get_entry(entry).set_mark(!( get_entry(entry).bookmarked() ));
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

     for(Book& book : book_container){
            if(book_name == book.get_name()){
                  return;
            }
     }
     
     book_container.emplace_back(Book(book_name));
     ++book_count;
}



void BookRack::update_book(int entry, int page){
  
     if(entry < 1 || entry > book_count){
           return;
     }
     get_entry(entry).set_page(page);

}



void BookRack::remove_book(int entry){

     if(entry - 1 < 0 || entry - 1  >= book_count)
        return;
     
     book_container.erase(book_container.begin() + entry - 1);
     --book_count;
}

void BookRack::daily_update(int entry){
  
    if(entry < 1 || entry > book_count){
            return;
    }
    int page = get_entry(entry).get_page() + 20;
    get_entry(entry).set_page(page);
  
}



Book& BookRack::get_empty(){
  
  
  return empty;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------







int main(){
  
    void getBuffered();
    
    
    
    
    
    
    char choice = '0';
    string buffer;
    
    
    while(true){
      
        BookRack rack; // load inside the loop so the file and the "rack" synchronize both ways
        rack.load_books("books.txt"); rack.set_max(500);
        
        //cout << "\x1b[H\x1b[2J"; cout << "\nMenu:\n\n";
        try{
  
        cout << "f. Fill Daily Reading Target\n";
        cout << "l. Bookmarks List\n";
        cout << "x. Mark or Unmark A Book\n";
        cout << "b. Books List\n";
        cout << "a. Add A Book\n";
        cout << "u. Update A Book\n";
        cout << "r. Remove A Book\n";
        cout << "q. Quit\n";
        
        
        cout << "\nEnter menu choice: "; cin >> choice; cout << '\n';
        cin.ignore(256,'\n'); 
        
        
        switch(choice){
            
            
            case 'f' :
            
            {
               int entry;
              
               rack.list_bookmarks();
               cout << "Enter book number to be updated: "; cin >> entry;
               rack.daily_update(entry);
               rack.save_books("books.txt");
               
               rack.list_books();
               
               cin.clear();
               getline(cin,buffer);
               break;
              
            }
            
            
            
            case 'l' :
            {
               rack.list_bookmarks();
               break;
              
            }
            
            
            case 'x' :
            {
               
               int entry;
              
              
               rack.list_books();
               
               cout << "Enter book number to be changed: "; cin >> entry;
               
               rack.mark_unmark(entry);
               
               rack.save_books("books.txt");
               
               rack.list_bookmarks();
               
               
               cin.clear();
               getline(cin,buffer);
               break;
              
            }
            
            
            case 'b' :
            {
               rack.list_books();
               break;
              
            }
            
            
            case 'a' :
            {
               string book_name;
               
               rack.list_books();
               
               cout << "Enter the name of the book you want to add: "; getline(cin,book_name);
               
               if(book_name == "") break;
               rack.add_book(book_name);
               rack.save_books("books.txt");
               rack.list_books();
               cout << "\"" << book_name << "\" added";
               break;
              
            }
            
            
            case 'u' :
            {
                 int entry; int page;
                 
                 rack.list_books();
                 cout << "Enter book number to be updated: "; 
                 if(cin >> entry && (rack.get_entry(entry).get_name() != " ") ){
                   cout << "Update \"" << rack.get_entry(entry).get_name() << "\" to page: ";
                   if( cin >> page){
                      rack.update_book(entry , page);
                      rack.save_books("books.txt");
                      rack.list_books();
                   }
                 }
                 
                 cin.clear();
                 getline(cin,buffer);
                 break;
              
              
            }
            
            
            case 'r' :
            {
              
                 int entry;
                
                 rack.list_books();
                 cout << "Enter book number to be removed: "; 
                 
                 if(cin >> entry){
                    string temp = rack.get_entry(entry).get_name();
                    rack.remove_book(entry);
                    rack.save_books("books.txt");
                   rack.list_books();
                    cout  << "\"" << temp << "\" removed \n";
                 
                   
                 }
                 
                 cin.clear();
                 getline(cin,buffer);
                 break;
              
            }
            
            
            case 'q' :
            {
              
                 return 0;
              
            }
            
            default:
            
                 cout << "\ninvalid choice. please try again!\n";
              
        }
        
        getline(cin,buffer);
        }catch(...){
          
          
          
        }
    }
    
    return 0;
    
}
