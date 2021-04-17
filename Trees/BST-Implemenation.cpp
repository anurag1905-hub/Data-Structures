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
bool searchData(BstNode* root,int data){
    if(root==NULL){
        return false;
    }
    else if(root->data==data){
        return true;
    }
    else if(data<=root->data){
        return searchData(root->left,data);
    }
    else{
        return searchData(root->right,data);
    }
}

void findmin_iterative(BstNode* root){
    if(root==NULL){
        cout<<"ERROR! The Tree is empty."<<endl;
        return;
    }
    while(root->left!=NULL){
        root=root->left;
    }
    cout<<"Minimum element of the binary tree is "<<root->data<<endl;
}

void findmax_iterative(BstNode* root){
    if(root==NULL){
        cout<<"Error! The tree is empty."<<endl;
        return;
    }
    while(root->right!=NULL){
        root=root->right;
    }
    cout<<"The maximum element of the binary tree  is "<<root->data<<endl;
}

int findmin_recursive(BstNode* root){
    if(root==NULL){
        cout<<"The tree is empty."<<endl;
        return -1;
    }
    else if(root->left==NULL){
        return root->data;
    }
    return findmin_recursive(root->left);
}

int findmax_recursive(BstNode* root){
    if(root==NULL){
        cout<<"The tree is empty."<<endl;
        return -1;
    }
    else if(root->right==NULL){
        return root->data;
    }
    return findmax_recursive(root->right);
}

int findHeight(BstNode* root){
    int leftheight,rightheight;
    if(root==NULL){
        return -1;
    }
    leftheight=findHeight(root->left);
    rightheight=findHeight(root->right);
    return max(leftheight,rightheight)+1;
}

int main(){
           int min,max,height;
           BstNode* root=NULL;
           findmax_iterative(root);
           findmin_iterative(root);
           root=insertData(root,11);
           root=insertData(root,17);
           root=insertData(root,19);
           root=insertData(root,23);
           if(searchData(root,17)){
               cout<<" 17 is present "<<endl;
           }
           else{
               cout<<"17 is absent "<<endl;
           }
            if(searchData(root,99)){
               cout<<" 99 is present "<<endl;
           }
           else{
               cout<<"99 is absent "<<endl;
           }
           root=insertData(root,90);
           root=insertData(root,-45);
            findmax_iterative(root);
           findmin_iterative(root);
          min=findmin_recursive(root);
          max=findmax_recursive(root);
          cout<<"Min element of tree "<<min<<endl;
          cout<<"Max element of tree "<<max<<endl;   
          root=insertData(root,15);
          root=insertData(root,16);
          root=insertData(root,21);
          height=findHeight(root);
          cout<<"The height of the tree is "<<height<<endl;
    return 0;
}
