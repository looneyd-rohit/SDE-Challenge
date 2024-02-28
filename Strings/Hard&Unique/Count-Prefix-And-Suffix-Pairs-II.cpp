// Leetcode 3045
// Approach 1: O(N*L*( O(1) + O(Log(N)))) --> TLE!!!
class Solution {
public:
  const int M = 1e9 + 7;
  const int p = 23; // p --> hashing constant (arbitrary)
  long long hashWordIndex(string &word, int ind, int power) {
    return (power * 1LL * (word[ind] - 'a')) % M;
  }
  bool isPrefixAndSuffixSame(string &word, int l, vector<long long> &prefSum,
                             vector<long long> &powers) {
    int wordLen = word.size();
    int fwd =
        (l != wordLen) ? (prefSum[l] * powers[wordLen - l]) % M : prefSum[l];
    int bwd = (((prefSum[wordLen] - prefSum[wordLen - l]) % M) + M) % M;
    if (fwd == bwd)
      return true;
    return false;
  }
  int countMatchings(int sum, int l, map<int, multiset<int>> &mp) {
    return mp[l].count(sum);
  }
  long long countPrefixSuffixPairs(vector<string> &words) {
    int n = words.size();
    vector<long long> powers(1e5 + 1, 1);
    for (int i = 1; i <= 1e5; i++)
      powers[i] = (powers[i - 1] * p) % M;
    // since it is given that `the sum of the lengths of
    // all words[i] does not exceed 5 * 105`
    // hence, we cannot use two for loops of n*n but can
    // do two loops of n*l
    map<int, multiset<int>> mp;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      string word = words[i];
      int wordLen = word.size();
      // compute the hash of the word and store in prefix sums
      vector<long long> prefSum(wordLen + 1, 0);
      for (int t = 1; t <= word.size(); t++) {
        prefSum[t] +=
            (prefSum[t - 1] + hashWordIndex(word, t - 1, powers[t])) % M;
      }
      for (int len = 1; len <= wordLen; len++) {
        // check if prefix and suffix are same for
        // a word of particular length
        if (!isPrefixAndSuffixSame(word, len, prefSum, powers))
          continue;

        // if prefix and suffix are same then take it
        ans += countMatchings(prefSum[len], len, mp);
      }
      mp[wordLen].insert(prefSum.back());
    }
    return ans;
  }
};

// Approach 2: O(N*L*( O(1) + O(1))) --> ACCEPTED
class Node {
public:
  long long count;
  vector<Node*> children;
  bool isEnd;
  Node() {
    this->count = 0;
    this->children.resize(26, NULL);
    this->isEnd = false;
  }
  bool containsKey(char ch) { return this->children[ch - 'a'] != NULL; }
  void insertChild(char ch, Node *node) { this->children[ch - 'a'] = node; }
  Node *getChild(char ch) { return this->children[ch - 'a']; }
  void markEnd() { this->isEnd = true; this->count++; }
};
Node* findOrInsert(Node* root, char ch) {
    Node *node = root;
    if (!node->containsKey(ch)) {
        // not present
        // insert
        node->insertChild(ch, new Node());
    }
    node = node->getChild(ch);
    return node;
}

class Solution {
public:
    const int M = 1e9+7;
    const int p = 23; // p --> hashing constant (arbitrary)
    long long hashWordIndex(string& word, int ind, int power){
        return (power * 1LL * (word[ind]-'a')) % M;
    }
    bool isPrefixAndSuffixSame(string& word, int l, vector<long long>& prefSum, vector<long long>& powers){
        int wordLen = word.size();
        int fwd = (l != wordLen) ? (prefSum[l] * powers[wordLen-l]) % M : prefSum[l];
        int bwd = (((prefSum[wordLen] - prefSum[wordLen-l]) % M) + M) % M;
        if(fwd == bwd) return true;
        return false;
    }
    int countMatchings(int sum, int l, map<int, multiset<int>>& mp){
        return mp[l].count(sum);
    }
    long long countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        Node* root = new Node();
        vector<long long> powers(1e5+1, 1);
        for(int i=1; i<=1e5; i++) powers[i] = (powers[i-1] * p) % M;
        // since it is given that `the sum of the lengths of 
        // all words[i] does not exceed 5 * 105`
        // hence, we cannot use two for loops of n*n but can
        // do two loops of n*l
        map<int, multiset<int>> mp;
        long long ans = 0;
        for(int i=0; i<n; i++){
            string word = words[i];
            int wordLen = word.size();
            // compute the hash of the word and store in prefix sums
            vector<long long> prefSum(wordLen+1, 0);
            for(int t=1; t<=word.size(); t++){
                prefSum[t] += (prefSum[t-1] + hashWordIndex(word, t-1, powers[t])) % M;
            }
            Node* temp = root;
            for(int len=1; len<=wordLen; len++){
                temp = findOrInsert(temp, word[len-1]);
                // check if prefix and suffix are same for
                // a word of particular length
                if(!isPrefixAndSuffixSame(word, len, prefSum, powers)){
                    continue;
                }

                // if prefix and suffix are same then take it
                // cout<<word<<", len: "<<len<<", count: "<<temp->count<<endl;
                ans += temp->count;  // countMatchings(prefSum[len], len, mp);
            }
            temp->markEnd();
            mp[wordLen].insert(prefSum.back());
        }
        return ans;
    }
};