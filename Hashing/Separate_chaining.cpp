#include<bits/stdc++.h>
using namespace std;
class Hash{
           int bucket;
           list<int>* table;

           public:
         void sizeofbucket(int v){
             bucket=v;
             table=new list<int>[bucket];
         }
          int hashFunction(int x){
               return x%10;    
           }

           void insertItem(int key){
               int index=hashFunction(key);
               table[index].push_back(key);
           }

           void deleteItem(int key){
               int index=hashFunction(key);
               list<int>::iterator it;
               for(it=table[index].begin();it!=table[index].end();++it){
                   if(*it==key){
                       break;
                   }
               }
               if(it!=table[index].end()){
                   table[index].erase(it);
               }
           }
           void displayHash(){
               for(int i=0;i<bucket;++i){
                   cout<<i;
                   for(auto x:table[i]){
                       cout<<"-->"<<x;
                   }
                   cout<<endl;
               }

           }
};
int main(){
          int a[]={15,11,27,8,12};
          int n=sizeof(a)/sizeof(a[0]);
          Hash h;
          h.sizeofbucket(10);
          /*Be very careful while passing the bucket size.It gives 
          the possible indexes available.Example-index of 27 will be 7.If I pass 5 as 
          size of bucket,it will lead to segmentation fault because index 7 for 27 is
          not available.*/
          for(int i=0;i<n;++i){
              h.insertItem(a[i]);
          }
          h.deleteItem(12);
          h.displayHash();
          /* 12 doesn't appear because we have deleted it.*/

}