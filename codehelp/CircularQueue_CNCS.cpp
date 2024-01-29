#include <bits/stdc++.h> 
class CircularQueue{

    int *q1; 
    int frontIndex; 
    int rearIndex; 
    int size; 
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        q1 = new int[n];
        for(int i=0;i<n;i++){
            q1[i] = -1; 
        }
        size = n;  
        frontIndex = 0; 
        rearIndex = 0; 
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // cout<<"frontIndex--> "<<frontIndex<<endl;
        //  cout<<"rearIndex--> "<<rearIndex<<endl;
        // Write your code here.

        if(frontIndex==rearIndex && q1[frontIndex]==-1){
            q1[rearIndex] = value;
            frontIndex = rearIndex; 
            return true; 

        }
        int newIndex = (rearIndex + 1)%size; 
        if(newIndex == frontIndex)
            return false;
        q1[newIndex] = value;
        rearIndex = newIndex; 
        return true; 
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        // cout<<"frontIndex--> "<<frontIndex<<endl;
        //  cout<<"rearIndex--> "<<rearIndex<<endl;
        if(frontIndex == rearIndex && q1[frontIndex] == -1){
            return -1; 
        }
        int element = q1[frontIndex]; 
        q1[frontIndex] = -1; 
        if(frontIndex != rearIndex)
        frontIndex = (frontIndex + 1)%size; 
        return element; 
    }
};
