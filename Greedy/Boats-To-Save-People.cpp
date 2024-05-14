// Leetcode 881

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(begin(people), end(people));
        int i=0, j=n-1;
        int boats = 0;
        while(i<=j){
            if((i!=j) && (people[i] + people[j] <= limit)){
                boats++;
                i++; j--;
            }else if(people[j] <= limit){
                boats++;
                j--;
            }else if(people[i] <= limit){
                boats++;
                i++;
            }
        }
        return boats;
    }
};