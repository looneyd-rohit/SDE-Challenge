// Leetcode 3171

// Approach 1: AND computation with bit array + prefix sum + binary search with monotonic AND function (decreasing property)
class Solution {
public:
    int minimumDifference(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> bitCount(n, vector<int>(31, 0));
        
        for (int i = 0; i < n; ++i) {
            int element = nums[i];
            for (int bit = 0; bit < 31; ++bit) {
                bitCount[i][bit] = (i > 0) ? bitCount[i - 1][bit] : 0;
                if (element & (1 << bit)) {
                    bitCount[i][bit]++;
                }
            }
        }

        int minDifference = 1e9;
        for (int i = 0; i < n; ++i) {
            int l = i, h = n - 1;
            while (l <= h) {
                int mid = l + ((h - l) >> 1);
                int value = 0;
                
                for (int bit = 0; bit < 31; ++bit) {
                    int count = bitCount[mid][bit] - ((i > 0) ? bitCount[i - 1][bit] : 0);
                    if (count == mid - i + 1) {
                        value |= (1 << bit);
                    }
                }

                minDifference = min(minDifference, abs(target - value));
                if (target < value) {
                    l = mid + 1;
                } else if (target > value) {
                    h = mid - 1;
                } else {
                    return 0;
                }
            }
        }

        return minDifference;
    }
};

// Approach 2: nearest zero approach for computing the possible and values of a subarray as it spans around indices
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> bitCount(n, vector<int>(31, 0));
        vector<vector<int>> nearestZero(n, vector<int>(31, n));
        // compute the bits array
        for (int i = 0; i < n; ++i) {
            int element = nums[i];
            for (int bit = 0; bit < 31; ++bit) {
                if (element & (1 << bit)) {
                    bitCount[i][bit]++;
                }
            }
        }
        // compute the nearest 0 for each bit
        for(int bit=0; bit<31; bit++){
            int nearest = n;
            for(int i=n-1; i>=0; i--){
                if(bitCount[i][bit]==0){
                    nearest = i;
                }else{
                    nearestZero[i][bit] = nearest;
                }
            }
        }
        

        int minDifference = 1e9;
        for (int i = 0; i < n; ++i) {
            int current = nums[i];

            minDifference = min(minDifference, abs(target-current));

            // extract the pair <index, nearest zero index> and compute the possibilities
            vector<pair<int, int>> possibilities;
            for(int bit=0; bit<31; bit++){
                if(bitCount[i][bit]==1 && nearestZero[i][bit]!=n){
                    possibilities.push_back({nearestZero[i][bit], bit});
                }
            }

            // sort
            sort(begin(possibilities), end(possibilities));

            for(int x=0; x<possibilities.size(); x++){
                int ind = possibilities[x].second;
                int nearest = possibilities[x].first;
                int y = x;
                for( ; y<possibilities.size(); y++){
                    if(possibilities[y].first == nearest){
                        current = current ^ ((1 << possibilities[y].second));
                    }else{
                        break;
                    }
                }
                minDifference = min(minDifference, abs(target-current));
                if(minDifference == 0) return 0;
                
                x = y - 1;
            }
        }

        return minDifference;
    }
};

// Approach 3: after performing AND operation multiple times each array element can have at maximum log(E) number of new elements, where E is the array element
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> visited;
        int mini = 1e9;
        for(int i=n-1; i>=0; i--){
            int e = nums[i];
            set<int> new_visited;
            for(auto& v: visited){
                new_visited.insert(v & e);
            }
            new_visited.insert(e);
            for(auto& v: new_visited){
                mini = min(mini, abs(k - v));
            }
            visited = new_visited;
        }
        return mini;
    }
};

// Approach 4: using sliding window + monotonicity of AND function
class Solution {
public:
    int computeAND(vector<vector<int>>& bitCount, int i, int j){
        int value = 0;
        for (int bit = 0; bit < 31; ++bit) {
            int count = bitCount[j][bit] - ((i > 0) ? bitCount[i - 1][bit] : 0);
            if (count == j - i + 1) {
                value |= (1 << bit);
            }
        }
        return value;
    }
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> bitCount(n, vector<int>(31, 0));
        
        for (int i = 0; i < n; ++i) {
            int element = nums[i];
            for (int bit = 0; bit < 31; ++bit) {
                bitCount[i][bit] = (i > 0) ? bitCount[i - 1][bit] : 0;
                if (element & (1 << bit)) {
                    bitCount[i][bit]++;
                }
            }
        }

        int i = 0, j = 0;
        int mini_diff = 1e9;
        while(j < n){
            // compute AND between i to j
            int value = computeAND(bitCount, i, j);

            mini_diff = min(mini_diff, abs(k - value));

            if(value < k){
                // try to increase value to decrease absolute difference
                while(i<=j && value < k){
                    // eliminate nums[i]
                    i++;
                    value = computeAND(bitCount, i, j);
                    mini_diff = min(mini_diff, abs(k - value));
                }
                j++;
            }else if(value > k){
                // try to decrease value to decrease absolute difference
                // include more items in computing AND -> increase sliding window
                j++;
            }else{
                return 0;
            }
        }
        return mini_diff;
    }
};