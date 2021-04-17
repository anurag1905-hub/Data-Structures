#include<bits/stdc++.h>
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
        adj[src].push_back(dest);/*Directed Graph*/
    }
    
    bool iscyclicUtil(int v,bool visited[],bool recStack[]){
        if(visited[v]==false){
            visited[v]=true;
            recStack[v]=true;
            list<int>::iterator it;
            for(it=adj[v].begin();it!=adj[v].end();++it){
                if(!visited[*it]&&iscyclicUtil(*it,visited,recStack)){
                    return true;
                }
                else if(recStack[*it]){
                    return true;
                }
            }
        }
        recStack[v]=false;
        return false;
    }
    
    bool isCyclic(){
        bool *visited=new bool[v];
        bool *recStack=new bool[v];
        for(int i=0;i<v;++i){
            visited[i]=false;
            recStack[i]=false;
        }
        for(int i=0;i<v;++i){
            if(iscyclicUtil(i,visited,recStack)){
                return true;
            }
        }
        return false;
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
           if(g.isCyclic()){
               cout<<"Graph contains cycle."<<endl;
           }
           else{
               cout<<"Graph doesn't contain cycle."<<endl;
           }
           return 0;
}
