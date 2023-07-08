// https://www.codingninjas.com/studio/problems/n-stacks-in-an-array_1164271?leftPanelTab=0

#include <bits/stdc++.h> 
class NStack
{
public:
    vector<int> arr, top, next;
    int freeIndex;
    int n, size;
    // Initialize your data structure.
    NStack(int N, int S)
    {
        this->n = N; this->size = S;
        this->freeIndex = 0;
        arr.resize(size);
        for(int i=0; i<size; i++) next.push_back(i+1);
        next[size-1] = -1; // last index won't have next free space pointer
        top.resize(n, -1);
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check if free space is available for pushing
        if(freeIndex == -1) return false;
        
        // capture free space
        int index = freeIndex;

        // push to arr
        arr[index] = x;

        // update free space
        freeIndex = next[index];

        // update next, as next will now point to next element and top changes
        next[index] = top[m-1];

        // update top
        top[m-1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check if stack is empty or not
        if(top[m-1] == -1) return -1;
        
        // get the top index
        int index = top[m-1];

        // update top, as element will get popped
        top[m-1] = next[index];

        // update next as, it will now point to free space rather than next stack
        // element
        next[index] = freeIndex;

        freeIndex = index;
        
        // capture popped element
        int x = arr[index];

        return x;
    }
};