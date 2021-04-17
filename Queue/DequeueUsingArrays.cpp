#include<iostream>
#define size 101
using namespace std;
class Dequeue{
              private:
              int arr[size],front,rear;
              public:
              Dequeue(){
                  front=-1;
                  rear=-1;
              }

              bool isEmpty(){
                  if(front==-1&&rear==-1){
                      return true;
                  }
                  else{
                      return false;
                  }
              }

              bool isFull(){
                  if((rear+1)%size==front){
                      return true;
                  }
                  else{
                      return false;
                  }
              }

              void insertFront(int x){
                  if(isFull()){
                      cout<<"The dequeue is Full."<<endl;
                      return;
                  }
                  else if(front==-1&&rear==-1){
                      front=0;
                      rear=0;   
                  }
                  else {
                      front=(front-1+size)%size;
                  }
                  arr[front]=x;
                  cout<<x<<" is enqueued at the front."<<endl;
              }

              void insertBack(int x){
                  if(isFull()){
                      return;
                  }
                  else if(front==-1&&rear==-1){
                      front=0;
                      rear=0;
                  }
                  else{
                      rear=(rear+1)%size;
                  }
                  arr[rear]=x;
                  cout<<x<<" is enqueued at the back."<<endl;
              }

              void deletefront(){
                     if(isEmpty()){
                         cout<<"The Dequeue is already empty."<<endl;
                         return;
                     }
                     else if(front==rear){
                         cout<<arr[front]<<" has been removed from the front."<<endl;
                         front=-1;
                         rear=-1;
                     }
                     else{
                          cout<<arr[front]<<" has been removed from the beginning."<<endl;
                          front=(front+1)%size;
                          
                     }
              }

              void deleteback(){
                  if(isEmpty()){
                      cout<<"The Dequeue is already empty."<<endl;
                      return;
                  }
                else if(front==rear){
                         cout<<arr[front]<<" has been removed from the back."<<endl;
                         front=-1;
                         rear=-1;
                     }
                else{
                    cout<<arr[rear]<<" has been removed from the back."<<endl;
                    rear=(rear-1+size)%size;
                }

              }

              void viewfront(){
                  if(!isEmpty()){
                  cout<<arr[front]<<" is at the front of the Dequeue."<<endl;
                  }
              }

              void viewback(){
                  if(!isEmpty()){
                      cout<<arr[rear]<<" is at the rear end of the Dequeue."<<endl;
                  }
              }

              void print(){
                  cout<<"The elements of Dequeue are:"<<endl;
                  int count=(rear-front+size)%size+1;
                  for(int i=0;i<count;++i){
                      int index=(front+i)%size;
                      cout<<arr[index]<<endl;
                  }
              }
};
int main(){
           Dequeue dq;
           dq.insertBack(23);
           dq.insertFront(11);
           dq.insertFront(7);
           dq.insertFront(5);
           dq.deletefront();
           dq.insertFront(99);
           dq.print();
           dq.viewback();
           dq.viewfront();
           
           
           
}