#include<bits/stdc++.h>
using namespace std;
class Edge{
           public:
           int src;
           int dest;
           int weight;
};
class Graph{
            public:
            int v,e;
            Edge* edge;
};
class Subset{
             public:
             int parent;
             int rank;
};
Graph* createGraph(int v,int e){
    Graph* graph=new Graph();
    graph->v=v;
    graph->e=e;
    graph->edge=new Edge[e];
};
int find(Subset subsets[],int i){
    if(subsets[i].parent!=i){
        subsets[i].parent=find(subsets,subsets[i].parent);
    }
    return subsets[i].parent;
}
void union1(Subset subsets[],int xroot,int yroot){
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
int myComp(const void* a,const void* b){
     Edge* a1=(Edge*)a;
     Edge* b1=(Edge*)b;
     return a1->weight>b1->weight;
}
void kruskalMst(Graph* graph){
    int v=graph->v;
    Edge result[v];
    int i=0,e=0;
    qsort(graph->edge,graph->e,sizeof(graph->edge[0]),myComp);
    Subset* subsets=new Subset[v*sizeof(Subset)];
    for(int i=0;i<v;++i){
        subsets[i].parent=i;
        subsets[i].rank=0;
    }
    while(e<v-1&&i<graph->e){
        Edge next_edge=graph->edge[i++];
        int x=find(subsets,next_edge.src);
        int y=find(subsets,next_edge.dest);
        if(x!=y){
            result[e++]=next_edge;
            union1(subsets,x,y);
        }
    }
    cout<<"Following are the edges in the Constructed MST\n";
    int minimumCost=0;
    for(i=0;i<e;++i){
        cout<<result[i].src<<"--"<<result[i].dest<<"=="<<result[i].weight<<endl;
        minimumCost+=result[i].weight;
    }
    cout<<"Minimum cost Spanning Tree:"<<minimumCost<<endl;
}
int main(){
      int v=4,e=5;
      Graph* graph=createGraph(v,e);
      graph->edge[0].src=0;
      graph->edge[0].dest=1;
      graph->edge[0].weight=10;
      
      graph->edge[1].src=0;
      graph->edge[1].dest=2;
      graph->edge[1].weight=6;
      
      graph->edge[2].src=0;
      graph->edge[2].dest=3;
      graph->edge[2].weight=5;
      
      graph->edge[3].src=1;
      graph->edge[3].dest=3;
      graph->edge[3].weight=15;
      
      graph->edge[4].src=2;
      graph->edge[4].dest=3;
      graph->edge[4].weight=4;
      
      kruskalMst(graph);
      return 0;
}