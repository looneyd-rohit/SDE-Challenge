// Leetcode 380

class RandomizedSet {
public:
    vector<int> store;
    unordered_map<int, int> hash;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(hash.find(val)!=hash.end()) return false;
        store.push_back(val);
        hash[val] = store.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(hash.find(val)==hash.end()) return false;
        // present
        // remove by swapping with the last index
        int ind = hash[val];
        int lastInd = store.size()-1;
        if(ind == lastInd){
            // edge case
            hash.erase(val);
            store.pop_back();
        }else{
            int lastIndVal = store.back();
            // swap
            swap(store[ind], store[lastInd]);
            // erase from hashmap
            hash.erase(val);
            // update in hashmap
            hash[lastIndVal] = ind;
            // erase from store
            store.pop_back();
        }
        return true;
    }
    
    int getRandom() {
        return store[rand() % store.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */