// Leetcode 2073

// Approach: observation
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            if(i<=k) sum += min(tickets[i], tickets[k]);
            else sum += min(tickets[i], tickets[k]-1);
        }
        return sum;
    }
};