#include<bits/stdc++.h>
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
void print(Node* head){
    while(head!=NULL){
        cout<<(*head).data<<endl;
        head=head->link;
    }
}

void reverseprintusingstack(Node* head){
     if(head==NULL){
       cout<<"The linked  list is empty:"<<endl;
       return;
    }
    stack<Node*>s;
    Node* temp=head;
    while(temp!=NULL){
        s.push(temp);
        temp=temp->link;
    }
    temp=s.top();
    head=temp;
   cout<<(*temp).data<<endl;
    s.pop();
    while(!s.empty()){
        temp->link=s.top();
        s.pop();
        temp=temp->link;
        cout<<(*temp).data<<endl;
    }
    temp->link=NULL;
    
}
    
int main(){
   Node* head=NULL;
   head=insertatbegining(head,1);
   insertatgivenposition(head,5,2);
   insertatgivenposition(head,10,3);
   insertatgivenposition(head,15,4);
   insertatgivenposition(head,0,2);
   print(head);
   cout<<"The linked list in reversed order is:"<<endl;
   reverseprintusingstack(head);
}
   
           