// Leetcode 1442

// Approach 1: Brute Force T.C: O(N^3), S.C: O(N)
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixXor(n, arr[0]);
        for(int i=1; i<n; i++) prefixXor[i] = prefixXor[i-1] ^ arr[i];
        int count = 0;
        // given: i < j <= k
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j; k<n; k++){
                    int leftXor = prefixXor[j-1] ^ (i > 0 ? prefixXor[i-1] : 0);
                    int rightXor = prefixXor[k] ^ prefixXor[j-1];
                    if(leftXor == rightXor){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

// Approach 2: Little Optimized T.C: O(N^2), S.C: O(N)
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> xors;
        xors[0].push_back(-1);
        int curr = 0;
        // given: i < j <= k
        int count = 0;
        for(int i=0; i<n; i++){
            curr = curr ^ arr[i];
            if(xors.find(curr)!=xors.end()){
                for(auto& ind: xors[curr]){
                    count += (i - ind - 1);
                }
            }
            xors[curr].push_back(i);
        }
        return count;
    }
};

// Approach 3: Most Optimized T.C: O(N), S.C: O(N)
// Since, we need to subtract the sum of the previous indices we can store only the sum,
// and their count, hence
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> count, total;
        count[0] = 1;
        total[0] = 0;
        int curr = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            curr = curr ^ arr[i];
            cnt += count[curr] * (i) - total[curr] ;
            count[curr]++;
            total[curr] += i+1;
        }
        return cnt;
    }
};