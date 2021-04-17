#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int src,dest;
};
class Graph{
    public:
    int v,e;
    Edge* edge;
};
Graph* createGraph(int v,int e){
    Graph* graph=new Graph();
    graph->v=v;
    graph->e=e;
    graph->edge=new Edge[graph->e*sizeof(Edge)];
    return graph;
};
int find(int parent[],int i){
    if(parent[i]==-1){
        return i;
    }
    return find(parent,parent[i]);
}
void Union(int parent[],int x,int y){
    parent[x]=y;
}
int isCyclic(Graph* graph){
    int *parent=new int[graph->v*sizeof(int)];
    memset(parent,-1,sizeof(int)*graph->v);
    for(int i=0;i<graph->e;++i){
        int x=find(parent,graph->edge[i].src);
         int y=find(parent,graph->edge[i].dest);
         if(x==y){
             return 1;
         }
         Union(parent,x,y);
    }
    return 0;
    
}
int main(){
    int v=3,e=3;
    Graph* graph=createGraph(v,e);
    graph->edge[0].src=0;
    graph->edge[0].dest=1;
     graph->edge[1].src=1;
    graph->edge[1].dest=2;
         graph->edge[2].src=0;
    graph->edge[2].dest=2;
    if(isCyclic(graph)){
        cout<<"graph contains cycle."<<endl;
    }
    else{
        cout<<"graph doesn't contain cycle."<<endl;
    }
}