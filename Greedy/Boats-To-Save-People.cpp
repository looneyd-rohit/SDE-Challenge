// Leetcode 881

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(begin(people), end(people));
        int boats = 0;
        int i = 0, j = n-1;
        while(i < j){
            int sum = people[i] + people[j];
            if(sum <= limit){
                boats++;
                i++; j--;
            }else{
                boats++;
                j--;
            }
        }
        if(i==j) boats++;
        return boats;
    }
};