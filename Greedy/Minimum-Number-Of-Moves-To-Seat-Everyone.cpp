// Leetcode 2037

// Approach: sort and take absolute difference
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = seats.size();
        sort(begin(seats), end(seats));
        sort(begin(students), end(students));
        int total = 0;
        for(int i=0; i<n; i++){
            total += abs(seats[i] - students[i]);
        }
        return total;
    }
};