bool cmp(Item a, Item b){
    return ((double)a.value/a.weight) >  ((double)b.value/b.weight) ; 
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        
        vector<Item> items; 
        for(int i=0;i<n;i++){
            items.push_back(arr[i]); 
        }
        
        sort(items.begin(), items.end(), cmp); 
        
        // for(int i=0;i<n;i++){
        //     cout<<"value-> "<<items[i].value<<" "; 
        //     cout<<"weight-> "<<items[i].weight<<" "; 
        //     cout<<"value/weight-> "<<(double)items[i].value/items[i].weight; 
        //     cout<<endl;
        // }
        double value = 0; 
        int i= 0; 
        while(W > 0 && i<n){
            int w  = items[i].weight; 
            if(w <= W){
                value += items[i].value; 
                W -= w; 
            }
            else {
                value += ((double)items[i].value/w)*W; 
                W = 0; 
            }
            i++; 
        }
        
        return value; 
    }
        
};
