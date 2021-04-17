#include <iostream>
using namespace std;
class Node{
          private:
          int data;
          Node* link;
          Node* top;
          
          public:
          Node(){
                top=NULL;
          }
          
          void push(int x){
              Node* newNode=new Node();
              (*newNode).data=x;
              if(top==NULL){
              (*newNode).link=NULL;
              top=newNode;
              cout<<(*newNode).data<<"Pushed into the stack."<<endl;
          }
          else{
              (*newNode).link=top;
              top=newNode;
              cout<<(*newNode).data<<" Pushed into the stack."<<endl;
          }
          }
          
          void print(){
              cout<<"The stack is:"<<endl;
              Node* temp=top;
              while(temp!=NULL){
                  cout<<(*temp).data<<endl;
                  temp=temp->link;
              }
          }
          
          void pop(){
              if(top==NULL){
                  cout<<"The stack is empty."<<endl;
                  return;
              }
              Node* temp=top;
              cout<<(*temp).data<<" popped out of stack."<<endl;
              top=top->link;
              delete temp;
              
          }
          
          void seetop(){
              cout<<"The top element of stack is "<<(*top).data<<endl;
          }
          
          void isempty(){
              if(top==NULL){
                  cout<<"The stack is empty."<<endl;
              }
              else{
                  cout<<"The stack is not empty."<<endl;
              }
          }
};
int main()
{
   Node s;
   s.push(2);
   s.print();
   s.push(6);
   s.print();
   s.push(5);
   s.print();
   s.pop();
   s.print();
   s.push(69);
   s.push(77);
   s.print();
   s.pop();
   s.print();
   s.seetop();
   s.push(67);
   s.push(99);
   s.pop();
   s.print();
   s.seetop();
   s.isempty();
   s.pop();
   s.pop();
    s.pop();
   s.pop();
   s.pop();
   s.isempty();
}
