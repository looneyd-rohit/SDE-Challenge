// Leetcode 1539
class Solution
{
public:
    bool isPossible(vector<int> &arr, int k, int num)
    {
        int cnt = 0;
        bool isPresent = false;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > num)
            {
                break;
            }
            cnt++;
            if (arr[i] == num)
            {
                isPresent = true;
            }
        }
        // cnt --> gives the count of the nos. <= num
        if (isPresent)
        {
            cnt--;
            return (num - 1 - cnt) >= (k);
        }
        else
        {
            return (num - 1 - cnt) >= (k - 1);
        }
    }
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int low = 1, high = 2069;
        while (low <= high)
        {
            int mid = low + ((high - low) >> 1);
            bool flag = isPossible(arr, k, mid);
            // cout<<mid<<" : "<<flag<<endl;
            if (flag)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};