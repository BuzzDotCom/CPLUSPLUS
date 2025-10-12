#include "std_lib_facilities.h"






int main(){
  
 /*
  
  double ctok(double);
  double ktok(double c);
  double fahrenheit_celcius(double);
  double celcius_fahrenheit(double);
  
  
  
  int choice;
  
  double c = 0;
  double k = 0;
  double f = 0;

  cout << "celcius to kelvin (1) -- kelvin to celcius (2) \n"
       << "celcius to fahrenheit (3) -- fahrenheit to celcius (4): \n";

  cin >> choice;
  
  try{
  
  
     switch(choice){
    
       case 1:
  
  
  
  
           cout << "input celcius to be converted: \n";
           cin >> c;
           k = ctok(c);
           cout << "kelvin: " << k << "K" << '\n';
           break;
           
    
       case 2:
  
  
  
  
           cout << "input kelvin to be converted: \n";
           cin >> k;
           c = ktok(k);
           cout << "celcius: " << c << " celcius" << '\n';
           break;
           
           
       case 3:
  
  
  
  
           cout << "input celcius to be converted: \n";
           cin >> c;
           f = celcius_fahrenheit(c);
           cout << "fahrenheit: " << f << " fahrenheit" << '\n';
           break;
           
           
       case 4:
  
  
  
  
           cout << "input fahrenheit to be converted: \n";
           cin >> f;
           c = fahrenheit_celcius(f);
           cout << "celcius: " << c << " celcius" << '\n';
           break;
           
           
                    
           
           
           
           
           
           
     }
           
           
 
  }catch(const runtime_error& err){
    
    cerr << err.what();
    
    
    
  }
  
  */
  
 /*
  
  int to_sum = 0;
  double sum = 0;
  double num = 0;
  
  
  
  vector<double> nums;
  vector<double> diffs;
  
  
  
  
  
  cout << "\nhow many values to sum?: \n";
  
  cin >> to_sum;
  
  
  while(cin >> num){
    
    
    nums.push_back(num);
    
    
    
    
  }
  
  
  if(nums.size() < to_sum){
    
    
    cerr << "invalid, not enough data!\n";
    
    return 1;
    
    
    
  }
  
  
  
  
  for(int i = 0 ; i < to_sum ; ++i){
    
    
    sum += nums[i];
    
    
    
  }
  
  
  
  for(int i = 0; i < nums.size() - 1 ; ++i){
    
    
    diffs.push_back(abs( nums[i] - nums[i+1] ));
    
    
  }
  
  
  cout << "\ndifferences: \n";
  
  for(const auto& diff : diffs){
    
    cout << diff << '\n';
    
    
    
  }
  
  
  
  
  
  
  
  
  
  cout << "\nthe sum is: " << sum << '\n';
*/
  
 /*
 int int_max_value = numeric_limits<int>::max();
  
 int nth_fibbonaci(int n);
  
 for(int i = 1 ; nth_fibbonaci(i) < int_max_value ; ++i){
   
   cout << i << ": " << nth_fibbonaci(i) << '\n' ;
 }
  
*/

 void input_1_digit(int* digit);
 vector<int> bull_cow_count(vector<int> guess , vector<int> answer);




 
  
  
 
 vector<int> answer;
 vector<int> user_guess;
 vector<int> result;
 
 
 
 int user_digit;
 int size = 4;
 
 
 
 do{
 
 
   bool isCorrect = false;
 
   vector<int> digits = {0,1,2,3,4
                        ,5,6,7,8,9};
   //generate the answer
 
   for(int i = 1 ; i <= size ; ++i){
   
   
     default_random_engine rng(random_device{}()); //seed
   
   
     uniform_int_distribution<int> dist(0 , digits.size() - 1);
   
     int randomIndex = dist(rng);
   
     answer.push_back(digits[randomIndex]);
     digits.erase(digits.begin() + randomIndex);
   
   }
  


   //prompting the user until user got it right
   
   do{
      
      
     // prompt the user to guess
     for(int i = 1 ; i <= size ; ++i){
  
       cout << i << ": \n";
    
       input_1_digit(&user_digit);
   
       user_guess.push_back(user_digit);
  
     }


   

     // display the answer and also user guess
     cout << "\nanswer: ";
 
     for(int i = 0 ; i < size ; ++i){
   
         cout << answer[i];
   
   
     }
 
     cout << "\nguess : ";

     for(int i = 0 ; i < size ; ++i){
   
         cout << user_guess[i];
   
   
     }
 
     result = bull_cow_count(user_guess , answer);
   
     try{
     cout << "\n\nbull: " << result[0] << "\ncow: " << result[1] << '\n';

     }catch(...){
   
        cout << "invalid\n";
   
     }
     
     if(result[0] == size){
       
       isCorrect = true;
     }
     
     
     user_guess.clear();
     
     
     
     
   }while(!isCorrect);

   answer.clear();

   user_guess.clear();
   
   result.clear();
   
   
 }while(true);
 
 
 
}



void input_1_digit(int* digit){
  
  
  
  do{
  
  
     cin >> (*digit);
  
  }while( *digit < 0 || *digit > 9);
  
}






vector<int> bull_cow_count(vector<int> guess , vector<int> answer){
  
  int size = 4;
  
  vector<int> bull_cow = {0,0};
  
  
  
  if(guess.size() < size || answer.size() < size){
    
    throw runtime_error("invalid guess or answer\n");
    
  }
  
  
  
  
  
  
  for(int i = 0 ; i < size ; ++i){
    for(int j = 0 ; j < size ; ++j){
    
      if(guess[i] == answer[j]){
      
         if(i == j){
        
            ++(bull_cow[0]);
            continue;
         
         }
      
      ++(bull_cow[1]);
      
      }
      
    }
    
    
    
  }
  
  
  return bull_cow;
  
}




double ctok(double c){
  
  if(c < -273.15){
    throw runtime_error("invalid, celcius input below absolute zero\n");
  }
  
  double k = c + 273.25;
  
  return k;
  
  
  
}



double ktok(double k){
  
  if(k < 0){
    throw runtime_error("invalid, kelvin input below absolute zero\n");
  }
  
  
  double c = k - 273.25;
  
  return c;
  
  
  
}



double fahrenheit_celcius(double f){
  
  
  if(f < -241.25){
    throw runtime_error("invalid, fahrenheit input below absolute zero\n");
  }
  
  double c = (f - 32) * ( (double) 5 / 9);
  
  return c;
  
}



double celcius_fahrenheit(double c){
  
  
  if(c < -273.25){
     throw runtime_error("invalid, celcius input below absolute zero\n");
  }
  
  double f = ( (double) 9 / 5) * c + 32;
  
  return f;
  
}


int nth_fibbonaci(int n){
  
  if(n <= 0)
     throw runtime_error("invalid terms");
  
  else if(n == 1)
     return 0;
  else if(n == 2)
     return 1;
     
  return nth_fibbonaci(n-1) + nth_fibbonaci(n-2);
  
  
  
}




