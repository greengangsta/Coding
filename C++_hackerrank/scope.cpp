#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
  	public:
  	int maximumDifference;

	Difference(vector <int> a)
    {
      int l = a.size();
      for(int i=0;i<l;i++)
      {
          this->elements.push_back(a[i]);
      }
    }

    void computeDifference(void)
    {
        sort(elements.begin(),elements.end());
        int l = elements.size();
        maximumDifference = abs(elements[0]- elements[l-1]);
    }

}; // End of Difference class

int main() {
    int N;
    cin >> N;
    
    vector<int> a;
    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        
        a.push_back(e);
    }
    
    Difference d(a);
    
    d.computeDifference();
    
    cout << d.maximumDifference;
    
    return 0;
}