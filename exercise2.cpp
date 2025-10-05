
#include "std_lib_facilities.h"

 void print_newline(){
   
   
   cout << "\n";
   
   
 }
 
 void print_digit(string number){
   
   if( number == "zero"){
     
     cout << 0 << "\n";
     
   }else if (number == "one"){
     
     cout << 1 << "\n";
     
   }else if (number == "two"){
     
     cout << 2 << "\n";
     
   }else if (number == "three"){
     
     cout << 3 << "\n";
     
   }else{
     
     cout << "not a number i know\n";
   }
   
   
 }
 
 





int main(){
  
  /*string previous;
  string current;
  
  cout << "test";
  
  while(cin >> current){
     if(previous == current)
        cout << "repeated word: " << current << '\n';
    previous = current;
  }*/
  
  /*
  string first_name;
  string friend_name;
  int age = -1;
  
  cout << "enter the name of the person you want to write to: ";
  cin >> first_name;
  print_newline();
  
  cout << "enter another friend's name: ";
  cin >> friend_name;     
  print_newline();
  
  cout << "enter the age of recipient: ";
  cin >> age;
  print_newline();
  
  if (age <= 0 || age >= 110){
      simple_error("you\'re kidding");
  }
  
  
  cout << "\n" << "Dear " << first_name << ",\n\n"
       << "How are you? I am fine. I miss you\n"
       << "i see you made progress regarding ABC. Good for you\n"
       << "Have you seen " << friend_name << " lately?\n"
       << "I hear you just had a birthday and you are " << age << " years old!\n";
  
  if(age > 70){
    
      cout << "Are you retired?";
    
  }else if (age == 17){
    
      cout << "Next year you will be able to vote!";
    
  }else if (age < 12){
    
      cout << "Next year you will be " << age + 1 << ".";
    
  }
  
  cout << "\n\nYours sincerely,\n\n" << "dava\n";
  
  */
  
  string num;
  
  cin >> num;
  
  print_digit(num);
  
  
  
  
  
  
  
  return 0;
  
  
  
}