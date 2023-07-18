// https://www.codingninjas.com/studio/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;
int getKthLargest(vector<int> &arr, int k)
{
    // store all subarrays in minheap of size k
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> minheap;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            minheap.push(sum);
            if(minheap.size() > k){
                minheap.pop();
            }
        }
    }
    return minheap.top();
}