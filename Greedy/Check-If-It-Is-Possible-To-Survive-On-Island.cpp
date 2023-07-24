// https://practice.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1

class Solution{
public:
    int minimumDays(int S, int N, int M){
        if(M > N) return -1;
        int noOfSundays = S / 7;
        int daysToBuy = ceil((1.0*M*S) / N);
        return daysToBuy > (S-noOfSundays) ? -1 : daysToBuy;
    }
};