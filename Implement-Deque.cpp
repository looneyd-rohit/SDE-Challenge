// https://www.codingninjas.com/studio/problems/deque_1170059?leftPanelTab=0&campaign=LoveBabbar_Codestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudio

#include <bits/stdc++.h> 
class Deque
{
public:
    vector<int> arr;
    int qfront, rear, size;
    Deque(int n)
    {
        size = n;
        arr.resize(n);
        qfront = rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if(qfront == -1 && rear == -1){
            qfront = rear = 0;
            arr[qfront] = x;
            return true;
        }else{
            qfront--;
            if(qfront == -1){
                if(rear == size - 1){
                    qfront++;
                    return false;
                }else{
                    qfront = size - 1;
                    arr[qfront] = x;
                    return true;
                }
            }else{
                if(qfront == rear){
                    qfront++;
                    return false;
                }else{
                    arr[qfront] = x;
                    return true;
                }
            }
        }
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if(qfront == -1 && rear == -1){
            qfront = rear = 0;
            arr[qfront] = x;
            return true;
        }else{
            rear++;
            if(rear == size){
                if(qfront == 0){
                    rear--;
                    return false;
                }else{
                    rear = 0;
                    arr[rear] = x;
                    return true;
                }
            }else{
                if(qfront == rear){
                    rear--;
                    return false;
                }else{
                    arr[rear] = x;
                    return true;
                }
            }
        }
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(qfront == -1 && rear == -1){
            return -1;
        }else{
            int x = arr[qfront];
            if(qfront == rear){
                qfront = rear = -1;
            }else{
                qfront++;
                if(qfront == size){
                    qfront = 0;
                }
            }
            return x;
        }
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if(qfront == -1 && rear == -1){
            return -1;
        }else{
            int x = arr[rear];
            if(qfront == rear){
                qfront = rear = -1;
            }else{
                rear--;
                if(rear == -1){
                    rear = size-1;
                }
            }
            return x;
        }
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(qfront == -1 && rear == -1) return -1;
        else{
            return arr[qfront];
        }
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(qfront == -1 && rear == -1) return -1;
        else{
            return arr[rear];
        }
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        return (qfront==-1 && rear==-1);
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        return (qfront < rear && qfront==0 && rear==size-1) || (qfront > rear && (rear+1)==qfront);
    }
};