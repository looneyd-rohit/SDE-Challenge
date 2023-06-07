#include <bits/stdc++.h>
int merge(int low, int mid, int high, long long *arr, int n){
    int size1 = mid - low + 1;
    int size2 = high - mid;
    int i=0, j=0, cnt=0;
    while(i<size1 && j<size2){
        if(arr[low+i] > arr[mid+1+j]){
            cnt += size1 - i;
            j++;
        }else{
            i++;
        }
    }
    sort(arr+low, arr+high+1);
    return cnt;
}
int mergeSort(int low, int high, long long *arr, int n){
    int cnt = 0;
    if(low<high){
        int mid = low + ((high - low) >> 1);
        cnt += mergeSort(low, mid, arr, n);
        cnt += mergeSort(mid+1, high, arr, n);
        cnt += merge(low, mid, high, arr, n);
    }
    return cnt;
}
long long getInversions(long long *arr, int n){
    return mergeSort(0, n-1, arr, n);
}