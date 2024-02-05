class comparator {

    public:

    bool operator()(Node* a, Node* b) { 
        return a->data > b->data; 
    }
};

Node* mergeKLists(vector<Node*> &listArray){
    // Write your code here.

    priority_queue<Node*, vector<Node*>, comparator> pq;

    Node* head = NULL; 
    Node* tail = NULL;

    for (int i = 0; i < listArray.size(); i++) {
        pq.push(listArray[i]); 
    }

    while (pq.size() > 0) {
       Node* topNode = pq.top();
       if (head == NULL) {
           head = topNode; 
           tail = topNode;
       } else {
           tail->next = topNode; 
           tail = topNode; 
       }
        pq.pop();
        if(topNode->next!=NULL ){
            pq.push(topNode->next); 
        }
       
    }

    return head; 

}
