// Leetcode 1700

// Approach: observation
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int zero_count = 0, one_count = 0;
        for(auto& e: students) zero_count += e==0, one_count += e==1;
        for(int i=0; i<n; i++){
            if(sandwiches[i]==0 && zero_count > 0){
                zero_count--;
            }else if(sandwiches[i]==1 && one_count > 0){
                one_count--;
            }else{
                return (n-i);
            }
        }
        return 0;
    }
};