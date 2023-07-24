// https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies, candies+N);
        int mini=0, maxi=0;
        int i=0, j=N-1;
        while(i<=j){
            mini+=candies[i];
            i++; j-=K;
        }
        i=0, j=N-1;
        while(i<=j){
            maxi+=candies[j];
            i+=K; j--;
        }
        return {mini, maxi};
    }
};