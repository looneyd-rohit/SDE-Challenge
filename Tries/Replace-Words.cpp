// Leetcode 648

// Approach 1: brute force -> works!!!
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        int n = sentence.length();
        unordered_set<string> ust;
        for(auto& word: dictionary){
            ust.insert(word);
        }
        string ans = "";
        string curr_word = "";
        for(int i=0; i<n; i++){
            curr_word.push_back(sentence[i]);
            if(ust.count(curr_word)){
                ans += curr_word;
                while(i < n && sentence[i]!=' ') i++;
                if(i < n){
                    ans += " ";
                }
                curr_word = "";
            }else if(sentence[i] == ' ' || i==n-1){
                if(i!=n-1) curr_word.pop_back();
                ans += curr_word;
                if(i < n-1){
                    ans += " ";
                }
                curr_word = "";
            }
        }
        return ans;
    }
};

// Approach 2: using tries
struct Node{
public:
    bool is_end;
    vector<Node*> children;
    Node(){
        this->is_end = false;
        this->children.resize(26, NULL);
    }
    void set_end(){
        this->is_end = true;
    }
    void unset_end(){
        this->is_end = false;
    }
    bool has_child(char ch){
        return this->children[ch-'a'] != NULL;
    }
    Node* get_child(char ch){
        return this->children[ch-'a'];
    }
    void set_child(char ch, Node* n){
        this->children[ch-'a'] = n;
    }
};
class Trie{
public:
    Node* node;
    Trie(){
        this->node = new Node();
    }
    string search_trie(string& word){
        Node* temp = node;
        string prefix = "";
        for(char &ch: word){
            if(!temp->has_child(ch)){
                return "";
            }
            temp = temp->get_child(ch);
            prefix.push_back(ch);
            if(temp->is_end) return prefix;
        }
        return prefix;
    }
    void insert_trie(string& word){
        Node* temp = node;
        for(char& ch: word){
            if(!temp->has_child(ch)){
                temp->set_child(ch, new Node());
            }
            temp = temp->get_child(ch);
        }
        temp->set_end();
    }
};
class Solution {
public:
    static bool compare(string& a, string& b){
        if(a.length() == b.length()) return a < b;
        return a.length() < b.length();
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        int n = sentence.length();
        Trie* trie = new Trie();
        for(auto& word: dictionary){
            trie->insert_trie(word);
        }
        string ans = "";
        for(int i=0; i<n; i++){
            int j=i;
            for(; j<n && sentence[j]!=' '; j++);
            string word = sentence.substr(i, j-i);
            string pref = trie->search_trie(word);
            ans += pref.length() > 0 ? pref : word;
            if(j < n) ans += " ";
            i = j;
        }
        return ans;
    }
};