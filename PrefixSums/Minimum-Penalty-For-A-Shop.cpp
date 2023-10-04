// Leetcode 2483
// Approach 1: T.C. ~ O(N), S.C. ~ O(N)
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> prefSums(n, 0);
        for(int i=0; i<customers.size(); i++){
            prefSums[i] += (i > 0 ? prefSums[i-1] : 0) + (customers[i]=='Y');
        }
        int minPenalty = prefSums.back();    // initially assume shop is closed at 0-th hour
        int minIndex = 0;    // initially assume shop is closed at 0-th hour
        for(int i=0; i<n; i++){
            // closed at i-th hour
            // calculate penalty
            // left side --> count all N's
            // right side --> count all Y's
            int left = i+1 - prefSums[i] - (customers[i]=='N');
            int right = prefSums.back() - (i > 0 ? prefSums[i-1] : 0);
            if(minPenalty > left+right){
                minPenalty = left+right;
                minIndex = i;
            }else if(minPenalty == left+right){
                minIndex = min(minIndex, i);
            }
        }
        // edge case check last index = n
        if(n-prefSums.back() < minPenalty){
            return n;
        }
        return minIndex;
    }
};

// Approach 2: T.C. ~ O(N), S.C. ~ O(1)
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int totalY = 0;
        for(int i=0; i<customers.size(); i++){
            totalY += (customers[i]=='Y');
        }
        int minPenalty = totalY, left = 0, right = totalY;    // initially assume shop is closed at 0-th hour
        int minIndex = 0;    // initially assume shop is closed at 0-th hour
        for(int i=0; i<n; i++){
            // closed at i-th hour
            // calculate penalty
            // left side --> count all N's
            // right side --> count all Y's
            if(minPenalty > left+right){
                minPenalty = left+right;
                minIndex = i;
            }else if(minPenalty == left+right){
                minIndex = min(minIndex, i);
            }
            if(customers[i]=='N'){
                left++;
            }else{
                right--;
            }
        }
        // edge case check last index = n
        if(n-totalY < minPenalty){
            return n;
        }
        return minIndex;
    }
};