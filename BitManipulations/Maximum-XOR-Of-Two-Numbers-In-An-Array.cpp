// Leetcode 421

// Approach 1:
// [IMP]: legit super question on bit manipulations, legendary
// excellent
class Solution {
public:
    int solve(vector<int>& nums, int target, int ans){
        unordered_set<int> hash;;
        for(auto& num: nums){
            int setBits = num & target;
            int remainingRequired = setBits ^ target;
            if(hash.count(remainingRequired)){
                // target can be achieved
                return target;
            }
            hash.insert(setBits);
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        // logic: we have to maximize the xor, so in order to maximize we need more and more
        // set bits in th 0 - 31 position, also the set bits should be more towards the msb
        // of the resulting number, now we find pairs iterating for every i-th bit and looking for
        // if the i-th bit can be set or not. Also, while checking for the next i-th bit, preserve
        // the current i-th bit in the number we are looking for
        int ans = 0;
        for(int i=31; i>=0; i--){
            // start from msb since we are needed to maximize
            ans = solve(nums, ans | (1<<i), ans);
        }
        return ans;
    }
};

// Approach 2:
// [IMP]: Trie based
class Node{
public:
    Node* left;
    Node* right;
    Node(Node* left = NULL, Node* right = NULL){
        this->left = left;
        this->right = right;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        // convert all the numbers into trie representation, so that we can check for each
        // possibility that exists for maximizing the xor between two numbers
        // construct the trie
        Node* root = new Node();
        for(int i=0; i<n; i++){
            int num = nums[i];
            Node* crawl = root;
            for(int i=31; i>=0; i--){
                bool flag = num & (1 << i);
                if(flag){    // bit is 1
                    if(crawl->right==NULL){
                        crawl->right = new Node();
                    }
                    crawl = crawl->right;
                }else{    // bit is 0
                    if(crawl->left==NULL){
                        crawl->left = new Node();
                    }
                    crawl = crawl->left;
                }
            }
        }
        int maxXor = 0;
        for(int i=0; i<n; i++){
            int num = nums[i];
            Node* crawl = root;
            int res = 0;
            for(int i=31; i>=0; i--){
                bool flag = num & (1 << i);
                if(flag){    // bit is 1
                    // try to take 0 if exists
                    if(crawl->left){
                        crawl = crawl = crawl->left;
                        res = res | (1 << i);
                    }else{
                        crawl = crawl->right;
                    }
                }else{    // bit is 0
                    // try to take 1 if exists
                    if(crawl->right){
                        crawl = crawl = crawl->right;
                        res = res | (1 << i);
                    }else{
                        crawl = crawl->left;
                    }
                }
            }
            maxXor = max(maxXor, res);
        }
        return maxXor;
    }
};