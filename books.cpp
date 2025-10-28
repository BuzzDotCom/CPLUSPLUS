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

  private:

    string book_name;
    int page;
    bool marked;





};




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
            void update_book(string book_name);
            void remove_book(string book_name);


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

                output_file << book.get_name() << book.get_page() << book.bookmarked() << endl;




        }











        output_file.close();

}



void BookRack::list_books(){

        for(Book& book : book_container){

                cout << book.get_name() << " " << book.get_page() << " " << book.bookmarked() << "\n";



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






}




void BookRack::add_book(Book book){


     



}



void BookRack::update_book(string book_name){


     



}



void BookRack::remove_book(string book_name){


     



}













int main(){

    BookRack rack;
    

    rack.set_max(500);


    
    
    Book books("a" , 1 ,true);

    books.set_page(100);

    cout << books.get_page() << endl;
    cout << books.bookmarked() << endl;


    
    rack.load_books("books.txt");
     
    rack.list_books();


    rack.save_books("books.txt");



   return 0;


}
