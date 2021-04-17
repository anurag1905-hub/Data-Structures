#include<iostream>
#include<list>
#include<stack>
using namespace std;
class Graph{
           int V;
           list<int>* adj;
           
           public:
           Graph(int V){
               this->V=V;
               adj=new list<int>[V];
           }
           
           void addEdge(int src,int dest){
               adj[src].push_back(dest);
           }
           
           void topologiocalSortUtil(int v,bool visited[],stack<int>&Stack){
               visited[v]=true;
               list<int>::iterator it;
               for(it=adj[v].begin();it!=adj[v].end();++it){
                   if(!visited[*it]){
                       topologiocalSortUtil(*it,visited,Stack);
                   }
               }
               Stack.push(v);
           }
           
           void topologicalSort(){
               stack<int>Stack;
               bool* visited=new bool[V];
               for(int i=0;i<V;++i){
                   visited[i]=false;
               }
               for(int i=0;i<V;++i){
                   if(!visited[i]){
                       topologiocalSortUtil(i,visited,Stack);
                   }
               }
               while(!Stack.empty()){
                   cout<<Stack.top()<<" ";
                   Stack.pop();
               }
           }
};
int main(){
           Graph g(6);
           g.addEdge(5,2);
           g.addEdge(5,0);
           g.addEdge(4,0);
           g.addEdge(4,1);
           g.addEdge(2,3);
           g.addEdge(3,1);
           cout<<"Following is the topological sorting of the given graph:"<<endl;
           g.topologicalSort();
}