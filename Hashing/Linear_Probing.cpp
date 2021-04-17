#include<iostream>
#define size 10
using namespace std;
int arr[size];/*When array is declared as a global variable, the value in all indexes is initialized to zero.*/
int count=0;
int hashFunction(int key){
    return key%size;
}
void insert(int value){
/*This program won't work if we are inserting 0 in this function.
Better initialise all the array elements to -1 where the array has been declared. */

 if(count==size){
     cout<<"Hash Table is FULL."<<endl;
     return;
 }
 else{
     int index=hashFunction(value);
     if(arr[index]==0){
         arr[index]=value;
     }
     else{
          while(arr[index]!=0){
              index=(index+1)%size;
          }
          arr[index]=value;
     }
      ++count;
 }
}
void deleteElement(int value){
    if(count==0){
        cout<<"The Hash table is empty."<<endl;
        return;
    }
    else{
    int index=hashFunction(value);
    if(arr[index]==0){
        cout<<"No data exists at this position."<<endl;   
    }
    else{
        while(arr[index]!=value&&arr[index]!=0){
            index=(index+1)%size;
        }
         arr[index]=0;
         --count;
    }
}
}
void displayHash(){
    cout<<"The elements of the Hash table are:";
    for(int i=0;i<size;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void search(int value){
    if(size==0){
        cout<<value<<" is not found."<<endl;
        return;
    }
    else{
       int index=hashFunction(value);
       if(index>10||index<0){
           cout<<value<<" not found."<<endl;
           return;
       }
       else{
            while(arr[index]!=value&&arr[index]!=0){
                 index=(index+1)%size;
            }
            if(arr[index]==value){
                cout<<value<<" is found."<<endl;
            }
            else{
                cout<<value<<" not found."<<endl;
            }
       }
    }
}

int main(){
          cout<<"You can enter a maximum of 10 elements in this hash table."<<endl;
          cout<<"Though can modify the maximum element by changing the value of size in the macro."<<endl;
          int n;
          cout<<"How many elements you want to enter."<<endl;
          cin>>n;
          cout<<"Enter them.Don't Enter zero it will lead to an error."<<endl;
          int num;
          /*Enter 12,22,76,86,100,67,88,32,99,34*/
          for(int i=0;i<n;++i){
              cin>>num;
              insert(num);
          }
          
          displayHash();
          cout<<"If output has 0 then it signifies that position is empty."<<endl;
          deleteElement(76);
          displayHash();
          search(76);
          search(1000);
          search(22);


}