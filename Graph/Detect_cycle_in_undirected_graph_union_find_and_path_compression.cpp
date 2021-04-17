#include<iostream>
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
class subset{
           public:
           int parent;
           int rank;
};
Graph* createGraph(int v,int e){
    Graph* graph=new Graph();
    graph->v=v;
    graph->e=e;
    graph->edge=new Edge[(graph->e)*(sizeof(Edge))];
    return graph;
}
int find(subset subsets[],int i){
    if(subsets[i].parent!=i){
        subsets[i].parent=find(subsets,subsets[i].parent);
    }
    return subsets[i].parent;
}
void Union(subset subsets[],int xroot,int yroot){
    if(subsets[xroot].rank<subsets[yroot].rank){
        subsets[xroot].parent=yroot;
    }
    else if(subsets[xroot].rank>subsets[yroot].rank){
        subsets[yroot].parent=xroot;
    }
    else{
        subsets[yroot].parent=xroot;
        subsets[xroot].rank++;
    }
}
int isCycle(Graph* graph){
    int x=graph->v;
    int y=graph->e;
    subset *subsets=new subset[x*sizeof(subset)];
    for(int i=0;i<x;++i){
        subsets[i].parent=i;
        subsets[i].rank=0;
    }
    for(int j=0;j<y;++j){
        int x=find(subsets,graph->edge[j].src);
        int y=find(subsets,graph->edge[j].dest);
        if(x==y){
            return 1;
        }
        Union(subsets,x,y);
    }
    return 0;
}
int main(){
           int v=3,e=3;
           Graph *graph=createGraph(v,e);
           //add edge 0-1
           graph->edge[0].src=0;
           graph->edge[0].src=1;
           //add edge 1-2
           graph->edge[1].src=1;
           graph->edge[1].dest=2;
           //add edge 0-2
           graph->edge[2].src=0;
           graph->edge[2].dest=2;
           
           if(isCycle(graph)){
               cout<<"Graph contains cycle."<<endl;
           }
           else{
               cout<<"Graph doesn't contain cycle."<<endl;
           }
           
}