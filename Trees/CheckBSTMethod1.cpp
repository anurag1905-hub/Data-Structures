#include<iostream>
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

bool IsSubtreelesser(BstNode* root,int value){
    if(root==NULL){
        return true;
    }
    if((root->data<=value)&&IsSubtreelesser(root->left,value)&&IsSubtreelesser(root->right,value)){
        return true;
    }
    else{
        return false;
    }
}

bool IsSubtreeGreater(BstNode* root,int value){
    if(root==NULL){
        return true;
    }
    if((root->data>value)&&IsSubtreeGreater(root->left,value)&&IsSubtreeGreater(root->right,value)){
        return true;
    }
    else{
        return false;
    }
}

bool IsBinaryTree(BstNode* root){
    if(root==NULL){
        return true;
    }
    if(IsSubtreelesser(root->left,root->data)&&IsSubtreeGreater(root->right,root->data)&&IsBinaryTree(root->left)&&IsBinaryTree(root->right)){
        return true;
    }
    else{
        return false;
    }
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
           int flag=IsBinaryTree(root);
           if(flag){
               cout<<"This binary tree is a binary search tree. "<<endl;
           }
           else{
               cout<<"This binary tree is not a binary search tree. "<<endl;
           }
           return 0;
           

}