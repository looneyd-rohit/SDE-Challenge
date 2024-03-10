// Leetcode 1032

// [IMP] Approach: reverse trie search for suffix
class Node {
public:
  vector<Node *> children;
  bool isLeaf;
  Node() {
    this->children.resize(26, NULL);
    this->isLeaf = false;
  }
  bool containsKey(char ch) { return this->children[ch - 'a'] != NULL; }
  void putKey(char ch, Node *n) { this->children[ch - 'a'] = n; }
  Node *getKey(char ch) { return this->children[ch - 'a']; }
  void markEnd() { this->isLeaf = true; }
  void unMarkEnd() { this->isLeaf = false; }
};
class Trie {
public:
  Node *root;
  Trie() { this->root = new Node(); }
  void insert(string &word) {
    Node *temp = root;
    for (int i = 0; i < word.length(); i++) {
      if (!temp->containsKey(word[i])) {
        // create a new node for word[i]
        temp->putKey(word[i], new Node());
      }
      temp = temp->getKey(word[i]);
    }
    temp->markEnd();
  }
  bool search(string &word) {
    Node *temp = root;
    for (int i = word.length() - 1; i >= 0; i--) {
      if (!temp->containsKey(word[i])) {
        return false;
      }
      temp = temp->getKey(word[i]);
      if (temp->isLeaf)
        return true;
    }
    return false;
  }
};
class StreamChecker {
public:
  Trie *trie;
  string queryString;
  StreamChecker(vector<string> &words) {
    this->trie = new Trie();
    this->queryString = "";
    for (auto &word : words) {
      string temp = word;
      reverse(begin(temp), end(temp));
      trie->insert(temp);
    }
  }

  bool query(char letter) {
    queryString.push_back(letter);
    bool flag = trie->search(queryString);
    return flag;
  }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */