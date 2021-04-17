#include<iostream>
#define N 5  /*Read an article from GFG on how to pass a two dimensional array to a function.*/
using namespace std;
int M;
void createAdjMatrix(int b,int Adj[][N+1],int arr[][2]){
    for(int i=0;i<N+1;++i){
        for(int j=0;j<N+1;++j){
            Adj[i][j]=0;
    }
   }
   for(int i=0;i<b;++i){
       int x=arr[i][0];
       int y=arr[i][1];
       Adj[x][y]=1;
       Adj[y][x]=1;
   }
}
void printAdjMatrix(int Adj[][N+1]){
   for(int i=1;i<N+1;++i){
       for(int j=1;j<N+1;++j){
           cout<<Adj[i][j]<<" ";
       }
       cout<<endl;
   }
}
int main(){
         int arr[][2]={
                      {1,2},{2,3},{4,5},{1,5}
                      };
         int M=sizeof(arr)/sizeof(arr[0]);
         int Adj[N+1][N+1];
         createAdjMatrix(M,Adj,arr);
         printAdjMatrix(Adj);
}