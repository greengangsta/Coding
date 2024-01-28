#include <bits/stdc++.h> 
class Queue {

    int *q1; 
    int frontIndex; 
    int rearIndex; 
public:
    Queue() {
        // Implement the Constructor
        int n = 100000;
        q1 = new int[n]; 
        frontIndex = 0; 
        rearIndex = 0; 

    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(frontIndex==rearIndex)
            return true; 
        return false; 
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        q1[rearIndex] = data; 
            rearIndex++;

    }

    int dequeue() {
        // Implement the dequeue() function
        if(frontIndex == rearIndex)
            return -1; 
        int element = q1[frontIndex]; 
        frontIndex++; 
        return element; 
    }

    int front() {
        // Implement the front() function
        if(frontIndex ==rearIndex)
            return -1; 
        int element = q1[frontIndex]; 
        return element; 
    }
};
