#include<bits/stdc++.h>

int signumFunction(int a, int b) {
	return a - b; 

}
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	priority_queue<int, vector<int>, greater<int>> minHeap; 
	priority_queue<int> maxHeap;
	vector<int> ans; 
	int median = arr[0]; 
	maxHeap.push(median);
	ans.push_back(median);
	for (int i = 1; i < n; i++) {
		  int num = arr[i]; 
		  int maxTop; 
		  int minTop;
			switch (signumFunction(maxHeap.size(), minHeap.size())) {
			case 0:
				if (num > median) {
					minHeap.push(num);
					median = minHeap.top();

                } else {
                   maxHeap.push(num);  
				   median = maxHeap.top();
				 }
				ans.push_back(median);
				break;
			case 1:
				if (num > median) {
					minHeap.push(num);
					median = (minHeap.top() + maxHeap.top())/2;

                } else {
				  maxTop = maxHeap.top(); 
				  maxHeap.pop();
                  minHeap.push(maxTop);  
				  maxHeap.push(num);
				  median = (minHeap.top() + maxHeap.top())/2;
				 }
				ans.push_back(median);
				break;
			case -1:
				if (num < median) {
					maxHeap.push(num);
					median = (minHeap.top() + maxHeap.top())/2;

                } else {
				  minTop = minHeap.top(); 
				  minHeap.pop();
                  maxHeap.push(minTop);  
				  minHeap.push(num);
				  median =(minHeap.top() + maxHeap.top())/2;
				 }
				ans.push_back(median);
				break;
			}
        }

        return ans;
}
