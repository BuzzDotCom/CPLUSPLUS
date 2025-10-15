#include "std_lib_facilities.h"

class Name_Value{

    public:
          string name;
          int score;

          Name_Value(string name_ , int score_) : name(name_) , score(score_) {}
          Name_Value(string name_) : name(name_) , score(0) {}

};


int fact(int i){
  
  if(i == 1 || i == 0){
    
    return 1;
    
  }
  
  return i * fact(i-1);
  
  
}

float permutation(int a , int b){
  
  
  return fact(a) / fact(a - b);
  
  
}

float combination(int a , int b){
  
  return permutation(a,b) / fact(b);
  
}


/*int main(){

   string name;
   int score = 0;
   vector<Name_Value> name_value_vect;


   cout << "enter name & score: \n"; 
   while(cin >> name >> score ){
    
   
    if(name == "noname" && score == 0) break;
    
    name_value_vect.emplace_back(Name_Value(name,score));

   }





}*/


/*int main(){
  
  char c = '\0';
  int num = 0;
  int counter = 0;
  vector<int> list;
  
  
  while(cin >> c && c >= '0' && c <= '9'){
    
    
    ++counter;
    
    num = c - '0';
    
    list.push_back(num);
    
    
  }
  
  switch(counter){
    
    case 1:
    
           cout << list[0] << " ones\n";
           break;
    
    case 2:
    
           cout << list[0] << " tens " << list[1] << " ones\n";
           break;
    
    case 3:
    
           cout << list[0] << " hundreds " << list[1] << " tens " << list[2] << " ones\n";
           break;
    
    case 4:
    
           cout << list[0] << " thousands " << list[1] << " hundreds " << list[2] << " tens " << list[3] << " ones \n";
           break;
    
    
    default: cout << "Too many digits\n";
    
    
    
    
    
  }
  
  
}*/



int main(){
  
  
  
  
  
  
  
  
  
}







