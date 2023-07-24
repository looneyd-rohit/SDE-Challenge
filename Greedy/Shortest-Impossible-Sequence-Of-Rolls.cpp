// Leetcode 2350

class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        // to generate a sequnce we need to fill postions, filling of positions is from
        // left towards right, so for filling a particualr position, try to find what is the
        // minimum right index that can fill all k postions for that index
        int n = rolls.size();
        unordered_set<int> hash;
        int minLenThatCanBeFulfilled = 0;
        for(int i=0; i<n; i++){
            hash.insert(rolls[i]);
            if(hash.size() == k){
                // time to check for next position
                minLenThatCanBeFulfilled++;
                hash.clear();
            }
        }
        return minLenThatCanBeFulfilled + 1;
    }
};