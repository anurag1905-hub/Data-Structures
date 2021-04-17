#include<iostream>
#include<cstdlib>
using namespace std;
struct AdjListNode{
    /*Each node contains two data fields,One two store data and one to store the address of  the next node;
    */
    int data;
    struct AdjListNode* next;
};
struct AdjList{
    /* Our list structure contains a pointer variable which stores the address of the head node.
    */
   struct AdjListNode* head;
};
class Graph{
           private:
            /*Our graph contains the number of vertices and
    a pointer to linked list.*/
          int V;
          AdjList* array;

          public:
          Graph(int V){
              this->V=V;
              array=new AdjList[V];
              /*Linking head of all vertices(array) to NULL,it doesn't store any number only stores HEAD.*/
              for(int i=0;i<V;++i){
                  array[i].head=NULL;
              }
          }
          /*Adding Edge to Graph*/
          void addEdge(int src,int dest){
              /*Add an edge from src to dest.A new Node is added to the adjacency list of src.The node is added at the beginning.*/
              AdjListNode* newNode =new AdjListNode;
              newNode->data=dest;
              newNode->next=NULL;
              newNode->next=array[src].head;
              array[src].head=newNode;

              /*Since graph is undirected add an edge from dest to src also*/
              newNode=new AdjListNode;
              newNode->data=src;
              newNode->next=NULL;
              newNode->next=array[dest].head;
              array[dest].head=newNode;

          }
          /*Print the graph*/
          void printGraph(){
              int v;
              for(v=0;v<V;++v){
                  AdjListNode* temp=array[v].head;
                  /*temp has the address of (0,1,2,..)vertex head.*/
                  cout<<"\n Adjacency list of vertex"<<v<<" is "<<endl;
                  while(temp){
                      cout<<"->"<<temp->data;
                      temp=temp->next;
                  } 
                  cout<<endl;
              }
          }
};
int main(){
    Graph gh(5);
    gh.addEdge(0,1);
    gh.addEdge(0,4);
    gh.addEdge(1,2);
    gh.addEdge(1,3);
    gh.addEdge(2,3);
    gh.addEdge(3,4);
    gh.printGraph();
}

