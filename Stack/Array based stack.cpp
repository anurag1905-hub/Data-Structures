#include<iostream>
using namespace std;
#define MAX_SIZE 100
class Stack{
            private:
            int A[MAX_SIZE];
            int top;
            
            public:
            
            Stack(){
                top=-1;
            }
            
            void push(int x){
                if(top==MAX_SIZE-1){
                    cout<<"Error ! overflow Condition."<<endl;
                }
                else{
                    A[++top]=x;
                    cout<<x<<" has been pushed into the stack."<<endl;
                }
            }
            
            void print(){
                cout<<"The stack is:"<<endl;
                for(int i=0;i<=top;++i){
                    cout<<A[i]<<endl;
                }
            }
            
            void pop(){
                if(top==-1){
                    cout<<"Error! Underflow condition."<<endl;
                }
                else{
                    --top;
                    cout<<"Popped element="<<A[top+1]<<endl;
                }
            }
            
            void gettop(){
                cout<<"The element at the top of stack is"<<A[top]<<endl;
            }
            
            void isEmpty(){
                if(top==-1){
                  cout<<"Yes"<<endl;
                }
                else{
                    cout<<"No"<<endl;
                }
            }
            
            
};
int main(){
           Stack s;
           s.push(2);
           s.push(5);
           s.push(100);
           s.print();
           s.isEmpty();
           s.gettop();
           s.pop();
           s.print();
           s.isEmpty();
           s.gettop();
           
           
}