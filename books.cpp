#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

int compare_string(string string1 , string string2);
void concat(string result , string string1 , string string2);

int compare_string(string string1 , string string2){


    return 0;
}





void concat(string result , string string1 , string string2){











}





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


     friend ostream& operator<<(ostream& os , const Book& book);

  private:

    string book_name;
    int page;
    bool marked;





};

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


class BookRack{

    

    public:

            void set_max(int max);
            int get_max();

            void load_books(string file_name);
            void save_books(string file_name);
            void list_books();

            void mark_book(string book_name , bool marked);
            void list_bookmarks();
            
            void add_book(Book book);
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

        string name;
        int page;
        bool marked;
        

        while(input_file >> name >> page >> marked){

             book_container.push_back(Book(name,page,marked));


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




void BookRack::mark_book(string book_name , bool marked){


     for(Book& book : book_container){

        if(book_name == book.get_name()){

            book.set_mark(marked) ;

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




void BookRack::add_book(Book new_){

     for(Book book : book_container){
            if(new_.get_name() == book.get_name()){
                  return;
            }
     }
     book_container.push_back(new_);
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
     cout << "Enter book number to ne removed: "; cin >> entry;

     if(entry < 1 || entry  > book_count){
              return;
     }
     

     book_container.erase(book_container.begin() + entry - 1);


}













int main(){

    BookRack rack;
    

    rack.set_max(500);


    
    
    Book books("a" , 1 ,true);

    books.set_page(100);

    cout << books.get_page() << endl;
    cout << books.bookmarked() << endl;


    
    rack.load_books("books.txt");

    rack.add_book(Book("tesfdst" , 24214214 , 1));
     
    rack.list_books();

    cout << "\n\n";
    rack.list_bookmarks();

    rack.update_book();
    rack.remove_book();

    cout << "\n\n";
    
    
    rack.list_books();
    
    
    rack.save_books("books.txt");



   return 0;


}
