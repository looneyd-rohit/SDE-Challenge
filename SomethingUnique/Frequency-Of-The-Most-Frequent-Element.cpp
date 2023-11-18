// Leetcode 1838

// Approach 1: Using Sorting + Binary Search to find the window that satisfy
class Solution {
public:
    int measureWindowBS(vector<int>& nums, int k, vector<long long>& pref, int chosenInd){
        int n = nums.size();
        long long target = nums[chosenInd];
        int low = 0, high = chosenInd;
        while(low <= high){
            int mid = low + ((high-low) >> 1);
            // take all the elements from [mid...chosenInd] and make them equal
            long long windowSum = (chosenInd - mid + 1) * target;
            long long originalSum = pref[chosenInd] - (mid > 0 ? pref[mid-1] : 0);
            long long diff = windowSum - originalSum;    // difference equal to no. of operations
            if(diff > k){
                // not possible for the entire window [mid...chosenInd] to be converted
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return (chosenInd - low + 1);
    }
    int maxFrequency(vector<int>& nums, int k) {
        // approach 1: using binary search
        // claim 1: for no. of operations to be minimum, chosen element which needs to have
        // maximum frequency should be present within the array (check to verify)
        // claim 2: sorting the array, helps, a chosen max freq element only has to ask
        // its previous members for the operation only (check to verify)
        int n = nums.size();
        sort(begin(nums), end(nums));
        vector<long long> pref(n, 0);
        pref[0] = nums[0];
        // computing prefix sum
        for(int i=1; i<n; i++) pref[i] = pref[i-1] + nums[i];
        int maxFreq = 1;    // maxFreq will atleast be 1
        for(int i=0; i<n; i++){
            // assume the current element
            int chosenInd = i;
            int freq = measureWindowBS(nums, k, pref, chosenInd);
            maxFreq = max(maxFreq, freq);
        }
        return maxFreq;
    }
};

// Approach 2: Sorting + Sliding Window to find the window that satisfy
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // approach 2: using sliding window
        // claim : sorting the array, helps, a chosen max freq element only has to ask
        // its previous members for the operation only (check to verify)
        // note: since the chosen element only has to ask elements before it, therefore it can be
        // framed as a sliding window problem where window grows on one direction and shrinks on
        // another direction as the chosen element only has to check its smaller previous
        // elements whether they can form the window
        int n = nums.size();
        sort(begin(nums), end(nums));
        long long sum = 0;
        int i=0, j=0;
        int maxFreq = 1;    // maxFreq will atleast be 1
        while(j<n){
            sum += nums[j];

            long long windowSum = (j-i+1) * 1LL * nums[j];
            long long diff = windowSum - sum;    // difference equal to no. of operations

            while(diff > k){
                sum -= nums[i++];
                windowSum = (j-i+1) * 1LL * nums[j];
                diff = windowSum - sum;
            }

            maxFreq = max(maxFreq, j-i+1);

            // move to chose next target
            j++;
        }
        return maxFreq;
    }
};

// Approach 2 (optimized): Sorting + Sliding Window + while loop to if
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // approach 2: using sliding window
        // claim : sorting the array, helps, a chosen max freq element only has to ask
        // its previous members for the operation only (check to verify)
        // note: since the chosen element only has to ask elements before it (not ask elements after
        // it), therefore it can be framed as a sliding window problem where window grows on one
        // direction and shrinks on another direction as the chosen element only has to check
        // its smaller previous elements whether they can form the window
        int n = nums.size();
        sort(begin(nums), end(nums));
        long long sum = 0;
        int i=0, j=0;
        int maxFreq = 1;    // maxFreq will atleast be 1
        while(j<n){
            sum += nums[j];

            long long windowSum = (j-i+1) * 1LL * nums[j];
            long long diff = windowSum - sum;    // difference equal to no. of operations

            if(diff > k){    // we can convert the while loop to if
                             // because, once we get a larger window, there's no point
                             // shrinking to get another [target value wala window] which will
                             // be smaller since we are shrinking and can never be considered
                             // as answer, hence only increment the left pointer as we
                             // will only take into account if window size gets larger
                sum -= nums[i++];
                windowSum = (j-i+1) * 1LL * nums[j];
                diff = windowSum - sum;
            }

            maxFreq = max(maxFreq, j-i+1);

            // move to chose next target
            j++;
        }
        return maxFreq;
    }
};



