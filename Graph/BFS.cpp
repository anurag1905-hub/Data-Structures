#include<iostream>
#include<bits/stdc++.h>
#include<list>
#include<queue>
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
    
    void BFS(int s){
        bool *visited=new bool[5];
        for(int i=0;i<v;++i){
            visited[i]=false;
        }
        queue<int>q;
        visited[s]=true;
        q.push(s);
        while(!q.empty()){
            s=q.front();
            cout<<s<<" ";
            q.pop();
            for(auto it=adj[s].begin();it!=adj[s].end();++it){
                if(!visited[*it]){
                    visited[*it]=true;
                    q.push(*it);
                }
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
           int source;
           cout<<"Enter the vertex from which you wish to do BFS:"<<endl;
           cin>>source;
           cout<<"The Breadth First Traversal from vertex "<<source<<" is:"<<endl;
           g.BFS(source);
}