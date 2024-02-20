bool cmp(pair <int, int> a, pair <int, int> b)
{
    return a.second < b.second; 
}

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        int n = N;
        vector<pair <int, int>> schedules;
         map<pair<int, int>, int> mp; 
        for(int i=0;i<n;i++){
            schedules.push_back(make_pair(S[i], F[i])); 
            if(mp.find({S[i], F[i]}) == mp.end())
                mp[{S[i], F[i]}] = i+1; 
        }

        vector<int> ans; 
        sort(schedules.begin(), schedules.end(), cmp);
        
        int ansStart = schedules[0].first; 
        int ansEnd = schedules[0].second;
        
        ans.push_back(mp[{ansStart, ansEnd}]);
        for(int i=1;i<n;i++){
            if(schedules[i].first > ansEnd){
                ansEnd = schedules[i].second; 
                ans.push_back(mp[{schedules[i].first,schedules[i].second }]); 
            }
        }
        
        sort(ans.begin(), ans.end()); 
        
        return ans; 
    }
};
