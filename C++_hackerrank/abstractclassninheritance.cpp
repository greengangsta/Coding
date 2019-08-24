#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Book{
    protected:
        string title;
        string author;
    public:
        Book(string t,string a){
            title=t;
            author=a;
        }
        virtual void display()=0;

};
class MyBook : public Book
{
    int price;
   public:
    MyBook(string t, string a,int p):Book(t,a)
    { 
        this->price = p;
    }
    virtual void display(void)
    {
        cout<<"Title: "<<this->title<<endl;
        cout<<"Author: "<<this->author<<endl;
        cout<<"Price: "<<this->price<<endl;
    }
   
};

int main() {