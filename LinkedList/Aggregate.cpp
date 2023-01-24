#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* link;

    node(int val){
        data = val;
        link = NULL;
    }

};

void display(node* head){
    node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<"->";
        temp= temp-> link;
    }
    cout<<" NULL"<<
    endl;
} 
// 17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL
node* aggregate(node* head){
    node *x = head,*curr = head, *prev = NULL;
    node *left = NULL;
    while(curr != NULL){
        cout<<"current node is "<<curr->data<<endl;
        node * next;
        if(curr->data % 2 ==0){
            next = curr->link;
            curr->link = x;
            prev->link = next;
            if(x == head){
                head = curr;
            }
            else{
                left -> link = curr;       
            }
            left = curr;
            curr = next;
        }
        else{
            prev = curr;
            curr = curr->link;
        }
        display(head);
    }
    return head;
}


void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
   
    node* temp= head;
    while(temp-> link!= NULL){
        temp= temp-> link;
    }
    temp->link = n;

}

node* reverseALL(node* head){
    node* curr = head;
    node* prev = NULL;
    node* next;

    while(curr){
        next = curr->link;
        curr->link = prev;

        prev = curr;
        curr = next;
    }
    head = prev;
    return head;

}




int main(){
    node* head = NULL;
    insertAtTail(head,17);
    insertAtTail(head,15);
    insertAtTail(head,8);
    insertAtTail(head,9);
    insertAtTail(head,2);
    insertAtTail(head,4);
    insertAtTail(head,6);
    insertAtTail(head,11);
    display(head);
    node *newhead = aggregate(head);
    display(newhead);

    return 0;

}