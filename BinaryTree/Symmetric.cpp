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
//   4    5  7   6   
//                 8
bool issymmetric(node* root1, node * root2){
    if(root1 == NULL || root2 == NULL){
        return root1==root2;
    }

    return issymmetric(root1->left, root2->right) and root1->data == root2->data and issymmetric(root1->right, root2->left);

}

bool symmetric(node *root){
    if(root== NULL){
        return true;
    }
    if(!root->left and !root->right){
        return true;
    }
    return issymmetric(root->left, root->right);
    
}

int main(){

    node * root;
    root = new node(1);
    root->left = new node(2);
    root->right = new node(2);
    // root->left ->left = new node(3);
    // root->left->right = new node(4);
    // root->right ->left = new node(4);
    // root->right ->right = new node(5);
    cout<<symmetric(root);
    return 0;
}