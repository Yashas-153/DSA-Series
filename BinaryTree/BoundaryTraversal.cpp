#include<bits/stdc++.h>
using namespace std;

//         1
//      2      3
//   4    5  7   6   
//                 8


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

void getLeftBoun(node* root, vector<int> &arr){
    if(root == NULL){
        return;
    }
    if(root->left == NULL and root->right == NULL)
        return;
    arr.push_back(root->data);
    if(root->left != NULL){
        getLeftBoun(root->left,arr);
    }
    else{
        getLeftBoun(root->right,arr);
    }
}

void getLeafNodes(node* root, vector<int> &arr){
    if(root== NULL){
        return;
    }
    if(root->left == NULL and root->right == NULL){
        arr.push_back(root->data);
    }
    getLeafNodes(root->left,arr);
    getLeafNodes(root->right,arr);
}

void getRightBoun(node* root,vector<int> &arr){
    if(root == NULL){
        return;
    }
    if(root->left == NULL and root->right == NULL)
        return;
    arr.push_back(root->data);
    if(root->right != NULL){
        getRightBoun(root->right,arr);
    }
    else{
        getRightBoun(root->left,arr);
    }
    
}
void boundary(node * root){
    vector<int> arr;
    getLeftBoun(root, arr);
    getLeafNodes(root,arr);
    vector<int> rgt;
    getRightBoun(root->right,rgt);
    for(int i =rgt.size()-1;i>=0;i--){
        arr.push_back(rgt[i]);
    }
    for(auto x: arr){
        cout<<x<<" ";
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
    root->right ->left = new node(7);
    root-> right-> right-> right = new node(8);
    boundary(root);

}