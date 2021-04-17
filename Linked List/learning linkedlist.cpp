#include<iostream>
using namespace std;
class Node{
           public:
           int data;
           Node* link;
};

/*Don't run this code here, run it inside an online compiler*/


Node* reverse(Node* head){
    if(head==NULL||head->link==NULL){
        return head;
    }
    else{
       Node* rest=reverse(head->link);
       head->link->link=head;
       head->link=NULL;
       return rest;

 
    }
}
    
void print(Node* n){
    while(n!=NULL){
        cout<<(*n).data<<endl;
        n=(*n).link;
    }
}
void append(Node** head_ref,int new_data){
    Node* new_node=new Node();
    Node* last=*head_ref;
    new_node->data=new_data;
    if(*head_ref==NULL){
        *head_ref=new_node;
    }
    else{
         while(last->link!=NULL){
             last=last->link;
         }
         last->link=new_node;
    }
}
void Delete(Node** head,int n){
         Node* temp1=*head;
         if(n==1){
             *head=(*temp1).link;
             delete temp1;
         }
         else{
             for(int i=1;i<n-1;++i){
                 temp1=(*temp1).link;
             }
             Node* temp2=(*temp1).link;
             temp1=(*temp2).link;
             delete temp2;
         }
         
}
int main(){
           int n;
           Node* head=NULL;
          append(&head,2);
          append(&head,4);
          append(&head,6);
          append(&head,8);
           print(head);
          cout<<"Enter the position"<<endl;
          cin>>n;
          Delete(&head,n);
          cout<<endl<<"The list is"<<endl;
          print(head);
          cout<<endl<<endl<<endl;
          cout<<"Reversing using recursion"<<endl<<endl;
          head=reverse(head);
          cout<<"Printing after reversing"<<endl<<endl<<endl;
          print(head);
          return 0;
}
