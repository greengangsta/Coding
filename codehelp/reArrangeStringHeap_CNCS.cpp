#include <bits/stdc++.h>

struct node {

	char ch; 
	int count; 
};

struct comparator {
	bool operator()(node a, node b){
		return a.count < b.count; 
	}
};

string reArrangeString(string &s) {
        // Write your code here.

		int n = s.length();
        int arr[26] = {0};
        for (int i = 0; i < n; i++) {
            arr[s[i] - 'a']++;
        }

	priority_queue <node, vector<node>, comparator> pq;

		char ch2 = 'a';

        for (int i = 0; i < 26; i++) {
          if (arr[i] > 0) {
			node n1; 
			n1.ch = ch2; 
			n1.count = arr[i]; 
			pq.push(n1); 
			
          }
          ch2++;            
        }

	// check if already valid string
	bool flag = false;
    for (int i = 1; i < n; i++) {
		if(s[i]== s[i-1]){
			flag = true; 
		}
    }

    if (!flag) {
		return s;
    }

	string finalString = "";
        while (pq.size() > 1) {
			node n1 = pq.top(); 
			pq.pop(); 
			node n2 = pq.top(); 
			pq.pop(); 
			finalString += n1.ch; 
			finalString += n2.ch; 
			n1.count = n1.count - 1; 
			n2.count = n2.count - 1; 
			if(n1.count > 0){
				pq.push(n1); 
			}
			if(n2.count > 0){
				pq.push(n2); 
			}
			
        }

		if(pq.size() == 0)
			return finalString; 
		node topNode = pq.top();
		if(topNode.count == 1 ){
           finalString += topNode.ch ; 
		   return finalString; 
		}

		return "not possible";

	return finalString; 
}
