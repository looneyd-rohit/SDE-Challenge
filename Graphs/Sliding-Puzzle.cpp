// Leetcode 773

class Solution {
public:
  bool checkFinal(string &str) { return str == "123450"; }
  string convertBoardToString(vector<vector<int>> &board) {
    string ans = "";
    int m = 2, n = 3;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        ans.push_back((char)(board[i][j] + '0'));
      }
    }
    return ans;
  }
  int findZeroIndex(string &str) {
    for (int i = 0; i < str.length(); i++) {
      if (str[i] == '0')
        return i;
    }
    return -1;
  }
  vector<string> findAllPossibleMoves(string &node) {
    vector<string> ans;
    int zero_index = findZeroIndex(node);
    if (zero_index == 0) {
      swap(node[zero_index], node[zero_index + 1]);
      ans.push_back(node);
      swap(node[zero_index], node[zero_index + 1]);

      swap(node[zero_index], node[zero_index + 3]);
      ans.push_back(node);
      swap(node[zero_index], node[zero_index + 3]);
    } else if (zero_index == 1) {
      swap(node[zero_index], node[zero_index - 1]);
      ans.push_back(node);
      swap(node[zero_index], node[zero_index - 1]);

      swap(node[zero_index], node[zero_index + 1]);
      ans.push_back(node);
      swap(node[zero_index], node[zero_index + 1]);

      swap(node[zero_index], node[zero_index + 3]);
      ans.push_back(node);
      swap(node[zero_index], node[zero_index + 3]);
    } else if (zero_index == 2) {
      swap(node[zero_index], node[zero_index - 1]);
      ans.push_back(node);
      swap(node[zero_index], node[zero_index - 1]);

      swap(node[zero_index], node[zero_index + 3]);
      ans.push_back(node);
      swap(node[zero_index], node[zero_index + 3]);
    } else if (zero_index == 3) {
      swap(node[zero_index], node[zero_index + 1]);
      ans.push_back(node);
      swap(node[zero_index], node[zero_index + 1]);

      swap(node[zero_index], node[zero_index - 3]);
      ans.push_back(node);
      swap(node[zero_index], node[zero_index - 3]);
    } else if (zero_index == 4) {
      swap(node[zero_index], node[zero_index - 1]);
      ans.push_back(node);
      swap(node[zero_index], node[zero_index - 1]);

      swap(node[zero_index], node[zero_index + 1]);
      ans.push_back(node);
      swap(node[zero_index], node[zero_index + 1]);

      swap(node[zero_index], node[zero_index - 3]);
      ans.push_back(node);
      swap(node[zero_index], node[zero_index - 3]);
    } else if (zero_index == 5) {
      swap(node[zero_index], node[zero_index - 1]);
      ans.push_back(node);
      swap(node[zero_index], node[zero_index - 1]);

      swap(node[zero_index], node[zero_index - 3]);
      ans.push_back(node);
      swap(node[zero_index], node[zero_index - 3]);
    }
    return ans;
  }
  int slidingPuzzle(vector<vector<int>> &board) {
    int m = 2, n = 3;
    queue<pair<string, int>> q;
    string str = convertBoardToString(board);
    q.push({str, 0});
    unordered_map<string, bool> visited;
    while (!q.empty()) {
      auto f = q.front();
      q.pop();
      string node = f.first;
      int d = f.second;
      if (checkFinal(node))
        return d;
      if (visited[node])
        continue;
      visited[node] = true;
      // make moves
      vector<string> all_possibilities = findAllPossibleMoves(node);
      for (auto &e : all_possibilities) {
        q.push({e, d + 1});
      }
    }
    return -1;
  }
};