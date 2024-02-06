#include <bits/stdc++.h>

struct node {
    int data; 
    int i; 
    int j;

}; 

struct comparator {

    bool operator()(node a, node b) {
        return a.data >= b.data;
    }
}; 

int kSorted(vector<vector<int>> &a, int k, int n) {
    // Write your code here.

    priority_queue <node, vector<node>, comparator> pq;
    int maxi = INT_MIN; 
    int mini = INT_MAX; 
    int start; 
    int end; 
    for (int i = 0; i < k; i++) {

        node n1; 
        n1.data = a[i][0]; 
        n1.i = i; 
        n1.j = 0; 
        pq.push(n1); 
        if( a[i][0] > maxi)
            maxi = a[i][0]; 
         if( a[i][0] < mini)
            mini = a[i][0]; 
    }


    start = mini; 
    end = maxi; 


    while (!pq.empty()) {

        node n1 = pq.top(); 
        pq.pop();
        
        mini = n1.data; 
        if (maxi - mini <= end - start) {
                start = mini; 
                end = maxi; 

        }
        if (n1.j < n-1) {

            node n2; 
            n2.data =  a[n1.i][n1.j + 1]; 
            n2.i = n1.i; 
            n2.j = n1.j + 1; 
            pq.push(n2);
            if (n2.data > maxi) {
              maxi = n2.data;
            }
        } else {
            break; 
        }
    }

   
    return end - start + 1; 
}
