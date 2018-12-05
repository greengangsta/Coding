#include <iostream>

int get_change(int m) {
  int a=1,b = 5, c= 10;
  int count = 0;
  while(m>=c){
	 m -= c; 
	 count++;
  }
  while(m>=b)
  {
	  m -= b;
	  count++;
  }
  while(m>=a)
  {
	  m -= a;
	  count++;
  }
  return count;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
