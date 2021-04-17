#include<iostream>
using namespace std;
class BstNode{
              public:
              char data;
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

void Postorder(BstNode* root){
    if(root==NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
        BstNode* root=NULL;
        root=insertData(root,'F');
        root=insertData(root,'D');
        root=insertData(root,'J');
        root=insertData(root,'B');
        root=insertData(root,'E');
        root=insertData(root,'G');
        root=insertData(root,'K');
        root=insertData(root,'A');
        root=insertData(root,'C');
        root=insertData(root,'I');
        Postorder(root);

}