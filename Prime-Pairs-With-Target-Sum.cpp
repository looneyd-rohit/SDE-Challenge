// Leetcode 2761
// Sieve of Eratosthenes Logic:
class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        // sieve of eratosthenes
        vector<bool> primes(n+1, true);
        primes[0] = primes[1] = false;
        for(int i=2; i*i<=n; i++){
            if(primes[i]){
                for(int j=i*i; j<=n; j+=i){
                    primes[j] = false;
                }
            }
        }

        // now store in array to apply 2-sum logic:
        vector<int> req;
        for(int i=2; i<=n; i++){
            if(primes[i]){
                req.push_back(i);
            }
        }

        vector<vector<int>> ans;
        int i=0, j=req.size()-1;
        while(i<=j){
            int first = req[i], second = req[j];
            int sum = first + second;
            if(sum < n){
                i++;
            }else if(sum > n){
                j--;
            }else{
                ans.push_back({first, second});
                i++; j--;
            }
        }

        return ans;
    }
};