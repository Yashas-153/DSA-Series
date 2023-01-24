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

int height(node *root,int &diameter){
    if( root == NULL){
        return 0;
    }
    int lh = height(root->left,diameter);
    int rh = height(root->right,diameter);
    
    diameter = max(diameter , lh+rh);
    
    return 1 + max(lh,rh);
}

int Diameter(node *root){
    int diameter = 0;
    height(root,diameter);
    return diameter;
}

int main(){
    node * root;
    root = new node(1);
    root->left = new node(2);
    root->right =new node(3);
    //root ->left->left = new node(4);
    root -> right-> right = new node(5);
    root -> right ->left = new node(4);
    root -> right ->left ->left= new node(6);
    root -> right ->left ->left ->left = new node(7);
    root -> right -> right->left = new node(8);
    root-> right ->right->left->left = new node(9);
    cout<<Diameter(root)<<endl;
    return 0;
}