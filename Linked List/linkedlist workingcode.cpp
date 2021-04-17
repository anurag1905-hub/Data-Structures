#include<iostream>
using namespace std;
class Node{
           public:
           int data;
           Node* link;
};

Node* insertatbegining(Node* p,int value){
    Node* temp=new Node();
    (*temp).data=value;
    (*temp).link=p;
    p=temp;
    return p;
}

void insertatgivenposition(Node* p,int value,int position){
    if(p==NULL||position==1){
        return ;
    }
    else{
        Node* temp=new Node();
        (*temp).data=value;
        (*temp).link=NULL;
        Node* temp1=p;
        for(int i=1;i<position-1;++i){
            temp1=temp1->link;
        }
        (*temp).link=temp1->link;
        (*temp1).link=temp;
    }
}

void insertatend(Node* head,int value){
    Node* temp=new Node();
    (*temp).data=value;
    (*temp).link=NULL;
    Node* temp1=head;
    while(temp1->link!=NULL){
        temp1=temp1->link;
    }
    temp1->link=temp;
    
}

Node* deletenode(Node* head,int position){
    if(position==1){
        head=head->link;
    }
    else{
        Node* temp=head;
        for(int i=1;i<position-1;++i){
            temp=temp->link;
        }
        Node* temp1=temp->link;
        temp->link=temp1->link;
        delete temp1;
    }
    return head;
}
void printusingrecursion(Node* head){
    if(head==NULL){
        return ;
    }
    cout<<(*head).data<<endl;
    printusingrecursion(head->link);
}

void reverseprintusingrecursion(Node* head){
    if(head==NULL){
        return ;
    }
    reverseprintusingrecursion(head->link);
     cout<<(*head).data<<endl;
}

Node* reverselinkedlist(Node* head){
    Node* current=head;
    Node* previous=NULL;
    Node* next;
    while(current!=NULL){
        next=current->link;
        current->link=previous;
        previous=current;
        current=next;
    }
    head=previous;
    return head;
}

Node* reverselinkedlistusingrecursion(Node* head){
       if(head->link==NULL){
         return head;
    }
    else{
         Node* rest=reverselinkedlistusingrecursion(head->link);
         head->link->link=head;
         head->link=NULL;
         return rest;
}
}
void print(Node* head){
    while(head!=NULL){
        cout<<(*head).data<<endl;
        head=head->link;
    }
}
int main(){
   Node* head=NULL;
   head=insertatbegining(head,1);
   print(head);
   insertatgivenposition(head,5,2);
   cout<<endl<<endl;
   print(head);
   insertatgivenposition(head,10,3);
   cout<<endl<<endl;
   print(head);
   insertatgivenposition(head,15,4);
   cout<<endl<<endl;
   print(head);
   insertatgivenposition(head,0,2);
   cout<<endl<<endl;
   print(head);
   insertatend(head,100);
   cout<<endl<<endl;
   print(head);
   head=insertatbegining(head,11);
   cout<<endl<<endl;
   print(head);
   insertatgivenposition(head,165,3);
   cout<<endl<<endl;
   print(head);
   head=deletenode(head,2);
   cout<<endl<<endl;
   print(head);
   head=deletenode(head,1);
   cout<<endl<<endl;
   print(head);
   head=deletenode(head,6);
   cout<<endl<<endl;
   print(head);
   cout<<endl<<endl;
   printusingrecursion(head);
   cout<<endl<<endl;
   reverseprintusingrecursion(head);
   cout<<endl<<endl;
   cout<<"Reversing a linked list using iterative approach"<<endl<<endl;
   cout<<endl<<endl;
   head=reverselinkedlist(head);
   print(head);
   cout<<endl<<endl;
   cout<<"Reversing a linked list using recursion"<<endl;
   cout<<endl<<endl;
   head=reverselinkedlistusingrecursion(head);
   print(head);
}