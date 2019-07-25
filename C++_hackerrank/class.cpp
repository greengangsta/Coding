#include<bits/stdc++.h>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student{
  
  private :
  string first_name,last_name;
  int age,standard;

  public :
   int get_age(){
      return age;
  }
  void set_age(int age)
  {
      this->age = age;
  }
  string get_first_name(void){
      return first_name;
  }
   void set_first_name(string first_name)
  {
      this->first_name = first_name;
  }
  string get_last_name(void){
      return last_name;
  }
  void set_last_name(string last_name)
  {
      this->last_name = last_name;
  }
  int get_standard(){
      return standard;
  }
   void set_standard(int standard)
  {
      this->standard = standard;
  }
  string to_string()
  {
     return std::to_string(this->age) + "," + first_name + "," + last_name + "," 
     + std::to_string(standard);
  }

};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}

