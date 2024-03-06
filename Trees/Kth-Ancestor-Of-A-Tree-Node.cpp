// Leetcode 1483

// [IMP] Approach: binary lifting
class TreeAncestor {
public:
  vector<vector<int>> lift;
  TreeAncestor(int n, vector<int> &parent) {
    this->lift.resize(n, vector<int>(18, 0));
    for (int i = 0; i < n; i++)
      lift[i][0] = parent[i]; // 0-th -> 1st parent
    for (int j = 1; j < 18; j++) {
      for (int i = 0; i < n; i++) {
        if (lift[i][j - 1] == -1) {
          lift[i][j] = -1;
        } else {
          lift[i][j] =
              lift[lift[i][j - 1]][j - 1]; // j-th -> 2^j = 2^(j-1) * 2^(j-1)
        }
      }
    }
  }

  int getKthAncestor(int node, int k) {
    for (int j = 0; j < 18; j++) {
      if (k & (1 << j)) {
        if (lift[node][j] == -1)
          return -1;
        node = lift[node][j];
      }
    }
    return node;
  }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */