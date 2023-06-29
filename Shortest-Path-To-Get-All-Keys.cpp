// Leetcode 864
class Solution {
public:
    bool checkBounds(int x, int y, int m, int n){
        if(x < 0 || y < 0 || x >= m || y >= n) return false;
        return true;
    }
    bool isKey(char& ch){
        if(ch>='a' && ch<='z') return true;
        return false;
    }
    bool isLock(char& ch){
        if(ch>='A' && ch<='Z') return true;
        return false;
    }
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        queue<tuple<int, int, int, int>> q;
        int totalKeys = 0;
        int s_x, s_y;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='@'){
                    s_x = i, s_y = j;
                    q.push(tuple<int, int, int, int>(i, j, 0, 0));
                }
                if(isKey(grid[i][j])){
                    totalKeys++;
                }
            }
        }
        // the ability to go and traverse depends on the current no. of keys acquired, since
        // from current position there may be a path that leads to blockage due to presence of a lock
        // so, out state change does not only contain x & y, it will contain x, y and keys acquired so far
        // [from a particular key to a particular lock there exists only one way, also here multiple
        // traversal of cells are possible since, we may get a key for a lock that was present on
        // such a location that leads to multiple traversals]
        unordered_map<string, bool> visited;
        string temp = to_string(0) + " " + to_string(s_x) + " " + to_string(s_y);
        visited[temp] = true;
        int steps = 0;
        while(!q.empty()){
            auto f = q.front(); q.pop();
            int x = get<0>(f), y = get<1>(f), dist = get<2>(f), keysTillNow = get<3>(f);
            if(keysTillNow == (1 << totalKeys)-1){
                return dist;
            }
            for(auto& mm: moves){
                int dx = mm.first, dy = mm.second;
                int new_x = x + dx, new_y = y + dy, new_keysTillNow = keysTillNow;
                if(checkBounds(new_x, new_y, m, n)){
                    if(grid[new_x][new_y]!='#'){
                        if(isKey(grid[new_x][new_y])){
                            int key = grid[new_x][new_y] - 'a';
                            new_keysTillNow = (keysTillNow | (1<<key));
                        }else if(isLock(grid[new_x][new_y])){
                            int reqKey = tolower(grid[new_x][new_y]) - 'a';
                            if(!(new_keysTillNow & (1<<reqKey))){
                                continue;
                            }
                        }
                        string temp = to_string(keysTillNow) + " " + to_string(new_x) + " " + to_string(new_y);
                        if(visited.find(temp)==visited.end()){
                            visited[temp] = true;
                            q.push(tuple<int, int, int, int>(new_x, new_y, dist+1, new_keysTillNow));
                        }

                    }
                }
            }

            steps++;

        }
        return -1;
    }
};