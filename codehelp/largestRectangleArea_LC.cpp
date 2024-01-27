class Solution {

void nextSmallest(vector <int> &nextSmallestIndex, vector<int>& heights){
    stack <int> s1; 
    int n = heights.size();
    s1.push(-1);
    for(int i=n-1;i>=0;i--){
        // cout<<"i-> "<<i; 
        int top = s1.top(); 
        // cout<<"top-> "<<top;   

        if(top == -1){
            nextSmallestIndex.push_back(top);
            s1.push(i);
        }
        else if(heights[top] < heights[i]){
            nextSmallestIndex.push_back(top);
            s1.push(i);
        }
        else {
            // cout<<"code reached here"; 
            // cout<<"heights[top] -> "<<heights[top];   
            // cout<<"heights[i] -> "<<heights[i]; 
            // cout<<endl;
            while(top!= -1 && heights[top] >= heights[i] ){
            //    cout<<"top-> "<<top;   
            //    cout<<"heights[top] -> "<<heights[top];   
            //     cout<<"heights[i] -> "<<heights[i]; 
                // cout<<endl;
                //  cout<<"code reached here1"; 
                s1.pop();
                top = s1.top();
            }
            // cout<<"code reached here";
            nextSmallestIndex.push_back(top);
            s1.push(i);
        }

    }

    reverse(nextSmallestIndex.begin(), nextSmallestIndex.end());
}

void previousSmallest(vector <int> &previousSmallestIndex, vector<int>& heights){
    stack <int> s1; 
    int n = heights.size();
    s1.push(-1);
    for(int i=0;i<n;i++){
        // cout<<"i-> "<<i; 
        int top = s1.top(); 
        // cout<<"top-> "<<top;   

        if(top == -1){
            previousSmallestIndex.push_back(top);
            s1.push(i);
        }
        else if(heights[top] < heights[i]){
            previousSmallestIndex.push_back(top);
            s1.push(i);
        }
        else {
            // cout<<"code reached here"; 
            // cout<<"heights[top] -> "<<heights[top];   
            // cout<<"heights[i] -> "<<heights[i]; 
            // cout<<endl;
            while(top!= -1 && heights[top] >= heights[i] ){
            //    cout<<"top-> "<<top;   
            //    cout<<"heights[top] -> "<<heights[top];   
            //     cout<<"heights[i] -> "<<heights[i]; 
                // cout<<endl;
                //  cout<<"code reached here1"; 
                s1.pop();
                top = s1.top();
            }
            // cout<<"code reached here";
            previousSmallestIndex.push_back(top);
            s1.push(i);
        }

    }

}

public:
    int largestRectangleArea(vector<int>& heights) {

        vector <int> nextSmallestIndex; 
        vector <int> previousSmallestIndex; 
        nextSmallest(nextSmallestIndex, heights);
        // for(int i=0;i<nextSmallestIndex.size();i++){
        //     cout<<nextSmallestIndex[i]<<" "; 
        // }cout<<endl;

        previousSmallest(previousSmallestIndex, heights);

        // for(int i=0;i<previousSmallestIndex.size();i++){
        //     cout<<previousSmallestIndex[i]<<" "; 
        // }cout<<endl;

        vector <int> areas; 
        int n = heights.size();

        int max = -1; 


        for(int i=0;i<heights.size();i++){
            int area = heights[i];
            if(nextSmallestIndex[i] == -1){
                area += (n-i-1)* heights[i];;
            }
            else{
                 area += (nextSmallestIndex[i] -i-1)* heights[i];
            }

            if(previousSmallestIndex[i] == -1){
                area += i* heights[i];
            }
            else{
                 area += (i- previousSmallestIndex[i]-1)* heights[i];
            }
            if(area > max)
            max = area; 
            areas.push_back(area);
        }

        // for(int i=0;i<areas.size();i++){
        //     cout<<areas[i]<<" "; 
        // }cout<<endl;
    return max ; 
        
    }
};
