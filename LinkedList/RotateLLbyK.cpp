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

node* RotateByK(node* head, int k){
    if( head == NULL){
        return NULL;
    }
    if(head->link == NULL){
        return head;
    }
    node *fir = head, *sec = head;
    int c = 0;
    while(c != k){
        fir = fir ->link;
        c++;
    }
    while(fir->link != NULL){
        sec = sec->link;
        fir = fir->link;
    }
    node * next = sec->link;
    fir-> link = head;
    head = next;
    sec->link = null;
    
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
    node *newhead = RotateByK(head,3);
    display(newhead);

    return 0;

}