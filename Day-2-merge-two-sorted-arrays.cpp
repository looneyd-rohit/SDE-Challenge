class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // gap method:
        int totalLen = m + n;
        int gap = (totalLen / 2) + (totalLen % 2);
        while(gap > 0){
            int i=0, j=gap+i;
            while(j < totalLen){
                // if i and j are on different indices
                if(i<m && j>=m){
                    if(nums1[i] > nums2[j-m]){
                        swap(nums1[i], nums2[j-m]);
                    }
                }
                // if i and j both are on arr2
                else if(i>=m){
                    if(nums2[i-m] > nums2[j-m]){
                        swap(nums2[i-m], nums2[j-m]);
                    }
                }
                // if i and j both are on arr1
                else{
                    if(nums1[i] > nums1[j]){
                        swap(nums1[i], nums1[j]);
                    }
                }
                i++; j++;
            }
            if(gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
        for(int i=0; i<nums2.size(); i++){
            nums1[m+i]=nums2[i];
        }
    }
};