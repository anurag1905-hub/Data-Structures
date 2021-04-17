#include<iostream>
#include<limits.h>
using namespace std;
class BstNode{
              public:
              int data;
              BstNode* left;
              BstNode* right;
};
BstNode* createnewNode(int data){
    BstNode* new_Node=new BstNode();
    new_Node->data=data;
    new_Node->left=NULL;
    new_Node->right=NULL;
    return new_Node;
}

BstNode* insertData(BstNode* root,int data){
    if(root==NULL){
        root=createnewNode(data);
    }
    else if(data<=root->data){
        root->left=insertData(root->left,data);
    }
    else{
        root->right=insertData(root->right,data);
    }
    return root;
}

bool IsBSTUtil(BstNode* root,int min_value,int max_value){
    if(root==NULL){
        return true;
    }
    if(root->data>min_value&&root->data<max_value&&IsBSTUtil(root->left,min_value,root->data)&&IsBSTUtil(root->right,root->data,max_value)){
        return true;
    }
    else{
        return false;
    }
}

bool checkIsBst(BstNode* root){
    return IsBSTUtil(root,INT_MIN,INT_MAX);
}
int main(){
           BstNode* root=NULL;
           root=insertData(root,5);
           root=insertData(root,4);
           root=insertData(root,11);
           root=insertData(root,3);
           root=insertData(root,2);
           root=insertData(root,17);
           root=insertData(root,77);
           int flag=checkIsBst(root);
           if(flag){
               cout<<"This binary tree is a binary search tree. "<<endl;
           }
           else{
               cout<<"This binary tree is not a binary search tree. "<<endl;
           }
           return 0;
}