#include<iostream>
#define MAX 100
using namespace std;
class Queue{
            private:
            int arr[MAX],front,rear;
            public:
            Queue(){
                front=-1;
                rear=-1;
            }

           int isEmpty(){
               if(rear==-1&&front==-1){
                   return true;
               }
               else{
                   return false;
               }

           }

           int isFull(){
                if(rear==MAX-1){
                    return true;
                }
                else{
                    return false;
                }
           }

           void enQueue(int x){
               if(isEmpty()){
                   rear=front=0;
                   arr[rear]=x;
                   cout<<x<<" pushed into the queue."<<endl;
               }
               else if(isFull()){
                    cout<<"Error! the queue is full."<<endl;
                    return;
               }
               else{
                   arr[++rear]=x;
                   cout<<x<<" pushed into the queue."<<endl;
               }
           }

           void Dequeue(){
               if(isEmpty()){
                   cout<<"The queue is already empty!."<<endl;
                   return;
               }
               else if(front==rear){
                   cout<<arr[front]<<" is dequeued."<<endl;
                   front=rear=-1;
               }
               else{
                   cout<<arr[front]<<" is dequeued."<<endl;
                   ++front;
               }
           }
           void getfront(){
               if(!isEmpty()){
               cout<<arr[front]<<" is at the front of the queue."<<endl;
               }
           }
           void printQueue(){
               cout<<"Elements of the Queue are:"<<endl;
               for(int i=front;i<=rear;++i){
                   cout<<arr[i]<<endl;
               }
           }
};
int main(){
           Queue q;
           q.enQueue(5);
           q.getfront();
           q.printQueue();
            q.enQueue(65);
           q.getfront();
           q.printQueue();
            q.enQueue(99);
           q.getfront();
           q.printQueue();
            q.enQueue(100);
           q.getfront();
           q.printQueue();
           cout<<endl<<endl<<"Now checking Dequeue."<<endl<<endl;
           q.Dequeue();
           q.getfront();
           q.printQueue();
           q.Dequeue();
           q.getfront();
           q.printQueue();
           


}