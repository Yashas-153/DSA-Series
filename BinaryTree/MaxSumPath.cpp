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

int maxSumPath(node* root, int sum){
    if(root == NULL){
        return 0;
    }
    int lsum = maxSumPath(root->left,sum);
    int rsum = maxSumPath(root->right, sum);

    sum = max(sum , lsum+ rsum + root->data) ;

    return lsum + rsum + root->data;

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