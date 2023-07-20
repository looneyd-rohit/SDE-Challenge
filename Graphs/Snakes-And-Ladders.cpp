// Leetcode 909
// [IMP]: MSBFS Pattern
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        // seems like MSBFS should be applied
        int n = board.size();
        vector<int> vBoard;
        for(int i=n-1; i>=0; i--){
            vector<int> temp = board[i];
            int diff = n - i;
            if(!(diff & 1)){
                // right to left
                // reverse it
                reverse(begin(temp), end(temp));
            }
            for(auto& e: temp) vBoard.push_back(e);
        }

        vector<bool> visited(n*n, false);
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0] = true;
        while(!q.empty()){
            auto f = q.front(); q.pop();
            int node = f.first, dist = f.second;
            if(node == n*n - 1) return dist;
            // visit neighbours
            for(int move=1; move<=6; move++){
                int next_node = min(node + move, n*n-1);
                int val = vBoard[next_node];
                if(val == -1){
                    // no snake or ladder
                    if(!visited[next_node]){
                        visited[next_node] = true;
                        q.push({next_node, dist+1});
                    }
                }else{
                    // presence of snake or ladder
                    // go to the place pointed by the snake or ladder
                    val--;
                    next_node = val;
                    if(!visited[next_node]){
                        visited[next_node] = true;
                        q.push({next_node, dist+1});
                    }
                }
            }
        }
        return -1;
    }
};