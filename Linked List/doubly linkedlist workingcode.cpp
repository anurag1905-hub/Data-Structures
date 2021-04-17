#include <iostream>
using namespace std;
class Node{
           public:
           int data;
           Node* next;
           Node* prev;
           
};
Node* insertathead(Node* head,int value){
    Node* newNode=new Node();
    (*newNode).data=value;
    (*newNode).next=NULL;
    (*newNode).prev=NULL;
    if(head==NULL){
        head=newNode;
    return head;
    }
    (*head).prev=newNode;
    (*newNode).next=head;
    head=newNode;
     return head;
}

Node* insertatanyposition(Node* head,int value,int position){
       Node* newNode=new Node();
       (*newNode).data=value;
       if(head==NULL||position==1){
           return head;
       }
       Node* temp=head;
      for(int i=1;i<position-1;++i){
          temp=temp->next;
      }
      (*newNode).prev=temp;
      (*newNode).next=temp->next;
      temp->next=newNode;
      
     return head; 
       
}

void print(Node* head){
    while(head!=NULL){
        cout<<(*head).data<<endl;
        head=head->next;
    }
}

void insertattail(Node* head,int value){
    Node* newNode=new Node();
    (*newNode).data=value;
    (*newNode).next=NULL;
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void reverseprint(Node* head){
     while(head->next!=NULL){
         head=head->next;
     }
     Node* temp=head;
     while(temp!=NULL){
         cout<<(*temp).data<<endl;
         temp=temp->prev;
     }
}


int main()
{
Node* head=NULL;
head=insertathead(head,2);
print(head);
cout<<endl<<endl;
head=insertathead(head,4);
print(head);
cout<<endl<<endl;
head=insertathead(head,6);
print(head);
cout<<endl<<endl;
reverseprint(head);
head=insertatanyposition(head,99,2);
cout<<endl<<endl;
print(head);
head=insertatanyposition(head,100,5);
cout<<endl<<endl;
print(head);
insertattail(head,156);
cout<<endl<<endl;
print(head);
}