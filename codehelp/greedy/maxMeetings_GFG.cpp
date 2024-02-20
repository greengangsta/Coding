bool cmp(pair <int, int> a, pair <int, int> b)
{
    return a.second < b.second; 
}
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair <int, int>> schedules;
        for(int i=0;i<n;i++){
            schedules.push_back(make_pair(start[i], end[i])); 
        }
        
        sort(schedules.begin(), schedules.end(), cmp);
        
        int ansStart = schedules[0].first; 
        int ansEnd = schedules[0].second; 
        int count = 1; 
        for(int i=1;i<n;i++){
            if(schedules[i].first > ansEnd){
                ansEnd = schedules[i].second; 
                count++;
            }
        }
        
        return count; 
    }
};
