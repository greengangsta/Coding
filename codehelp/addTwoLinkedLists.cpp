class Solution
{
    private :
    
    void insertAtTail(struct Node* &head, struct Node* &tail, int val){
        Node* temp = new Node(val);
        if(head == NULL){
            head = temp; 
            tail = temp; 
        }
        else {
            tail->next = temp; 
            tail = tail->next; 
        }
    }
    
    struct Node* reverseNodes(struct Node* &head){
        Node* curr = head;
        Node* prev = NULL; 
        while(curr != NULL){
            Node* temp = curr->next;
            curr->next = prev; 
            prev = curr; 
            curr = temp;
            
        }
        return prev; 
        
    }
    
    
    public:
    //Function to add two numbers represented by linked list.
   struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        
        first = reverseNodes(first); 
        second = reverseNodes(second);
        
        Node * tail = NULL; 
        Node * newHead = NULL; 

        int carry = 0; 
        while(first!=NULL && second!= NULL){
            int sum = first->data + second->data + carry; 
            carry = sum/10; 
            int digit = sum%10;
            
           insertAtTail(newHead, tail, digit);
             first = first->next; 
            second= second->next;

        }
        
        while(first != NULL){
                int sum = carry + first->data; 
                int digit = sum%10; 
                carry = sum/10;
                insertAtTail(newHead, tail, digit);
                 first = first->next; 
        }
        while(second != NULL){
                int sum = carry + second->data; 
                int digit = sum%10; 
                carry = sum/10;
                insertAtTail(newHead, tail, digit);
                second = second->next; 
        }
        
        while(carry){
            insertAtTail(newHead, tail, carry);
            carry = carry/10;
         }
        
        return reverseNodes(newHead); 
    }
};
