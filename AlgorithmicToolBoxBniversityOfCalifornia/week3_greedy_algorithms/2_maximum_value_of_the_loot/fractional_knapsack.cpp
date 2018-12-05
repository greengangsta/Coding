#include<bits/stdc++.h>
using namespace std;

int maxind( vector<int> weights, vector<int> values)
{
    int id = 0;
    double max = 0;
    int n = weights.size();
    for (int i = 0; i < weights.size(); i++) {
        if (weights[i] != 0 && (double) values[i] / weights[i] > max) {
            max = (double) values[i] / weights[i];
            id = i;
        }
    }
return id;
}
double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
    int n = weights.size(); 
	   for(int i = 0;i<n;i++)
	   {
	     if(capacity == 0)
	       return  value ;
	       int id = maxind(weights,values);
	   int a = min(capacity,weights[id]);
	   value += a*(double)values[id]/weights[id];
	   weights[id] -= a;
	   capacity -= a;
	   }
	   

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
