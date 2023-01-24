#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }

};
void LevelOrderTraversal(node* root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL and root->right == NULL){
        cout<<root->data<<endl;
        return;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node * temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
}
int main(){
    node * root;
    root = new node(1);
    root->left = new node(2);
    root->right =new node(3);
    root ->left->left = new node(4);
    root ->left ->right = new node(5);
    root -> right -> right = new node(6);
    LevelOrderTraversal(root);
    return 0;
}