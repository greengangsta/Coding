class Solution {
public:
int num=0;
    int count = 0; 
    int reverse(int x) {
        while(x){
        int temp=x%10;
        if(num <= INT_MAX/10  && num >= INT_MIN/10){
            num=num*10; 
        }
        else {
            return 0; 
        }

        if(temp > 0){

        if(num <= INT_MAX - temp  ){
            num=num + temp;
        }
        else {
            return 0; 
        }

        }
        else if(temp < 0){

        if(num <= INT_MAX + temp  ){
            num=num + temp;
        }
        else {
            return 0; 
        }

        }
        
        x=x/10;
    }
    return num;
    }
};
