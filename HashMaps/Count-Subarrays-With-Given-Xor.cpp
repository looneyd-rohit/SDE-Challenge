// https://www.codingninjas.com/studio/problems/count-subarrays-with-given-xor_1115652?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    vector<int> prefixXor(n, arr[0]);
    for(int i=1; i<n; i++) prefixXor[i] = prefixXor[i-1] ^ arr[i];
    unordered_map<int, int> hash;
    int count = 0;
    for(int i=0; i<n; i++){
        int xorr = prefixXor[i];
        if(xorr == x) count++;
        int req = xorr ^ x;
        if(hash.find(req)!=hash.end()) count += hash[req];
        hash[xorr]++;
    }
    return count;
}