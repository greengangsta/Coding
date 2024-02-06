#include<bits/stdc++.h>
int maximumFrequency(vector<int> &arr, int n)
{
    //Write your code here
    unordered_map <int, int > mp; 
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        if (mp.find(num) == mp.end()) {
            mp[num] = 1; 
        }else{
            mp[num] =  mp[num] + 1; 
        }
    }
    int maxFrequencey= INT_MIN; 
    for (auto i:mp) {
        if (i.second > maxFrequencey) {
            maxFrequencey = i.second; 
        }
    }

    for (int i = 0; i < n; i++) {
        if(mp[arr[i]]== maxFrequencey)
        return arr[i];
    }

    return maxFrequencey;
}
