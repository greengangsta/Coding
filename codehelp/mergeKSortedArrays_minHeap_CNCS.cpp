#include <bits/stdc++.h>

struct node {
    int data; 
    int i; 
    int j; 
};

struct comparator {
    bool operator()(node a, node b) { 
        return a.data > b.data; 
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k) {
    // Write your code here.
    vector<int> ans;
    priority_queue<node, vector<node>, comparator> pq;

    for (int i = 0; i < k; i++) {
        node n1; 
        n1.data = kArrays[i][0]; 
        n1.i = i; 
        n1.j = 0; 
        pq.push(n1); 
    }

    while (pq.size() > 0) {
        struct node minElement = pq.top(); 
        pq.pop();
        ans.push_back(minElement.data); 
        node n1; 
        int n = kArrays[minElement.i].size(); 
        if(minElement.j < n-1 ){
            n1.data = kArrays[minElement.i][minElement.j +1]; 
            n1.i = minElement.i; 
            n1.j = minElement.j + 1; 
            pq.push(n1); 
        }
       
    }

    return ans; 
}
