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

BstNode* find(BstNode* root,int data){
    if(root==NULL){
        return root;
    }
    else if(root->data==data){
        return root;
    }
    else if(root->data>data){
       return find(root->left,data);
    }
    else{
        return find(root->right,data);
    }
}

BstNode* FindMin(BstNode* root){
    if(root==NULL){
        return root;
    }
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

BstNode* GetSuccessor(BstNode* root,int data){
    BstNode* current=find(root,data);
    if(current==NULL){
        return NULL;
    }
    if(current->right!=NULL){
        return FindMin(current->right);
    }

    else{
        BstNode* successor=NULL;
        BstNode* ancestor=root;
        while(ancestor!=current){
            if(ancestor->data>current->data){
                successor=ancestor;
                ancestor=ancestor->left;
            }
            else{
                ancestor=ancestor->right;
            }
        }
        return successor;
    }

}
int main(){
    BstNode* root=NULL;
        root=insertData(root,15);
        root=insertData(root,10);
        root=insertData(root,20);
        root=insertData(root,8);
        root=insertData(root,12);
        root=insertData(root,17);
        root=insertData(root,25);
        root=insertData(root,6);
        root=insertData(root,11);
        root=insertData(root,16);
        root=insertData(root,27);
        BstNode* successor=GetSuccessor(root,12);
        if(successor==NULL){
            cout<<"No successor found"<<endl;
        }
        else{
            cout<<"Successor is "<<successor->data<<endl;
        }
        successor=GetSuccessor(root,6);
        if(successor==NULL){
            cout<<"No successor found"<<endl;
        }
        else{
            cout<<"Successor is "<<successor->data<<endl;
        }

}