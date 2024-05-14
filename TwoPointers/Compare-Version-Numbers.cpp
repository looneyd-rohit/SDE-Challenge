// Leetcode 165

// Approach: basic two pointers simulation
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.length(), n2 = version2.length();
        int i=0, j=0;
        int r1=0, r2=0;
        while(i<n1 || j<n2){
            int iend = i, jend = j;

            while(iend<n1 && version1[iend]!='.') iend++;
            while(jend<n2 && version2[jend]!='.') jend++;

            string str1 = (i < n1) ? version1.substr(i, iend-i) : "0";
            string str2 = (j < n2) ? version2.substr(j, jend-j) : "0";
            int num1 = stoi(str1), num2 = stoi(str2);

            if(num1 < num2) return -1;
            if(num1 > num2) return 1;

            i = iend + 1;
            j = jend + 1;
        }
        return 0;
    }
};