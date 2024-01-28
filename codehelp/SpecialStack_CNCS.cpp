class SpecialStack {
    private : 
    
    int mini = 999999999; 
    stack <int> s1; 
    public:
        
    void push(int data) {
        // Implement the push() function.
        // cout<<"mini before push --> "<<mini<<endl;
        // cout<<"data being push --> "<<data<<endl;

        if(s1.empty()){
            mini = data; 
            s1.push(data); 
        }
        else if(data > mini ){
             s1.push(data); 
        }
        else {
            int val = 2*data - mini; 
            mini = data; 
            s1.push(val); 
        }
        // cout<<"mini after push --> "<<mini<<endl;

    }

    void pop() {
        // Implement the pop() function.
        if(s1.top() > mini){
            s1.pop(); 
            return; 
        }
        else {
            int val = 2*mini - s1.top(); 
            mini = val; 
            s1.pop(); 
        }
    }

    int top() {
        // Implement the top() function.
        if(s1.top() > mini || s1.size()==1){
            return s1.top(); 
        }
        else {
            // int val = 2*mini - s1.top(); 
            // mini = val; 
            return mini; 
        }

    }

    int getMin() {
        // Implement the getMin() function.
        return mini; 
    }  
};
