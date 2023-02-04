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

//         1
//      2      3
//   4    5  6   7   
//                 8

node* lca(node* root, node* p, node* q){
    if(root == NULL or root == p or root == q){
        return root;
    }
    node* left = lca(root->left , p,q);
    node * right = lca(root->right , p,q);

    if(left == NULL){
        return right;
    }
    else if(right == NULL){
        return left;
    }
    else{
        return root;
    }
}


int main(){
    node * root;
    root = new node(1);
    root->left = new node(2);
    root->right =new node(3);
    root ->left->left = new node(4);
    root -> left -> right = new node(5);
    root -> right ->left = new node(6);
    root -> right ->right= new node(7);
    root -> right -> right->right = new node(8);
    node *p = root -> right -> right->right; 
    node *q = root -> right ->left ;
    cout<<lca(root,p,q) ->data <<endl;
    return 0;
}