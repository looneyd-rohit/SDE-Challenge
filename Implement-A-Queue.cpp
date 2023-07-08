// https://www.codingninjas.com/studio/problems/queue-using-array-or-singly-linked-list_2099908?leftPanelTab=0&campaign=LoveBabbar_Codestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudio

#include <bits/stdc++.h> 
class Queue {
public:
    vector<int> arr;
    int qfront, rear, size;
    Queue() {
        size = 10000;
        arr.resize(10000);
        qfront = rear = -1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return qfront==-1;
    }

    void enqueue(int data) {
        if(qfront == -1){
            // first element
            qfront++; rear++;
            arr[rear] = data;
        }else{
            if(rear < size-1){
                rear++;
                arr[rear] = data;
            }
        }
    }

    int dequeue() {
        if(qfront == -1) return -1;
        else{
            int e = arr[qfront];
            qfront++;
            if(qfront > rear) qfront = rear = -1;
            return e;
        }
    }

    int front() {
        if(qfront == -1) return -1;
        return arr[qfront];
    }
};