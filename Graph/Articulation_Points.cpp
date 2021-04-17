#include<iostream>
#include<list>
#define NIL -1
using namespace std;
class Graph{
            int V;
            list<int>* adj;
            
            public:
            Graph(int v){
                this->V=v;
                adj=new list<int>[V];
            }  
            
            void addEdge(int src,int dest){
                adj[src].push_back(dest);
                adj[dest].push_back(src);   //Undirected Edge     
                
            }
            
            void APUtil(int u,bool visited[],int disc[],int low[],int parent[],bool ap[]){
                static int time=0;
                int children=0;
                visited[u]=true;
                disc[u]=low[u]=++time;
                list<int>::iterator i;
                for(i=adj[u].begin();i!=adj[u].end();++i){
                    int v=*i;
                    if(!visited[v]){
                        children++;
                        parent[v]=u;
                        APUtil(v,visited,disc,low,parent,ap);
                        low[u]=min(low[u],low[v]);
                        if(parent[u]==NIL&&children>1){
                            ap[u]=true;
                        }
                        if(parent[u]!=NIL&&low[v]>=disc[u]){
                            ap[u]=true;
                        }
                        
                    }
                    else if(v!=parent[u]){
                        low[u]=min(low[u],disc[v]);
                    }
                }
                
            }
            
            void AP(){
                bool *visited=new bool[V];
                int *disc=new int[V];
                int *low=new int[V];
                bool *ap=new bool[V];
                int *parent=new int[V];
                for(int i=0;i<V;++i){
                    parent[i]=NIL;
                    visited[i]=false;
                    ap[i]=false;
                }
                for(int i=0;i<V;++i){
                    if(visited[i]==false){
                        APUtil(i,visited,disc,low,parent,ap);
                    }
                }
                for(int i=0;i<V;++i){
                    if(ap[i]==true){
                        cout<<i<<" ";
                    }
                }
            }
};
int main(){
           cout<<endl<<"Articulation points in first graph:"<<endl;
           Graph g1(5);
           g1.addEdge(1,0);
           g1.addEdge(0,2);
           g1.addEdge(2,1);
           g1.addEdge(0,3);
           g1.addEdge(3,4);
           g1.AP();
           cout<<endl<<"Articulation points in second graph:"<<endl;
           Graph g2(4);
           g2.addEdge(0,1);
           g2.addEdge(1,2);
           g2.addEdge(2,3);
           g2.AP();
           cout<<endl<<"Articulation points in third graph:"<<endl;
           Graph g3(7);
           g3.addEdge(0,1);
           g3.addEdge(1,2);
           g3.addEdge(2,0);
           g3.addEdge(1,3);
           g3.addEdge(1,4);
           g3.addEdge(1,6);
           g3.addEdge(3,5);
           g3.addEdge(4,5);
           g3.AP();
           
}