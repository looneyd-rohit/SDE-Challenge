#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   int n = arr.size();
   sort(begin(arr), end(arr));
   int i=0, j=n-1;
   vector<vector<int>> ans;
   while(i<j){
      int first = arr[i], second = arr[j];
      int sum = first + second;
      if(sum == s){
         int new_i = i, new_j=j;
         while(new_i<j){
            if(arr[new_i]==first){
               new_i++;
            }else{
               break;
            }
         }
         while(new_j>i){
            if(arr[new_j]==second){
               new_j--;
            }else{
               break;
            }
         }
         int p = (first != second) ? (new_i-i) * (j-new_j) : (new_i-i+1)*(new_i-i)/2;
         while(p--) ans.push_back({first, second});
         i=new_i;
         j=new_j;
      }else if(sum < s){
         i++;
      }else{
         j--;
      }
   }
   return ans;
}