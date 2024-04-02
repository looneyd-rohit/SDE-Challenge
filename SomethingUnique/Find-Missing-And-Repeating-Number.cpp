// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // using swap sort
        // this method works since any duplicate element is present twice, which means after
        // swap sort process one will be at correct index and one will be at incorrect index.
        // first put elements in their correct positions
        for(int i=0; i<n; i++){
            if(arr[i]!=arr[arr[i]-1]){
                swap(arr[i], arr[arr[i]-1]);
                i--;
            }
        }
        // now check which is the duplicate guy
        for(int i=0; i<n; i++){
            if(i!=arr[i]-1){
                return {arr[i], i+1};
            }
        }
        return {};
    }
};