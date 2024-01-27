#include<bits/stdc++.h>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack <int> s1; 
    vector <int> ans; 
    s1.push(-1);
    for(int i=n-1;i>=0;i--){
        int top = s1.top();   
        if(top == -1){
            ans.push_back(top);
            s1.push(arr[i]);
        }
        else if(top < arr[i]){
            ans.push_back(top);
            s1.push(arr[i]);
        }
        else {
            while(top >= arr[i] && top!=-1){
                s1.pop();
                top = s1.top();
            }
            ans.push_back(top);
            s1.push(arr[i]);
        }

    }

    reverse(ans.begin(), ans.end());

    return ans;
}
