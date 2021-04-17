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
    else if(data<root->data){
        root->left=insertData(root->left,data);
    }
    else{
        root->right=insertData(root->right,data);
    }
    return root;
}
BstNode* FindMin(BstNode* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

BstNode* Delete(BstNode* root,int data){
    if(root==NULL){
        return root;
    }
    /* Don't use data<=root->data otherwise the node won't be deleted.
    */
    else if(data<root->data){
        root->left=Delete(root->left,data); 
        
    }
    else if(data>root->data){
        root->right=Delete(root->right,data);
    }
    else{
         if(root->left==NULL&&root->right==NULL){
             delete root;
             root=NULL;
             
         }
         else if(root->left==NULL){
             BstNode* temp=root;
             root=root->right;
             delete temp;
             
         }
         else if(root->right==NULL){
             BstNode* temp=root;
             root=root->left;
             delete temp;
            

         }
         else{
              BstNode* temp=FindMin(root->right);
              root->data=temp->data;
              root->right=Delete(root->right,temp->data);
              
         }
    }
     return root;
    
}
void Inorder(BstNode* root){
 if(root==NULL){
     return;
 }
 Inorder(root->left);
 cout<<root->data<<" ";
 Inorder(root->right);
}
int main(){
           BstNode* root=NULL;
           root=insertData(root,12);
           root=insertData(root,5);
           root=insertData(root,19);
           root=insertData(root,3);
           root=insertData(root,7);
           root=insertData(root,13);
           root=insertData(root,15);
           root=insertData(root,1);
           root=insertData(root,17);
           root=insertData(root,9);
           cout<<"The binary search tree is :"<<endl;
           Inorder(root);
           cout<<endl;
           root=Delete(root,9);
           cout<<"The binary search tree is :"<<endl;
            Inorder(root);
            cout<<endl;
            root=Delete(root,1);
            cout<<"The binary search tree is :"<<endl;
            Inorder(root);

}