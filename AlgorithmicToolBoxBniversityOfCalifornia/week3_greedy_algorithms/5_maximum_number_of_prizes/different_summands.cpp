#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int i = 1;
while(n > i)
{
	 n = n - i ;
	 summands.push_back(i);
	 i++;
}
int j = summands.size();
summands[j-1] = summands[j-1] + n;
return summands;
 
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
