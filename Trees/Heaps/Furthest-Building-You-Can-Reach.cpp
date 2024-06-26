// Leetcode 1642

// Approach: using heaps + lazy greedy approach
class Solution {
public:
  int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
    int n = heights.size();
    // recursion works --> but constrains are so high that it will fail
    // approach: use bricks by default, and go on storing them on a data
    // structure as and when moment arrives when we cannot use bricks anymore
    // check the previous usages of bricks and try to reduce that usage by
    // swapping that with ladders
    priority_queue<int> maxheap;
    int ans = 0;
    for (int i = 1; i < n; i++) {
      int diff = heights[i] - heights[i - 1];
      if (diff <= 0)
        ans = i;
      else {
        // we need to use bricks or ladders
        if (bricks >= diff) {
          bricks -= diff;
          ans = i;
          maxheap.push(diff);
        } else {
          // bricks cannot be used now
          // try and remove brick usages if used before
          // and swap them with ladders
          if (maxheap.size() > 0) {
            int maxi = maxheap.top();
            if (maxi >= diff) {
              if (ladders > 0) {
                maxheap.pop();
                bricks += maxi;
                ladders--;
              } else {
                // else not possible to go further
                return ans;
              }
              // use bricks now for current
              bricks -= diff;
              maxheap.push(diff);
              ans = i;
            } else {
              // even the maximum brick amount used is
              // smaller than current requirement, so
              // use ladders if available
              if (ladders > 0) {
                ladders--;
                ans = i;
              } else {
                return ans;
              }
            }
          } else {
            // no bricks used before and current requirement
            // also cannot be fulfilled
            // use ladders if possible
            if (ladders > 0) {
              ladders--;
              ans = i;
            } else {
              return ans;
            }
          }
        }
      }
    }
    return ans;
  }
};

// Approach: (same as above but shorter code)
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> pq;    // to store the bricks, replace max bricks with one ladder
        for(int i=0; i<n-1; i++){
            int left = heights[i], right = heights[i+1];
            if(left >= right){
                continue;
            }else{
                // use bricks pre-dominantly
                bricks -= (right - left);
                pq.push(right-left);
                if(bricks < 0){
                    // bricks can't go negative, so replace with ladders if available
                    if(ladders > 0){
                        int t = pq.top(); pq.pop();
                        bricks += t;
                        ladders--;
                    }else{
                        // cannot reach i+1 building
                        return i;
                    }
                }
            }
        }
        return n-1;
    }
};