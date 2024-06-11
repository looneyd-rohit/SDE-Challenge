// Leetcode 3179

// Approach: prefix sum technique
#include <vector>

class Solution {


private:
    std::vector<int> initializeArray(int n) {
        return std::vector<int>(n, 1);
    }

    std::vector<int> computePrefixSums(const std::vector<int>& arr, int mod) {
        int array_size = arr.size();
        std::vector<int> prefix_sums(array_size, 0);
        prefix_sums[0] = arr[0];
        
        for (int index = 1; index < array_size; ++index) {
            prefix_sums[index] = (prefix_sums[index - 1] + arr[index]) % mod;
        }
        
        return prefix_sums;
    }
    
    public:
    int valueAfterKSeconds(int n, int k) {
        const int MODULO_CONSTANT = 1000000007;
        std::vector<int> initial_array = initializeArray(n);
        
        for (int loop_counter = 0; loop_counter < k; ++loop_counter) {
            std::vector<int> prefix_sums = computePrefixSums(initial_array, MODULO_CONSTANT);
            updateArray(initial_array, prefix_sums);
        }
        
        return initial_array[n - 1];
    }

    void updateArray(std::vector<int>& arr, const std::vector<int>& prefix_sums) {
        int array_size = arr.size();
        for (int index = 0; index < array_size; ++index) {
            arr[index] = prefix_sums[index];
        }
    }
};
