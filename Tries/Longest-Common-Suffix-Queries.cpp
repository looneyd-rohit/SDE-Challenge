// Leetcode 3093

// Approach: modified trie based approach
class Node{
public:
    int index;
    // vector<Node*> children;
    Node* children[26];
    Node(){
        this->index = -1;
        // this->children.resize(26, NULL);
        for(int i=0; i<26; i++) this->children[i] = NULL;
    }
    Node* getChild(char ch){
        return this->children[ch-'a'];
    }
    void putChild(char ch, Node* node){
        this->children[ch-'a'] = node;
    }
    bool containsChild(char ch){
        return this->children[ch-'a']!=NULL;
    }
};
class Solution {
public:
    void insert(Node* root, int ind, vector<string>& wordsContainer){
        string &str = wordsContainer[ind];
        Node* temp = root;
        for(int i=0; i<str.length(); i++){
            if(!temp->containsChild(str[i])){
                temp->putChild(str[i], new Node());
            }
            temp = temp->getChild(str[i]);
            // store the index
            
            if(temp->index==-1) temp->index = ind;
            else{
                if(wordsContainer[temp->index].length() > wordsContainer[ind].length()){
                    temp->index = ind;
                }
            }
        }
    }
    int search(Node* root, string& word){
        Node* temp = root;
        for(int i=0; i<word.length(); i++){
            if(!temp->containsChild(word[i])){
                return temp->index;
            }
            temp = temp->getChild(word[i]);
        }
        return temp->index;
    }
vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n = wordsContainer.size(), q = wordsQuery.size();
        Node* root = new Node();
        int mini = -1, mini_len = 1e9;
        for(int i=0; i<n; i++){
            if(wordsContainer[i].length() < mini_len){
                mini_len = wordsContainer[i].length();
                mini = i;
            }
            reverse(begin(wordsContainer[i]), end(wordsContainer[i]));
            insert(root, i, wordsContainer);
        }
        root->index = mini;
        vector<int> ans;
        for(int i=0; i<q; i++){
            reverse(begin(wordsQuery[i]), end(wordsQuery[i]));
            int ind = search(root, wordsQuery[i]);
            ans.push_back(ind);
        }
        return ans;
    }
};