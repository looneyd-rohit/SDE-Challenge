// Leetcode 542

class Solution {
private:
    vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool checkBounds(int i, int j, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n) return false;
        return true;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
	    vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
	    queue<tuple<int, int, int>> q;
	    for(int i=0; i<m; i++){
	        for(int j=0; j<n; j++){
	            if(mat[i][j]==0){
	                distance[i][j] = 0;
	                q.push(tuple<int, int, int>(i, j, 0));
	            }
	        }
	    }
	    while(!q.empty()){
	        auto f = q.front(); q.pop();
	        
	        int x = get<0>(f), y = get<1>(f), dist = get<2>(f);
	        mat[x][y] = 0;
	        distance[x][y] = min(distance[x][y], dist);
	        for(auto& mm: moves){
	            int dx = mm.first, dy = mm.second;
	            int new_x = x + dx, new_y = y + dy;
	            if(checkBounds(new_x, new_y, m, n)){
	                if(mat[new_x][new_y]==1){
	                    q.push(tuple<int, int, int>(new_x, new_y, dist+1));
	                }
	            }
	        }
	    }
	    return distance;
    }
};