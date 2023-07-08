// https://www.codingninjas.com/studio/problems/circular-queue_1170058?leftPanelTab=0&campaign=LoveBabbar_Codestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudio

#include <bits/stdc++.h> 
class CircularQueue{
    public:
    vector<int> arr;
    int front, rear, size;
    CircularQueue(int n){
        size = n;
        front = rear = -1;
        arr.resize(n, -1);
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if(front == -1){
            front = rear = 0;
            arr[rear] = value;
            return true;
        }else{
            if((rear+1)%size == front) return false;
            rear = (rear+1) % size;
            arr[rear] = value;
            return true;
        }
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front == -1) return -1;
        else{
            if(front == rear){
                int x = arr[front];
                front = rear = -1;
                return x;
            }else{
                int x = arr[front];
                front = (front+1)%size;
                return x;
            }
        }
    }
};