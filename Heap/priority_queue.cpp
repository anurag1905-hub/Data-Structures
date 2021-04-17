/*Considering largest element has the highest priority.Basically a Max-Heap is
  Implemented here.*/
#include<bits/stdc++.h>
using namespace std;
int H[50];
int size=-1;
int parent(int i){
    return (i-1)/2;
}
int leftChild(int i){
    return ((2*i)+1);

}
int rightChild(int i){
    return ((2*i)+2);
}
void shiftUp(int i){
    while(i>0&&H[i]>H[parent(i)]){
        swap(H[i],H[parent(i)]);
        i=parent(i);
    }
}
void shiftDown(int i){
    int maxIndex=i;
    int l=leftChild(i);
    int r=rightChild(i);
    if(l<=size&&H[l]>H[maxIndex]){
        maxIndex=l;
    }
    if(r<=size&&H[r]>H[maxIndex]){
        maxIndex=r;
    }
    if(maxIndex!=i){
        swap(H[maxIndex],H[i]);
        shiftDown(maxIndex);
    }
}

void insert(int p){
    size=size+1;
    H[size]=p;
    shiftUp(size);
}
int extractMax(){
    int result=H[0];
    H[0]=H[size];
    size--;
    shiftDown(0);
    return result;
}
void changePriority(int i,int p){
    int oldp=H[i];
    H[i]=p;
    if(oldp>p){
        shiftDown(i);
    }
    else{
        shiftUp(i);
    }
}
int getMax(){
    return H[0];
}
void remove(int i){
    H[i]=getMax()+1;
    shiftUp(i);
    extractMax();  /*We are not collecting any returned value because it is not of any use.*/
}

int main(){
           insert(45);
           insert(20);
           insert(14);
           insert(12);
           insert(31);
           insert(7);
           insert(11);
           insert(13);
           insert(7);
           int i=0;
           cout<<"Priority Queue:"<<endl;
           for(i=0;i<=size;++i){
               cout<<H[i]<<" ";
           }
           cout<<endl;
           cout<<"Node with maximum priority is "<<endl;
           int max=extractMax();
           cout<<max<<endl;
           cout<<"Priority Queue after extracting maximum:"<<endl;
           int j=0;
           for(int j=0;j<=size;++j){
               cout<<H[j]<<" ";
           }
           cout<<endl;
           changePriority(2,49);
           cout<<"Priority Queue after priority change is:"<<endl;
           int k=0;
           for(k=0;k<=size;++k){
               cout<<H[k]<<" ";
           }
           cout<<endl;
           remove(3);
           cout<<"Priority Queue after removing the element:"<<endl;
           int l=0;
           for(l=0;l<=size;++l){
               cout<<H[l]<<" ";
           }
           cout<<endl;
           return 0;

}