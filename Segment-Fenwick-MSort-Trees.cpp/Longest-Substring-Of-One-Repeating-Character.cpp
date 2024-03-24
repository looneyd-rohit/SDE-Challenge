// Leetcode 2213

// [IMP] Approach: segment trees + merging of custom nodes of a segment tree
// based on characters / string (prefix+suffix merging concept)
struct Node {
public:
  int sz;
  int pref_l, suff_l, best_l;
  char pref_c, suff_c;
  Node(int sz = 0, int pref_l = 0, int suff_l = 0, int best_l = 0,
       char pref_c = '#', char suff_c = '#')
      : sz(sz), pref_l(pref_l), suff_l(suff_l), best_l(best_l), pref_c(pref_c),
        suff_c(suff_c) {}
};
class SGTree {
public:
  vector<Node *> segarr;
  SGTree(int n = 0) { this->segarr.resize(4 * n + 1, NULL); }

  inline void updateNode(Node *root, int sz = 0, int pref_l = 0, int suff_l = 0,
                         int best_l = 0, char pref_c = '#', char suff_c = '#') {
    root->sz = sz;
    root->pref_l = pref_l;
    root->pref_c = pref_c;
    root->suff_l = suff_l;
    root->suff_c = suff_c;
    root->best_l = best_l;
  }

  inline Node *merge(Node *n1, Node *n2) {
    Node *res = new Node();

    res->sz = n1->sz + n2->sz;

    // merge prefix
    if (n1->pref_l != n1->sz || n1->pref_c != n2->pref_c) {
      // merging does not occur when length is less or character mismatch
      res->pref_l = n1->pref_l;
      res->pref_c = n1->pref_c;
    } else {
      // merging will occur as length is full and character also matches
      res->pref_l = n1->pref_l + n2->pref_l;
      res->pref_c = n1->pref_c;
    }

    // merge suffix
    if (n2->suff_l != n2->sz || n2->suff_c != n1->suff_c) {
      // merging does not occur when length is less or character mismatch
      res->suff_l = n2->suff_l;
      res->suff_c = n2->suff_c;
    } else {
      // merging will occur as length is full and character also matches
      res->suff_l = n2->suff_l + n1->suff_l;
      res->suff_c = n2->suff_c;
    }

    // get the best string
    res->best_l = max({res->pref_l, res->suff_l, n1->best_l, n2->best_l});
    if (n1->suff_c == n2->pref_c) {
      res->best_l = max({res->best_l, n1->suff_l + n2->pref_l});
    }

    return res;
  }

  void build(int index, int low, int high, string &s) {
    if (low == high) {
      // create node and initialize
      this->segarr[index] = new Node(1, 1, 1, 1, s[low], s[low]);
      return;
    }
    int mid = low + ((high - low) >> 1);
    build(2 * index + 1, low, mid, s);
    build(2 * index + 2, mid + 1, high, s);
    this->segarr[index] =
        merge(this->segarr[2 * index + 1], this->segarr[2 * index + 2]);
  }

  void update(int index, int low, int high, int ind, char ch) {
    if (low == high) {
      // update
      updateNode(this->segarr[index], 1, 1, 1, 1, ch, ch);
      return;
    }
    int mid = low + ((high - low) >> 1);
    if (ind <= mid) {
      update(2 * index + 1, low, mid, ind, ch);
    } else {
      update(2 * index + 2, mid + 1, high, ind, ch);
    }
    this->segarr[index] =
        merge(this->segarr[2 * index + 1], this->segarr[2 * index + 2]);
  }
};
class Solution {
public:
  vector<int> longestRepeating(string s, string queryCharacters,
                               vector<int> &queryIndices) {
    int n = s.length();
    int k = queryIndices.size();
    SGTree *sgtree = new SGTree(n);
    sgtree->build(0, 0, n - 1, s);
    vector<int> ans;
    for (int i = 0; i < k; i++) {
      sgtree->update(0, 0, n - 1, queryIndices[i], queryCharacters[i]);
      ans.push_back(sgtree->segarr[0]->best_l);
    }
    return ans;
  }
};