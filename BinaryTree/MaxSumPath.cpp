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

int maxSumPath(node* root, int &sum){
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
    root = new node(-10);
    root->left = new node(9);
    root ->right = new node(20);
    root-> right -> left = new node(15);
    root -> right -> right = new node(7);
    int sum = 0;
    cout<<maxSumPath(root,sum)<<endl;
    return 0;
}