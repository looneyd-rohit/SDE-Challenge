// Leetcode 3043

class Node{
public:
    vector<Node*> children;
    bool isEnd;
    Node(){
        this->children.resize(10, NULL);
        this->isEnd = false;
    }
    bool containsKey(char ch){
        return this->children[ch-'0']!=NULL;
    }
    void insertChild(char ch, Node* node){
        this->children[ch-'0'] = node;
    }
    Node* getChild(char ch){
        return this->children[ch-'0'];
    }
    void markEnd(){
        this->isEnd = true;
    }
};
class Trie{
public:
    Node* root;
    Trie(){this->root = new Node();};    
    void insert(string& word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                // not present
                // insert
                node->insertChild(word[i], new Node());
            }
            node = node->getChild(word[i]);
        }
        // mark as end
        node->markEnd();
    }
    int searchAndCount(string& word){
        int len = 0;
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                // not present
                return len;
            }
            node = node->getChild(word[i]);
            len++;
        }
        return len;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        // create the trie consisting of arr1 elements
        Trie trie;
        for(int i=0; i<n1; i++){
            string word = to_string(arr1[i]);
            trie.insert(word);
        }
        // check for longest length prefix
        int prefix = 0;
        for(int i=0; i<n2; i++){
            string word = to_string(arr2[i]);
            prefix = max(prefix, trie.searchAndCount(word));
        }
        return prefix;
    }
};