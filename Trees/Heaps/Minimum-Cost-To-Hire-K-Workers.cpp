// Leetcode 857

// Approach 1: brute force + TLE
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        double mini_cost = 1e10;
        for(int i=0; i<n; i++){
            int base = wage[i];
            vector<double> temp;
            for(int j=0; j<n; j++){
                if(i == j) continue;
                double d = quality[j] / (1.0 * quality[i]);
                if(wage[i] * quality[j] >= wage[j] * quality[i]){
                    temp.push_back(base * d);
                }
            }
            if(temp.size() < k-1) continue;
            sort(begin(temp), end(temp));
            double cost = base;
            for(int j=0; j<k-1; j++) cost += temp[j];
            mini_cost = min(mini_cost, cost);
            // cout<<cost<<endl;
        }
        return mini_cost;
    }
};

// [IMP] Approach 2: observation + optimized with sorting + priority queue to take smallest quality sums
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> qw;
        for(int i=0; i<n; i++){
            qw.push_back(make_pair(wage[i] / (1.0 * quality[i]), quality[i]));
        }
        sort(begin(qw), end(qw));
        int least_quality_sum = 0;
        priority_queue<int> pq;
        for(int i=0; i<k-1; i++){
            pq.push(qw[i].second);
            least_quality_sum += qw[i].second;
        }
        double mini_cost = 1e10;
        for(int i=k-1; i<n; i++){
            double curr_ratio = qw[i].first;
            int curr_quality = qw[i].second;
            mini_cost = min(mini_cost, (least_quality_sum + curr_quality) * curr_ratio);

            // update the quality sum taken previously
            pq.push(curr_quality);
            least_quality_sum += curr_quality;
            if(pq.size() >= k){
                least_quality_sum -= pq.top();
                pq.pop();
            }
        }
        return mini_cost;
    }
};