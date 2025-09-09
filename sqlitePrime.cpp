#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <string>
#include <thread>
#include <chrono>
#include <sqlite3.h>
#include <vector>




bool isPrimeSingleNumber ( long long int num , sqlite3_stmt* stmt_select, sqlite3_stmt* stmt_insert , bool* state );

bool isPrimeSieve ( long long int upper , sqlite3_stmt* stmt_insert , bool* state);
void isPrimeInterval (long long lower , long long upper , sqlite3_stmt* stmt_insert , bool* state);
void primeCount (long long int lower , long long upper , sqlite3_stmt* stmt_count , bool* state);



//##############################################################################################



int main(){

  
  
  sqlite3* DB;
  
  int rc = sqlite3_open("Prime.db" , &DB);
  if(rc != SQLITE_OK){
    sqlite3_close(DB);
    return 1;
  }


  


  sqlite3_stmt* stmt_select;
  sqlite3_stmt* stmt_insert;
  sqlite3_stmt* stmt_count;
  
  
  
  std::string create_table = "CREATE TABLE IF NOT EXISTS Prime_Table("
                             "Number BIGINT PRIMARY KEY NOT NULL);";
                    
  std::string syncOff = "PRAGMA synchronous=OFF;";
  
  std::string begin = "BEGIN TRANSACTION;";
  
  std::string commit = "COMMIT;";
  
  
  
  

  char* ErrMsg = 0;
  
  
  
  rc = sqlite3_exec(DB, create_table.c_str(), NULL, 0, &ErrMsg);
  
  
  
  if(rc != SQLITE_OK){
    std::cerr << "Error creating table: " << ErrMsg;
    sqlite3_free(ErrMsg);
    sqlite3_close(DB);
    return 1;
  }
  
  rc = sqlite3_exec(DB, syncOff.c_str(), NULL, 0, &ErrMsg);
  
  
  
  
  
  
  
  sqlite3_prepare_v2( DB 
  ,  "SELECT COUNT(*) FROM Prime_Table WHERE Number = ?;" , -1 
  , &stmt_select , NULL );
  
  
  sqlite3_prepare_v2( DB
  , "INSERT OR IGNORE INTO Prime_Table (Number) VALUES (?);" , -1
  , &stmt_insert , NULL );
  
  
  sqlite3_prepare_v2( DB 
  , "SELECT COUNT(*) FROM Prime_Table WHERE Number >=? AND Number <= ?;" , -1
  , &stmt_count , NULL );
  
  
  

  char choice;
  
  bool running = true;
  
  while(running){
    
      
      
      std::cout << "\nNumber or Interval?: ";
      std::cin >> choice;
      std::cout << '\n';
      
      
      switch(choice){
      
         case 'n':
         
            long long int num;
            std::cout << "Number: ";
            std::cin >> num;
            std::cout << '\n';
            
            rc = sqlite3_exec(DB, begin.c_str(), NULL, 0, &ErrMsg);
            
            isPrimeSingleNumber(num , stmt_select , stmt_insert , &running);
            
            rc = sqlite3_exec(DB, commit.c_str(), NULL, 0, &ErrMsg);
            
            break;
         
            
         case 'i':
            
            
            long long int lower;
            long long int upper;
            
            
            std::cout << "lower Bound: ";
            std::cin >> lower;
            
            std::cout << "\nUpper Bound: ";
            std::cin >> upper;
            std::cout << '\n';
            
            rc = sqlite3_exec(DB, begin.c_str(), NULL, 0, &ErrMsg);
            
            isPrimeInterval( lower , upper , stmt_insert , &running);
            
            
            
            std::cout << "\x1b[H\x1b[2J"; 
            primeCount( lower , upper , stmt_count , &running);
            std::cout << '\n';
            rc = sqlite3_exec(DB, commit.c_str(), NULL, 0, &ErrMsg);
            
            break;
            
            
            
         case 'x':
         
            running = false;
            
            break;
         
         
         default: std::cout << "invalid\n";
            
      }
      
      
      
      
  }
  
  
  
  
  
  
  sqlite3_finalize(stmt_select);
  sqlite3_finalize(stmt_insert);
  sqlite3_finalize(stmt_count);
  
  sqlite3_close(DB);
  
  return 0;
  
}



//###############################################



bool isPrimeSingleNumber ( long long int num , sqlite3_stmt* stmt_select , sqlite3_stmt* stmt_insert , bool* state ){
  

     if (num < 2LL){
       std::cout << "\r\x1b[2K" << num << " is not a prime";
       return false;
     }
  
     
     int rc;
     
     sqlite3_bind_int64(stmt_select , 1 , num);
     
     rc = sqlite3_step(stmt_select);
     
     if ( rc != SQLITE_ROW){
       
       *state = false;
       return false;
     }
     
     
     
     if( sqlite3_column_int(stmt_select , 0) == 1 ){
     
    
        std::cout << "\r\x1b[2K" << num << " is a prime" << std::flush;
        sqlite3_reset(stmt_select);
        return true;
        
     }
     
     sqlite3_reset(stmt_select);
    
  
     bool isPrime = isPrimeSieve(num , stmt_insert , state);
       
       
     std::cout << "\r\x1b[2K" << num << (isPrime ?  " is a prime" : " is not a prime");
     
     return true;
  

}



//###############################################



bool isPrimeSieve( long long int upper , sqlite3_stmt* stmt_insert , bool* state ){

   int rc;


   
  
  std::vector<bool> boolPrime(upper + 1LL , true);
  boolPrime[0] = false;
  boolPrime[1] = false;
  
  
  
  
  
  for ( long long int num = 1 ; num <= upper ; ++num){
    
    
      

    
    
    if(boolPrime[num] == true){
        
        std::cout << "\r\x1b[2K" << num << " is a Prime" << std::flush;
        
        sqlite3_bind_int64(stmt_insert , 1 , num);
        rc = sqlite3_step(stmt_insert);
        if (rc != SQLITE_DONE){     
               *state = false;
               return false;
        }
        sqlite3_reset(stmt_insert);
        
        
        for (long long int multiple = num * num ; (num * num <= upper) && (multiple <= upper) ; multiple += num){
          
          boolPrime[multiple] = false;
          //std::cout << "\r\x1b[2K" << multiple << " is not a Prime" << std::flush;
          
        }  
       
    }
    
    
  }
  
  
  return boolPrime[upper];
  
}



//###############################################



void isPrimeInterval( long long lower , long long upper , sqlite3_stmt* stmt_insert , bool* state ){
  
  switch( static_cast<int>(lower < upper) ){
    
    case 1:
    
        if (lower < 0){
          
          for (long long int num = lower ; num <= 0 ; ++num){
              std::cout << "\r\x1b[2K" << num << " is not a Prime";
          }
          
          
        }
        
        
        break;
     
    default:
        std::cerr << "\nInvalid!";
        return;
        
  
  }
  
  isPrimeSieve(upper , stmt_insert , state);

  
}



//###############################################



void primeCount ( long long lower , long long upper , sqlite3_stmt* stmt_count , bool* state ){
  
  
  
  sqlite3_bind_int64(stmt_count , 1 , lower);
  sqlite3_bind_int64(stmt_count , 2 , upper);
  
  int rc = sqlite3_step(stmt_count);
  
  if ( rc != SQLITE_ROW){
    *state = false;
    return;
  }
  
  std::cout << "\nthere are " << sqlite3_column_int64(stmt_count , 0) << " Primes Between " << lower << " and " << upper; 
  
  sqlite3_reset(stmt_count);
  return;
}














