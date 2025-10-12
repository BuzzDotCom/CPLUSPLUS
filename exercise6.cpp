#include "std_lib_facilities.h"

class Name_Value{

    public:
          string name;
          int score;

          Name_Value(string name_ , int score_) : name(name_) , score(score_) {}
          Name_Value(string name_) : name(name_) , score(0) {}

};






int main(){

   string name;
   int score = 0;
   vector<Name_Value> name_value_vect;


   cout << "enter name & score: \n"; 
   while(cin >> name >> score ){
    
   
    if(name == "noname" && score == 0) break;
    
    name_value_vect.emplace_back(Name_Value(name,score));

   }





}