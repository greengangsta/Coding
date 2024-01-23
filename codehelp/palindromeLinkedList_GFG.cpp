class Solution{
private: 
    bool checkPalindrome(string arr){
        int i=0; 
        int j= arr.length() -1; 
        while(i<=j){
            if(arr[i]!=arr[j]){
                return false;
            }
            i++; 
            j--; 
        }
        return true; 
    }

  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node* temp = head; 
        string nodeArray; 
        while(temp != NULL) {
            nodeArray += temp->data; 
            temp = temp->next; 

        }
        return checkPalindrome(nodeArray); 

       
    }
};
