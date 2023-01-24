#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
    int front;
    int rear;
    int *arr;
    int size;

    Queue(){
        size = 1000;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    
    void enqueue(int value){
        if(front == -1){
            front = 0;
        }
        rear++;
        arr[rear]  = value;
    }

    int dequeue(){
        int ele = arr[rear];
        rear--;
        return ele;
    }

    int peek(){
        return arr[front];
    }

    int Size(){
        return rear + 1;
    }
};

int main(){
    Queue q;
    q.enqueue(5);
    q.enqueue(7);
    cout<<q.peek()<<endl;
    cout<<q.Size()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.peek()<<endl;
    return 0;
}   