// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    // fixed sliding window question
    vector<long long> ans;
    deque<pair<long long, long long>> dq;
    long long i = 0, j = 0;
    while(j < N){
        if(A[j] < 0) dq.push_back({A[j], j});
        
        if(j - i + 1 < K){
            j++;
        }else if(j - i + 1 == K){
            if(!dq.empty()){
                ans.push_back(dq.front().first);
                if(i == dq.front().second) dq.pop_front();
            }else{
                ans.push_back(0);
            }
            i++; j++;
        }
    }
    return ans;
 }