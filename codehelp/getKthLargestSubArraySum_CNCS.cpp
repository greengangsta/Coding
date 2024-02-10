#include <bits/stdc++.h> 
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	priority_queue <int, vector<int>, greater<int> > pq;
		int n = arr.size(); 
        for (int i = 0; i <n ; i++) {
		  int sum = 0; 
          for (int j = i; j < n; j++) {
			  sum += arr[j];
				if (pq.size() < k) {
					pq.push(sum);
                } 
				else {
					int element = pq.top();
					if (sum > element) {
							pq.pop(); 
							pq.push(sum); 
					}
                }
            }
        }
	return pq.top();
}