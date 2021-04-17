#include<iostream>
#include<list>
#include<iterator>
using namespace std;
class Graph{
            int v;
            list<int>* adj;
            
            public:
            Graph(int v){
                this->v=v;
                adj=new list<int>[v];
            }
            
            void addEdge(int src,int dest){
                adj[src].push_back(dest);   /*Directed Graph*/
            }
            
            void DFSUtil(int s,bool visited[]){
                visited[s]=true;
                cout<<s<<" ";
                list<int>::iterator it;
                for(it=adj[s].begin();it!=adj[s].end();++it){
                    if(!visited[*it]){
                        DFSUtil(*it,visited);
                    }
                }
            }
            
            void DFS(){
                bool *visited=new bool[v];
                for(int i=0;i<v;++i){
                    visited[i]=false;
                }
                for(int i=0;i<v;++i){
                    if(visited[i]==false){
                        DFSUtil(i,visited);
                    }
                }
            }
};
int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);
    cout<<"The DFS traversal is:"<<endl;
    g.DFS();
}