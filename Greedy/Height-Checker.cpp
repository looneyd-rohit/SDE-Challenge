// Leetcode 1051

// Approach: counting sort logic
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int> freq(101, 0);
        for(auto& h: heights) freq[h]++;
        int height = 0, count = 0;
        for(auto& h: heights){
            while(freq[height] == 0) height++;
            if(height != h) count++;
            freq[height]--; // as we are already visiting this item
        }
        return count;
    }
};