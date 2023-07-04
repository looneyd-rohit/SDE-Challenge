// Leetcode 2748
class Solution {
public:
    int gcd(int a, int b)
    {
        if (a == 0) return b;
        if (b == 0) return a;
        if (a == b) return a;
        if (a > b) return gcd(a - b, b);
        return gcd(a, b - a);
    }
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int first = nums[i], second = nums[j];
                int n1 = to_string(first)[0] - '0', n2 = second % 10;
                int g = gcd(n1, n2);
                if(g == 1) cnt++;
            }
        }
        return cnt;
    }
};