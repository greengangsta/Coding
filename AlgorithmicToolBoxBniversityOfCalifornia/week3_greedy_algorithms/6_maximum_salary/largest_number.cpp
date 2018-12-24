#include <bits/stdc++.h>

using namespace std;

bool cmp(string a,string b)
{    
    string p = a+b;
    string q = b+a;
    stringstream s1(p);
    stringstream s2(q);
   	 int n1 , n2 =0;
   	 s1>>n1;
   	 s2>>n2;
   	 return n1>n2;
}
string largest_number(vector<string> a) {
  //write your code here
  sort(a.begin(),a.end(),cmp);
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
