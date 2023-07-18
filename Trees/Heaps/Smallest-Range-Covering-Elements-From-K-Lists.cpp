// Leetcode 632

class Node{
    public:
    int val, x, y;
    Node(int val, int x, int y){
        this->val = val;
        this->x = x;
        this->y = y;
    }
};
class CompareMin{
    public:
    bool operator()(Node* a, Node* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<Node*, vector<Node*>, CompareMin> minheap;
        // using minheap --> we can get min in O(1) time, we just need the max so using maxi
        // variable to get it
        int maxi = -1e9, diff = 2e9;
        for(int i=0; i<k; i++){
            maxi = max(maxi, nums[i][0]);
            minheap.push(new Node(nums[i][0], i, 0));
        }
        diff = maxi - minheap.top()->val;
        int minans = minheap.top()->val, maxans = maxi;
        while(!minheap.empty()){
            auto mintop = minheap.top(); minheap.pop();
            
            int currdiff = maxi - mintop->val;
            if(diff > currdiff){
                diff = currdiff;
                maxans = maxi;
                minans = mintop->val;
            }
            
            // now add next elements
            int xmin = mintop->x, ymin = mintop->y;
            if(ymin+1 < nums[xmin].size()){
                // new element, getting added so update maxi
                maxi = max(maxi, nums[xmin][ymin+1]);
                minheap.push(new Node(nums[xmin][ymin+1], xmin, ymin+1));
            }else{
                // every array element not included, so break
                break;
            }
        }
        return {minans, maxans};
    }
};