#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<double> weights, vector<double> values) {
  double value = 0.0,smw = 0;
  int n  = weights.size();
  for(int i = 0;i< n;i++)
    smw += weights[i];
    
  while(capacity>0 && smw > 0)
  { 
       double max = 0;
       int id = -1;
	  for(int i = 0;i<n;i++)
	   {
		 if( values[i]/weights[i]>max)
		 {
			 max = values[i]/weights[i];
		      id = i;
		 } 
	   }
	   if(capacity >= weights[id])
	   {
		   capacity -= weights[id];
		   smw -= weights[id];
		   value += values[id];
		   values[id] = 0;
	   }
      else if (capacity > 0){
		  double m = 0.0;
		  m =(values[id]/weights[id])*capacity;
		  value +=m;
		  capacity = 0;
		  smw = 0;
	  }
  }
  

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
