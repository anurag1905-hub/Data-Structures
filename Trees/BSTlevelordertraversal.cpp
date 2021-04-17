#include<iostream>
#include<queue>
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

void levelordertraversal(BstNode* root){
    if(root==NULL){
        return;
    }
    else{
        queue<BstNode*>q;
         q.push(root);
        while(!q.empty()){
            BstNode* current=q.front();
            cout<<current->data<<" ";
            if(current->left!=NULL){
                q.push(current->left);
            }
            if(current->right!=NULL){
                q.push(current->right);
            }
            q.pop();
        }

    }
}
int main(){
           BstNode* root=NULL;
           root=insertData(root,3);
           root=insertData(root,8);
           root=insertData(root,11);
           root=insertData(root,25);
           root=insertData(root,87);
           root=insertData(root,9);
           root=insertData(root,-4);
           root=insertData(root,9);
           root=insertData(root,5);
           levelordertraversal(root);

}