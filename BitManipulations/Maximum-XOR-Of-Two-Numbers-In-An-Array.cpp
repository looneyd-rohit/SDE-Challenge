// Leetcode 421

// Approach 1:
// [IMP]: legit super question on bit manipulations, legendary
// excellent
class Solution {
public:
  int solve(vector<int> &nums, int target, int ans) {
    unordered_set<int> hash;
    ;
    for (auto &num : nums) {
      int setBits = num & target;
      int remainingRequired = setBits ^ target;
      if (hash.count(remainingRequired)) {
        // target can be achieved
        return target;
      }
      hash.insert(setBits);
    }
    return ans;
  }
  int findMaximumXOR(vector<int> &nums) {
    int n = nums.size();
    // logic: we have to maximize the xor, so in order to maximize we need more
    // and more set bits in th 0 - 31 position, also the set bits should be more
    // towards the msb of the resulting number, now we find pairs iterating for
    // every i-th bit and looking for if the i-th bit can be set or not. Also,
    // while checking for the next i-th bit, preserve the current i-th bit in
    // the number we are looking for
    int ans = 0;
    for (int i = 31; i >= 0; i--) {
      // start from msb since we are needed to maximize
      ans = solve(nums, ans | (1 << i), ans);
    }
    return ans;
  }
};

// Approach 2:
// [IMP]: Trie based
class Node {
public:
  vector<Node *> children;
  bool isLeaf;
  Node() {
    this->children.resize(2, NULL);
    this->isLeaf = false;
  }
  bool containsKey(int key) { return this->children[key] != NULL; }
  void putKey(int key, Node *n) { this->children[key] = n; }
  Node *getChild(int key) { return this->children[key]; }
  void markEnd() { this->isLeaf = true; }
  void unMarkEnd() { this->isLeaf = false; }
};
class Trie {
public:
  Node *root;
  Trie() { this->root = new Node(); }
  void insert(int number) {
    Node *temp = root;
    for (int i = 31; i >= 0; i--) {
      if (number & (1 << i)) {
        // i-th bit is set
        if (!temp->containsKey(1)) {
          temp->putKey(1, new Node());
        }
        temp = temp->getChild(1);
      } else {
        // i-th bit is not set
        if (!temp->containsKey(0)) {
          temp->putKey(0, new Node());
        }
        temp = temp->getChild(0);
      }
    }
  }
  int searchMaximumXOR(int number) {
    Node *temp = root;
    int result = 0;
    for (int i = 31; i >= 0; i--) {
      if (number & (1 << i)) {
        // i-th bit is set
        // try to take 0
        if (temp->containsKey(0)) {
          result = result | (1 << i);
          temp = temp->getChild(0);
        } else {
          temp = temp->getChild(1);
        }
      } else {
        // i-th bit is not set
        if (temp->containsKey(1)) {
          result = result | (1 << i);
          temp = temp->getChild(1);
        } else {
          temp = temp->getChild(0);
        }
      }
    }
    return result;
  }
};
class Solution {
public:
  int findMaximumXOR(vector<int> &nums) {
    int n = nums.size();
    Trie *trie = new Trie();
    // we need to store from msb to lsb
    // this is because number gets maximized with the
    // maximization of msb -> try to bring xor == 1 at the
    // msb first if possible followed by lsb
    for (int i = 0; i < n; i++) {
      int num = nums[i];
      trie->insert(num);
    }
    // now search within the trie
    int max_xor = 0;
    for (int i = 0; i < n; i++) {
      int num = nums[i];
      int result = trie->searchMaximumXOR(num);
      max_xor = max(max_xor, result);
    }
    return max_xor;
  }
};