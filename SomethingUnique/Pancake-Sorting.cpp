// Leetcode 969

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        int prev = 0, prevInd = -1;
        vector<int> ans;
        while(prevInd < n){
            // uptil prev we have found all the sorted characters of the array
            // now we need to find the next number
            int next = prev + 1, nextInd = prevInd + 1;
            while(nextInd < n && arr[nextInd] != next) nextInd++;

            // [(...)prev....next....] --> reverse the part from start till next
            // then reverse the part from next till prev
            // them reverse again the whole part
            if(nextInd != prevInd + 1){
                // reverse(begin(arr), begin(arr)+nextInd+1);
                reverse(begin(arr)+prevInd+1, begin(arr)+nextInd+1);
                ans.push_back(nextInd+1);
                if(prevInd != -1){
                    // not required for very first element
                    // reverse(begin(arr), begin(arr)+nextInd-prevInd);
                    // reverse(begin(arr), begin(arr)+nextInd+1);
                    ans.push_back(nextInd-prevInd);
                    ans.push_back(nextInd+1);
                }
            }
            prev = next;
            prevInd++;
        }
        return ans;
    }
};