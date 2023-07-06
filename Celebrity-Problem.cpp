// GFG: https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1


// Approach 1: brute force O(N^2)
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n)
    {
        for(int i=0; i<n; i++){
            // check if everybody knows celebrity --> i (assume i is celebrity)
            bool one = true;
            for(int j=0; j<n; j++){
                if(i == j) continue;
                if(M[j][i]!=1){
                    one = false;
                    break;
                }
            }
            
            // check if celebrity (i) does not know everybody
            bool two = true;
            for(int j=0; j<n; j++){
                if(i==j) continue;
                if(M[i][j]!=0){
                    two = false;
                    break;
                }
            }
            
            if(one && two) return i;
        }
        return -1;
    }
};

// Approach 2: brute force O(N)
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n)
    {
        stack<int> st;
        for(int i=0; i<n; i++) st.push(i);
        while(st.size() > 1){
            int first = st.top(); st.pop();
            int second = st.top(); st.pop();
            if(M[first][second] && M[second][first]) continue;
            else if(M[first][second] && !M[second][first]) st.push(second);
            else if(!M[first][second] && M[second][first]) st.push(first);
        }
        if(st.empty()) return -1;
        int candidate = st.top();
        for(int i=0; i<n; i++){
            if(i==candidate) continue;
            
            // check if everybody knows candidate
            if(!M[i][candidate]) return -1;
            
            // check if candidate knows anyone
            if(M[candidate][i]) return -1;
        }
        return candidate;
    }
};