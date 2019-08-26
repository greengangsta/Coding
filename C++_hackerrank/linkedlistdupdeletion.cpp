#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;	
class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};
class Solution{
    public:

          Node* removeDuplicates(Node *head)
          {
             Node* temp = head;
             Node* nnext = temp->next;
             Node * prev = temp;
             while(nnext != NULL)
             {
                 int d = nnext->data;
                 Node* temp2 = head;
                 int flag = 0;
                 while(temp2->next!= nnext->next)
                 {
                    if (temp2->data == d)
                    {
                      flag = 1;
                      break;
                    }
                    else 
                    {
                        temp2 = temp2->next;
                    }
                 }
                 if(flag==1)
                 {
                     prev->next = nnext->next;
                     Node *temp3 = nnext;
                     nnext = nnext->next;
                     delete(temp3);        

                 }
                 else 
                 {
                    prev = prev->next;
                    nnext = nnext->next;
                 }
             }
             return head;
          }

          Node* insert(Node *head,int data)
          {
               Node* p=new Node(data);
               if(head==NULL){
                   head=p;  

               }
               else if(head->next==NULL){
                   head->next=p;

               }
               else{
                   Node *start=head;
                   while(start->next!=NULL){
                       start=start->next;
                   }
                   start->next=p;   

               }
                    return head;
                
            
          }
          void display(Node *head)
          {
                  Node *start=head;
                    while(start)
                    {
                        cout<<start->data<<" ";
                        start=start->next;
                    }
           }
};
			
int main()
{
	Node* head=NULL;
  	Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    }	
    head=mylist.removeDuplicates(head);

	mylist.display(head);
		
}