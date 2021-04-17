#include<bits/stdc++.h>
#define v 5
using namespace std;
int minKey(int key[],bool mstSet[]){
    int min=INT_MAX;
    int min_index;
    for(int i=0;i<v;++i){
        if(mstSet[i]==false&&key[i]<min){
            min=key[i];
            min_index=i;
        }
    }
    return min_index;
}
void printMST(int parent[],int graph[v][v]){
    cout<<"Edge \t Weight\n";
    for(int i=1;i<v;++i){
        cout<<parent[i]<<"-"<<i<<"\t"<<graph[i][parent[i]]<<"\n";
    }
}
void primMST(int graph[][v]){
    int parent[v];
    int key[v];
    bool mstSet[v];
    for(int i=0;i<v;++i){
        key[i]=INT_MAX;
        mstSet[i]=false;
    }
    key[0]=0;
    parent[0]=-1;
    for(int count=0;count<v-1;++count){
        int u=minKey(key,mstSet);
        mstSet[u]=true;
        for(int j=0;j<v;++j){
            if(graph[u][j]&&mstSet[j]==false&&graph[u][j]<key[j]){
                parent[j]=u;
                key[j]=graph[u][j];
            }
        }
    }
    printMST(parent,graph);
}
int main(){
    int graph[v][v]={
                     {0,2,0,6,0},
                     {2,0,3,8,5},
                     {0,3,0,0,7},
                     {6,8,0,0,9},
                     {0,5,7,9,0}
                    };
    primMST(graph);
    return 0;
    }
