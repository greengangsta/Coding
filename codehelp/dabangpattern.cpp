#include <iostream>
using namespace std;

int main() {
	int n = 5; 

    int row = 0;
    int i = 0; 
    while (row < n)
    {
        
    // first square 
   
       //print numbers
       
         int col = 0; 
         while(col < n-row){
             cout<<col+1;
             col++;
         }
         
       //print stars 
         while(col < n){
             cout<<'*';
             col++;
         }
         
    
    // second square  
    
    // print stars
    
   int j = 0;
    while(j<i)
    {
        cout<<"*"; 
        j++;
    
    }
    
    //print numbers 
    while(j<n){
        cout<<n-j;
        j++;
        
    }
    
   
    cout<<endl;
    row++;
    i++; 
        
    }
    
  
   
   
	
	return 0;
}
