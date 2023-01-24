#include <bits/stdc++.h>
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

bool checkBalanced(node *root){
    if(root == NULL){
        return true;
    }
    if((root->left == NULL and root->right != NULL) or root->left != NULL and root->right == NULL){
        return false;
    }
    return checkBalanced(root->left) and checkBalanced(root->right);

}

int main(){
    node * root;
    root = new node(1);
    root->left = new node(2);
    root->right =new node(3);
    root ->left->left = new node(4);
    root ->left ->right = new node(5);
    root -> right -> right = new node(6);
    root->right ->left = new node(7);
    root-> right-> right-> right = new node(8);
    cout<<checkBalanced(root);
    return 0;
}