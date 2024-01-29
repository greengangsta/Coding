class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        // add code here.
        stack <int> s1; 
        while(!q.empty()){
            int element = q.front();
            q.pop();
            s1.push(element); 
        }
        while(!s1.empty()){
            int element = s1.top();
            s1.pop();
            q.push(element); 
        }
        return  q; 
    }
};
