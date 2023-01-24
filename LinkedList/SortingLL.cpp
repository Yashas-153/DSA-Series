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
    cout<<" NULL"<<endl;
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

void sortingLL(node* head){
    node * curr_i = head, *curr_j = head;
    while(curr_i->link != NULL){
        curr_j = curr_i->link;
        while(curr_j != NULL){
            //cout<<"j is"<<curr_j->data<<endl;
            if(curr_j->data < curr_i ->data){
                int temp = curr_i->data;
                curr_i->data = curr_j->data;
                curr_j->data = temp;
            }
            curr_j = curr_j ->link;
        }
        //cout<<"i is"<<curr_i->data<<endl;
        curr_i = curr_i -> link;
    }
}

int main(){
    node* head = NULL;
    insertAtTail(head,15);
    insertAtTail(head,9);
    insertAtTail(head,7);
    insertAtTail(head,2);
    insertAtTail(head,4);
    insertAtTail(head,1);
    insertAtTail(head,10);
    display(head);
    sortingLL(head);
    display(head);

    return 0;

}