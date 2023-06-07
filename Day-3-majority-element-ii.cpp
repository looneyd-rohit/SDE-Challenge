#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Moore's voting algorithm
    // approach: forming triples (a, b, c) where a!=b && b!=c
    int n = arr.size();
    int element1 = INT_MIN, cnt1 = 0, element2 = INT_MIN, cnt2 = 0;
    // first pass generates candidates
    for(int i=0; i<n; i++){
        if(arr[i]==element1){
            cnt1++;
        }else if(arr[i]==element2){
            cnt2++;
        }else if(cnt1==0){
            cnt1 = 1;
            element1 = arr[i];
        }else if(cnt2==0){
            cnt2 = 1;
            element2 = arr[i];
        }else{
            cnt1--; cnt2--;
        }
    }

    // second pass verifies triples
    cnt1 = 0, cnt2 = 0;
    for(int i=0; i<n; i++){
        if(arr[i]==element1) cnt1++;
        else if(arr[i]==element2) cnt2++;
    }
    vector<int> ans;
    if(cnt1>n/3) ans.push_back(element1);
    if(cnt2>n/3) ans.push_back(element2);
    return ans;
}