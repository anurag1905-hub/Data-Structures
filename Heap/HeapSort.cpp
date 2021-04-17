#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n&&arr[l]>arr[largest]){
        largest=l;
    }
    if(r<n&&arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=i){
        /*Swap function is defined in STL.If you don't want to use <bits/stdc++.h> header then 
         it is better to introduce a temporary variable.
         */
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapsort(int arr[],int n){
    for(int i=(n/2)-1;i>=0;--i){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>0;--i){
        /*Swap function is defined in STL.If you don't want to use <bits/stdc++.h> header then 
         it is better to introduce a temporary variable.
         */
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }
}
/*Utility function to print the sorted array.*/
void printarray(int arr[],int n){
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
          int arr[]={12,11,55,13,5,6,90,55,7,99,0};
          int n=sizeof(arr)/sizeof(arr[0]);
          heapsort(arr,n);
          cout<<"The sorted array is:";
          printarray(arr,n);
}