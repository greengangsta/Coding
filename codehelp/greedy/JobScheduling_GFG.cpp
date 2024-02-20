bool cmp(Job a, Job b){
    return a.profit > b.profit; 
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<Job> jobs; 
        for(int i=0;i<n;i++){
            jobs.push_back(arr[i]);
        }
        
        sort(jobs.begin(), jobs.end(), cmp); 
        
        // for(int i=0;i<n;i++){
        //     cout<<"id-> "<<jobs[i].id<<" "; 
        //     cout<<"profit-> "<<jobs[i].profit<<" "; 
        //     cout<<"dead-> "<<jobs[i].dead; 
        //     cout<<endl;
        // }
        
        vector< int> timeline(n+1, -1); 
        int i=0; 
        int numJobs = 0; 
        int profit = 0; 
        while(i<n){
            int d = jobs[i].dead; 
            if(timeline[d] == -1){
                profit += jobs[i].profit; 
                numJobs++; 
                timeline[d] = 0; 
            }
            else{
                while(d > 0){
                    if(timeline[d] == -1){
                        profit += jobs[i].profit; 
                        numJobs++; 
                        timeline[d] = 0; 
                        break; 
                    }
                    d--; 
                }
            }
            i++; 
        }
        
        vector<int> ans; 
        ans.push_back(numJobs); 
        ans.push_back(profit); 
        
        return ans; 
    } 
};
