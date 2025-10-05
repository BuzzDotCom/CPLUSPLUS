#include "std_lib_facilities.h"

int main(){
  
  /*
  string input;
  
  
  
  cout << "enter a string:\n";
  getline(cin ,input);
  
  for(char c : input){
    
  
    cout << c << "  " << int(c) << "\n";
  
  
    
  }
  */
  
  
  
  vector<double> quadratic(double a , double b , double c);
  double mode (vector<double>);
  double calculator(double num1, double num2 , char op);
  int guess_number(int num , int low , int high);
  void input_double(vector<double>*);
  double sum(vector<double>vect);
  double mean(vector<double>vect);
  double mean(vector<double> vect);
  double max(vector<double>vect);
  double min(vector<double>vect);
  double median(vector<double> vect);
  long long int grain_rice(int square);
  
  
  
  /*
  double num1 , num2;
  char op;
  double result;
  
  bool isRun = true;
  
  while(isRun){
    
      
      cout << "\nenter operands 1, operator and also operands 2:\n";
      
      
      
      cin >> num1 >> op >> num2;
      
      result = calculator(num1 , num2 , op);
      
      if(result != -0.987){
        
      
         cout << "\n" << "result of " << num1 << " " << op  << " " << num2 << " is " << result << "\n";
      }
  
    
  }
*/
  
  /*
  int num;
  
  cout << "input an int between 1 and 100\n";
  
  do{
  cin >> num;
  }while( num < 1 || num > 100);
  
  cout << "your number must be " << guess_number(num , 1, 100) << "\n";
  
  
  vector<double>numbers;
  
  
  //input_double(&numbers);
  
  if ( numbers.size() != 0 ){
     sort(numbers.begin(), numbers.end());
  
  }
*/
  
  /*
  cout << "\nmin: \n" << min(numbers) << "\n";

  cout << "\nmax: \n" << max(numbers) << "\n";
  
  cout << "\nmean: \n" << mean(numbers) << "\n";
  
  
  cout << "\nmedian: \n" << median(numbers) << "\n";
  
*/
  
  /*
  int sum_rice = 0;
  int rice_square = 0;
  
  for(int square = 1; square != 65 ; ++square){
    
    sum_rice += grain_rice(square);
    
    
    cout << "\nsquare: " << square << " rice: " << sum_rice << "\n";
    
    
  }
  
*/
  
  /*
  vector<double> doub{0,38282 ,99,0, 3828 , 29282 ,99, 29292929 , 2828,0,99, -28282};
  
  cout << "\n"<<mode(doub)<<"\n";
*/


/*

  double a;
  double b;
  double c;

  double epsilon_ = numeric_limits<double>::epsilon();


  cout << "input constant for ax^2 + bx + c = 0: \n";

  vector<double> roots;

  try{
    
  cin >> a >> b >> c;
    
  roots = quadratic(a , b , c);
  
  
  
  
  }catch (const runtime_error& e){
    
    cerr << "runtime error: " << e.what();
    
  }catch(...){
    
    
    cerr << "invalid, unknown error";
    
  }
  
  
  
  
  
  
  if(roots[0] != roots[1]){
  
      cout << "the roots are " << roots[0] << " and " << roots[1] << "\n";
    
  }else{
    
    cout << "the root is " << roots[0] << "\n";
    
  }




*/


int score;
string name;

vector<int> scores;
vector<string> names;



cout << "input: " <<"\n";


while(cin >> name >> score){
  
  bool isDuplicate = false;
  
  if (name == "noname" && score == 0)
    break;
  
  for(int i ; i < names.size() ; ++i){
    
    if(name == names[i]){
      
      cerr << "cannot be duplicates!";
      
      isDuplicate = true;
      
      
    }
  }
    
  if(!isDuplicate){
    
    
     scores.push_back(score);
  
     names.push_back(name);
  }
  
    
    
    
  
  
}




cout << "\nvalues:\n\n";

for(int i = 0 ; i < names.size() ; ++i){
  
  cout << names[i] << "  " << scores[i] <<"\n";
  
  
}



cout << "search names by score: \n";

while(cin >> score){
  
  
  int i;
  bool is_exist = false;
  
  for( i = 0 ; i < names.size() ; ++i ){
    
    if(score == scores[i]){
      
      is_exist = true;
      cout << "\nname: " << names[i] << " score: " << scores[i] << "\n";
      
      
    }
    
  }
  
  if(!is_exist){
    
      cout << "\nscore not found!\n";
    
  }
  
  
}











  
  
  return 0;
}








