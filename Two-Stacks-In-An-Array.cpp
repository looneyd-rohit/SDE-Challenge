// https://www.codingninjas.com/studio/problems/two-stacks_983634?leftPanelTab=0&campaign=YouTube_CodestudioLovebabbar5thfeb&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_CodestudioLovebabbar5thfeb

#include <bits/stdc++.h> 
class TwoStack {
public:
    vector<int> arr;
    int top1, top2, size;
    // Initialize TwoStack.
    TwoStack(int s) {
        this->size = s;
        this->top1 = -1;
        this->top2 = s;
        arr.resize(s);
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(abs(top1 - top2) > 1){
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if(abs(top1 - top2) > 1){
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1 == -1) return -1;
        return arr[top1--];
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2 == this->size) return -1;
        return arr[top2++];
    }
};
