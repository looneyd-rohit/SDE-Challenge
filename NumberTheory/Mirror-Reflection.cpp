// Leetcode 858

class Solution {
public:
    int mirrorReflection(int p, int q) {
        // pretty bad problem:
        int extension = q, reflection = p;    // extension * p == reflection * q

        // when either of them becomes odd we get an answer
        while(extension % 2 == 0 && reflection % 2 == 0){
            extension /= 2;
            reflection /= 2;
        }

        if(!(extension & 1) && (reflection & 1)) return 0;
        if((extension & 1) && !(reflection & 1)) return 2;
        if((extension & 1) && (reflection & 1)) return 1;

        return -1;
    }
};