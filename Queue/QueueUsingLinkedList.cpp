#include<iostream>
using namespace std;
class Node{
           private:
           int data;
           Node *next,*front,*rear;

           public:
           Node(){
           front=NULL;
           rear=NULL;
           }

           void dequeueathead(){
           if(front==NULL){
               cout<<"The queue is empty."<<endl;
               return;
           }
           if(front==rear){
               cout<<(*front).data<<" is deleted from the beginning."<<endl;
               front=NULL;
               rear=NULL;
           }
           else{
                Node* temp=front;
                cout<<(*temp).data<<" is deleted from the beginning of queue."<<endl;
                front=front->next;
                delete temp;
           }
           }

           void enqueueattail(int x){
             Node* new_node=new Node();
             new_node->data=x;
             new_node->next=NULL;
             if(front==NULL){
                 front=new_node;
                 rear=new_node;
                 cout<<(*rear).data<<" is added at rear end of queue."<<endl;
             }
             else{
                 rear->next=new_node;
                 rear=new_node;
                 cout<<(*rear).data<<" is added at rear end of queue."<<endl; 
             }
           }

           void print(){
               Node* temp=front;
               cout<<"The elements of the queue are:"<<endl;
               while(temp!=NULL){
                   cout<<temp->data<<endl;
                   temp=temp->next;
               }
           }

           void viewfront(){
                 if(front!=NULL){
                     cout<<(*front).data<<" is at the front of the queue."<<endl;
                 }
           }
};
int main(){
          Node n;
          n.enqueueattail(12);
          n.print();
          n.enqueueattail(15);
          n.print();
          n.enqueueattail(18);
          n.print();
          n.dequeueathead();
          n.print();
          n.dequeueathead();
          n.print();
          n.dequeueathead();
          n.print();
          n.dequeueathead();
}