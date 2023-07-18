// https://www.codingninjas.com/studio/problems/build-min-heap_1171167?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h> 
using namespace std;

void heapify(vector<int>& arr, int index){
    
    int current = index;
    int leftChild = 2*index + 1;
    int rightChild = 2*index + 2;
    
    // now, find the smallest among current, leftChild and rightChild
    // and then put the smallest to the current index
    if(leftChild < arr.size() && arr[current] > arr[leftChild]){
        current = leftChild;
    }
    if(rightChild < arr.size() && arr[current] > arr[rightChild]){
        current = rightChild;
    }
    
    // now swap if current is not pointing to index
    if(current != index){
        swap(arr[index], arr[current]);
        // recursively call forward
        heapify(arr, current);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    // to build a heap we need heapify() method
    // 0-based indexing, so nodes from 0 to n/2-1 needs to be accounted for
    int n = arr.size();
    for(int i=n/2-1; i>=0; i--){
        heapify(arr, i);
    }
    return arr;
}
