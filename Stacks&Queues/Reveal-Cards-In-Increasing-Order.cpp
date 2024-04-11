// Leetcode 950

// Approach: simple simulation
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        deque<int> dq;
        sort(begin(deck), end(deck));
        for(int i=n-1; i>=0; i--){
            if(!dq.empty()){
                int last = dq.back(); dq.pop_back();
                dq.push_front(last);
            }
            dq.push_front(deck[i]);
        }
        return vector<int>(begin(dq), end(dq));
    }
};