#include <bits/stdc++.h> 
class NStack
{

private : 
    int *top; 
    int *next; 
    int freespot;
    int *arr;  

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        freespot = 0; 
        top = new int[N]; 
        next = new int[S];
        arr = new int[S];
        for(int i=0;i<N;i++)
            top[i] = -1;
        for(int i=0;i<S-1;i++)
            next[i] = i+1;
        next[S-1] = -1; 

        // Write your code here.
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        if(freespot != -1){

        int index = freespot; 
        freespot = next[index];

        arr[index] = x; 
        next[index] = top[m-1];
        top[m-1] = index; 
        return true; 
        }

        return false; 

    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        if(top[m-1] == -1){
            return -1;
        }

        int index = top[m-1]; 
        int element = arr[index]; 
        top[m-1] =  next[index];
        next[index] = freespot;
        freespot = index; 

        return element; 
        
    }
};
