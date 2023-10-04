// Leetcode 705

class MyHashSet {
private:
    vector<list<int>> hash;
public:
    MyHashSet() {
        hash.resize(1e4);
    }
    
    void add(int key) {
        int ind = key % (int)1e4;
        if(contains(key)) return;
        hash[ind].push_back(key);
    }
    
    void remove(int key) {
        int ind = key % (int)1e4;
        for(auto it=begin(hash[ind]); it!=end(hash[ind]); it++){
            if(*it == key){
                hash[ind].erase(it);
                return ;
            }
        }
    }
    
    bool contains(int key) {
        int ind = key % (int)1e4;
        for(auto it=begin(hash[ind]); it!=end(hash[ind]); it++){
            if(*it == key){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */