// Leetcode 79

// Approach: simple recursion + backtracking
class Solution {
public:
    bool solve(int i, int j, int ind, int m, int n, string& word, vector<vector<char>>& board){
        if(ind >= word.length()) return true;
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='$') return false;

        char temp = board[i][j];
        if(temp == word[ind]){
            board[i][j] = '$';
            bool a = solve(i+1, j, ind+1, m, n, word, board);
            bool b = solve(i-1, j, ind+1, m, n, word, board);
            bool c = solve(i, j+1, ind+1, m, n, word, board);
            bool d = solve(i, j-1, ind+1, m, n, word, board);
            board[i][j] = temp;
            return (a || b || c || d);
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(solve(i, j, 0, m, n, word, board)){
                    return true;
                }
            }
        }
        return false;
    }
};