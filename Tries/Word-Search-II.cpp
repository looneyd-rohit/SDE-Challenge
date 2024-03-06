// Leetcode 212

// [IMP] Approach: trie + dfs
class Node {
public:
  vector<Node *> children;
  string word;
  bool isEnd;
  Node() {
    this->children.resize(26, NULL);
    this->isEnd = false;
    this->word = "";
  }
  bool containsKey(char ch) { return this->children[ch - 'a'] != NULL; }
  void insertChild(char ch, Node *node) { this->children[ch - 'a'] = node; }
  Node *getChild(char ch) { return this->children[ch - 'a']; }
  void markEnd() { this->isEnd = true; }
  void markWord(string &word) { this->word = word; }
  void unMarkWord() { this->word = ""; }
};
class Trie {
public:
  Node *root;
  Trie() { this->root = new Node(); };
  void insert(string &word) {
    Node *node = root;
    for (int i = 0; i < word.length(); i++) {
      if (!node->containsKey(word[i])) {
        // not present
        // insert
        node->insertChild(word[i], new Node());
      }
      node = node->getChild(word[i]);
    }
    // mark as end
    node->markEnd();
    node->markWord(word);
  }
};
class Solution {
public:
  void dfs(int i, int j, int m, int n, Node *root, string &temp,
           vector<vector<char>> &board, vector<string> &ans) {
    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$')
      return;
    char ch = board[i][j];
    if (root->containsKey(ch) == NULL)
      return;

    board[i][j] = '$';
    root = root->getChild(ch);
    if (root->word != "") {
      ans.push_back(root->word);
      root->unMarkWord(); // unmark the word as it can get counted multiple
                          // times
    }
    dfs(i - 1, j, m, n, root, temp, board, ans);
    dfs(i + 1, j, m, n, root, temp, board, ans);
    dfs(i, j - 1, m, n, root, temp, board, ans);
    dfs(i, j + 1, m, n, root, temp, board, ans);
    board[i][j] = ch;
  }
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    int m = board.size(), n = board[0].size();
    int w = words.size();
    // the compare step in recursive dfs taken O(N) time by itself hence gives
    // TLE we can decrease that comparison step by using tries
    Trie *trie = new Trie();
    for (int k = 0; k < w; k++) {
      trie->insert(words[k]);
    }
    vector<string> ans;
    string temp = "";
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (trie->root->containsKey(board[i][j])) {
          dfs(i, j, m, n, trie->root, temp, board, ans);
        }
      }
    }
    return ans;
  }
};