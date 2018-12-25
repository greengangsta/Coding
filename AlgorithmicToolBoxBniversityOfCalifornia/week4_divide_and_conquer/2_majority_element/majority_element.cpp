#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;


int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  int m,le,re,lc=0,rc=0;
   m = (left+right-1)/2 +1;
   le = get_majority_element(a,left ,m);
  re = get_majority_element(a,m,right);
   for(int i=left;i<right;i++)
	   if(a[i]==le)
		   lc++;
   for(int i=left;i<right;i++)
      if(a[i]==re)
          rc++;		  
   if(rc > (right-left/2))
	   return re;
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
