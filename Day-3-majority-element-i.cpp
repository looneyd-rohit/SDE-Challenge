// #include <bits/stdc++.h>

// int findMajorityElement(int arr[], int n) {
// 	// Moore's voting algorithm
// 	int majorityElement = arr[0];
// 	int cnt = 1;
// 	for(int i=1; i<n; i++){
// 		if(arr[i] == majorityElement){
// 			cnt++;
// 		}else{
// 			cnt--;
// 			if(cnt==0){
// 				majorityElement = arr[i];
// 				cnt = 1;
// 			}
// 		}
// 	}
// 	// first step either gives the majority element or gives some element that may
// 	// be eligible for majority element (edge case when cnt of an element is equal
// 	// to n/2 then it is not majority element but majorityElement contains it)
// 	cnt = 0;
// 	for(int i=0; i<n; i++) if(arr[i] == majorityElement) cnt++;
// 	return (cnt > n/2) ? majorityElement : -1;
// }


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        // approach: forming pairs of (a, b) where a!=b
        int cnt = 0, element = INT_MIN;
        for(int i=0; i<n; i++){
            if(nums[i]==element){
                cnt++;
            }else if(cnt==0){
                cnt = 1;
                element = nums[i];
            }else{
                cnt--;
            }
        }
        return element;
    }
};