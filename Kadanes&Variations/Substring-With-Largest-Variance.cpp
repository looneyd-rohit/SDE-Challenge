// Leetcode 2272
// Follow Leetcode Editorial to catch up
// Excellent and [IMP] question variation on Kadane's Algorithm

class Solution {
public:
    int largestVariance(string s) {
        int n = s.length();
        int result = 0;
        for(char ch1='a'; ch1<='z'; ch1++){
            for(char ch2='a'; ch2<='z'; ch2++){
                if(ch1==ch2) continue;
                int f1 = 0, f2 = 0;
                bool seen_in_past = false;
                for(int i=0; i<n; i++){
                    if(s[i]==ch1) f1++;
                    else if(s[i]==ch2) f2++;

                    if(f2>0){
                        result = max(result, f1-f2);
                    }else if(seen_in_past){
                        result = max(result, f1-1);
                    }

                    if(f2>f1) f1=f2=0, seen_in_past = true;
                }
            }
        }
        return result;
    }
};
