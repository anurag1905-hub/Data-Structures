#include<iostream>
#define MAX 50
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
                if((rear+1)%5==front){
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
                   rear=(rear+1)%5;
                   arr[rear]=x;
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
                   front=(front+1)%5;
               }
           }
           void getfront(){
               if(!isEmpty()){
               cout<<arr[front]<<" is at the front of the queue."<<endl;
               }
           }
           void printQueue(){
               cout<<"Elements of the Queue are:"<<endl;
               int count=(rear-front+5)%5+1;
               for(int i=0;i<count;++i){
                   int index=(front+i)%5;
                   cout<<arr[index]<<endl;
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
            q.enQueue(150);
           q.getfront();
           q.printQueue();
           cout<<endl<<endl<<"Now checking Dequeue."<<endl<<endl;
           q.Dequeue();
           q.getfront();
           q.printQueue();
           q.Dequeue();
           q.getfront();
           q.printQueue();
           cout<<endl<<endl<<"Again doing enQueue:"<<endl<<endl;
            q.enQueue(999);
           q.getfront();
           q.printQueue();
            q.enQueue(33333);
           q.getfront();
           q.printQueue();
    
}