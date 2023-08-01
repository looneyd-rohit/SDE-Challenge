// Leetcode 2682

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        unordered_map<int, int> hash;
        int curr = 0;    // initially player 0 (taking 0-indexing) holds the ball
        int turn = 1;
        while(1){
            hash[curr]++;

            if(hash[curr] == 2) break;

            // find the next player
            int next = curr + (turn * k);

            next = next % n;

            curr = next;

            // update turn
            turn++;
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(hash.find(i)==hash.end()){
                // never received ball
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};