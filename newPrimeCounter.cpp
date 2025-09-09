#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <string>
#include <thread>
#include <chrono>


bool isPrimeNumber(long long int num , std::vector<long long int>* ptrVector );
void iterate_isPrimeNumber(long long int lower_number , long long int upper_number , std::vector<long long int>* ptrVector);
void isPrimeSingleNumber( long long int num , std::vector<long long int>* ptrToVector );
long long int primeCount(long long int lower , long long int upper , std::vector<long long int>* ptrVector);






int main(){
        
     std::vector<long long int> primeVector ;
     std::vector<long long int>* ptrPrimeVector = &primeVector ;
            
     
     while(true){
       
        std::cout << "\x1b[H\x1b[2J \n\n-------------Prime Number Counter--------------\n\n";
       
       
        
        
        std::cout << "Do you want to check a Number or over an Interval?: ";
        std::string choice = "";
        std::string buffer;
        std::cin >> choice;
    
                
        std::getline(std::cin , buffer);     
              
        if( choice == "interval" ){
                    
                     std::cout << "\x1b[H\x1b[2J \n\n-------------Prime Number Counter--------------\n\n";
                     
                       
                       
                       
                    long long int lower_number = 0LL;
                    long long int upper_number = 0LL;
                    
                   
                    
                    
                    std::cout << "Input the Lower Number: ";
                    
                    std::cin >> lower_number;
                    std::getline(std::cin , buffer);
                    
                    
                    std::cout << "\nInput the Upper Number: ";   
                    
                    std::cin >> upper_number;
                    std::getline(std::cin , buffer);
                    
                    
                    std::cout << "\x1b[H\x1b[2J  \n\n-------------Prime Number Counter--------------  \n\nLoading...\n\n";
                    
                    auto start = std::chrono::steady_clock::now();
                    iterate_isPrimeNumber(lower_number , upper_number , ptrPrimeVector);
                    auto end = std::chrono::steady_clock::now();
                    
                    auto elapsed = end - start;
                    auto elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double>>(elapsed).count();
                    
                     
                    std::cout << "\x1b[H\x1b[2J \n\n-------------Prime Number Counter--------------" 
                    << "  \n\nThe operations took " << elapsed_seconds << " Seconds" << "\nPress Enter to continue\n";
                    std::getline(std::cin , buffer);                
                   
                   
                    
                    
                    std::cout << "\x1b[H\x1b[2J  \n\n-------------Prime Number Counter--------------\n\n";
                    
                    std::cout << "There are " << primeCount(lower_number , upper_number , ptrPrimeVector)
                    << " prime numbers on interval [" <<lower_number<< "," << upper_number << "]";
                    
                    std::cout << "\n-----------\n  \nPress Enter to continue\n";
                    std::getline(std::cin , buffer);
        }
        
        
        
        else if (choice == "number"){
                   
                   std::cout << "\x1b[H\x1b[2J  \n\n-------------Prime Number Counter--------------\n\n";       
        
        
        
        	         long long int number = 0LL;
        	       
                   std::cout << "Input the Number: ";
                   
                   std::cin >> number;
                   std::getline(std::cin , buffer);
                   
                   
                   
                   std::cout << "\x1b[H\x1b[2J  \n\n-------------Prime Number Counter--------------\n\n";
                   
                   auto start = std::chrono::steady_clock::now();
                   isPrimeSingleNumber(number , ptrPrimeVector);
                   auto end = std::chrono::steady_clock::now();
                   
                   
                   auto elapsed = end - start;
                   double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double>>(elapsed).count();
                   
                   
                   std::cout << "\n-----------  \n\nThe operations took " << elapsed_seconds << " Seconds" << "\nPress Enter to continue\n";
                   std::getline(std::cin , buffer);
        }
        
        
        
        else if (choice == "x"){
                	break;        	        	
        }
        
        
        
        else{    	        
                	std::cout << "\nInvalid choice! please input a valid choice.  \nOr if you want to exit, type x.\n";
                  std::this_thread::sleep_for(std::chrono::seconds(2) );
        }
        primeVector.clear();
        
     }
     
     
     
     return 0;
}










bool isPrimeNumber(long long int num , std::vector<long long int>* ptrVector){
	  
	           
	            	            
	
            	if(num > 1LL){
            	  
            	  
            	      if(num == 2LL){
	            	
	                    	std::cout << "2 is a prime ";	 
	                    	ptrVector->emplace_back(num);
	                    	return true;	            	
	                  }
            	
		
		
		                
		                
		                 //we are searching prime factor of num all the way to square root of num.
		                 for( long long int i = 0LL ; ( (*ptrVector)[i] <= std::floor(std::sqrt(num)) ) && ( i < ptrVector->size() ) ; i++ ){
		                 
		                      	    if(num % (*ptrVector)[i] == 0LL){
		                      	          std::cout << num << " is not a prime "; 
		                      	          return false;	             		                      	    
		                      	    }
		                  }
		                  std::cout << num << " is a prime";
		                  ptrVector->emplace_back(num);
		                  return true;
		                  
            	}
            	
             	
		          else{
		                    std::cout << num << " is not a prime";                    
		                    return false;   
		          }
	return false;
	         
}



void iterate_isPrimeNumber(long long int lower_number , long long int upper_number , std::vector<long long int>* ptrVector){
  
  if (lower_number >= 1){
  
	  for(long long int num = 1 ; num <= upper_number ; num++){
		
		    std::cout << "\r\x1b[2K";
	  	  isPrimeNumber(num , ptrVector);    
	  }
	  return;
  }
  
  for(long long int num = lower_number ; num <= upper_number ; num++){
		    std::cout << "\r\x1b[2K";
	  	  isPrimeNumber(num , ptrVector);
    
  }
  
}	



void isPrimeSingleNumber( long long int num , std::vector<long long int>* ptrToVector ){
  
   std::vector<long long int> primeFirst25 = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43 , 47 , 53 , 59 , 61 , 67 , 71 , 73 , 79 , 83 , 89 , 97};
   std::vector<long long int>* ptrPrime = &primeFirst25;
   
   
   if(!isPrimeNumber( num , ptrPrime )) return ;
   
   std::cout << "\r\x1b[2KLoading...\n\n";
   iterate_isPrimeNumber(2LL , std::floor(std::sqrt(num)) + 1LL, ptrToVector);
        
        
   std::cout << "\x1b[H\x1b[2J  \n\n-------------Prime Number Counter--------------\n\n" ;   
   isPrimeNumber(num , ptrToVector );
}






long long int primeCount(long long int lower , long long int upper , std::vector<long long int>* ptrVector){
  long long int count = 0LL ;
  for(long long int prime : *ptrVector){
      if(prime >=lower){
          
          ++count;
                
      }
  }
  
  return count;
}