void input_double(vector<double>* vect){
  
  
    cout << "input doubles: \n\n";
  
    double doub;
  
    while(cin >> doub){
        vect->push_back(doub);
  }
  
  
}

double sum(vector<double>vect){
  
  double value;
  
  for(double doub : vect){
    
    value += doub;
    
  }
  
  return value;
  
}







double max(vector<double>vect){
  
  
  
  double value;
  value = vect[0];
  
  for (double& doub : vect){
    
     if (doub > value){
       value = doub;
     }
    
    
  }
  
  
  
  return value;
  
}





double min(vector<double>vect){
  
  
  
  double value;
  value = vect[0];
  
  for (double& doub : vect){
    
     if (doub < value){
       value = doub;
     }
    
    
  }
  
  
  
  return value;
  
}




double median(vector<double> vect){
  
  
  
  if( vect.size() == 1 ){
    
    return vect[0];
    
  }
  
  else if(vect.size() % 2 == 0){
    
      
    
    return ( vect[ floor( vect.size() / 2 - 1 ) ] + vect[ floor( vect.size()/ 2 ) ] ) / 2;
    
    
  }else{
    
    
      return vect[vect.size()/2];
    
  }
  
  
  
  
}




double mean(vector<double>vect){
  
  return sum(vect) / vect.size();
  
  
  
}


int guess_number(int num , int low , int high){
  
  
  
  
  
  int guess;
  
  do{
    
       guess = low + (high-low) / 2;
       
       
      if(guess > num){
        
        high = guess - 1;
        
        
      }else if ( guess < num){
        
        low = guess + 1;
        
        
      }else{
        return guess;
      }
    
      
    
  }while(guess != num);
  
  
  return -1;
}





double calculator(double num1, double num2 , char op){
  
  
  double epsilon_ = numeric_limits<double>::epsilon();
  
  
  switch(op){
    
    
    
    case '+':
    
    
             return num1 + num2;
    
             break;
             
    case '-':
    
             return num1 - num2;
    
             break;
             
    case '*':
    case 'x':
    
             return num1 * num2;
    
             break;
    
    case '/':
    case ':':
    
             if(abs(num2) > epsilon_ ){
               
             return num1 / num2;
             }
             
             break;
             
             
    default : return -0.987;
    
  }
  
  return -0.987;
  
}




string digit_to_string(int digit){
  
  vector<string> numbers {"zero" , 
                       "one" ,
                       "two" ,
                       "three" ,
                       "four" , 
                       "five" , 
                       "six" ,
                       "seven" , 
                       "eight" ,
                       "nine"
                      };
                      
                      
  if (digit >= 0 && digit <= 9){
      return numbers[digit];
  
  }
  
  return "invalid";
  
  
}


int string_to_digit(string number){
  
  
  vector<string> numbers {"zero" , 
                       "one" ,
                       "two" ,
                       "three" ,
                       "four" , 
                       "five" , 
                       "six" ,
                       "seven" , 
                       "eight" ,
                       "nine"
                      };
  for( int i; i < numbers.size() ; ++i ){
    
    if(number == numbers[i]){
      
      return i;
      
    }
    
  }
  
  return -1;
  
  
}


long long int grain_rice(int square){
  

    
    
    
  if(square >= 1 && square <= 64){
    
       return pow(2 , (square - 1));
    
    
  
  }
  
  return -1;
  
  
}



double mode (vector<double> doubs){
  
  int mode_index = 0;
  int mode_freq = 0;
  
  for( int i = 0 ; i != doubs.size() ; ++i){
    
    int freq = 0;
    
    for( int j = 0 ; j != doubs.size() ; ++j){
      
      if(doubs[i] == doubs[j])
      { ++freq; }
      
    }
    
    if(freq >= mode_freq){
      
      mode_index = i;
      mode_freq = freq;
      
    }
    
  }
  
  
  return doubs[mode_index];
  
  
}



vector<double> quadratic(double a , double b , double c){
  
  vector<double> roots;
  
  
  double det =pow(b,2)-4*a*c;
  
  if(det >= 0){
  
    double root_1 = ( -b+sqrt(det) ) / (2*a);
    
    double root_2 = ( -b-sqrt(det) ) / (2*a);
  
    roots.assign({root_1 , root_2});
    
    
  }else{
    
    throw runtime_error("invalid, complex range ");
    
    
  
  }
  
  return roots;
  
}


