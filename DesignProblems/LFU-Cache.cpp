// Leetcode 460

class LFUCache {
public:
    // we have to store frequency as well as maintain lru style for same frequency elements
    map<int, list<pair<int, int>>> freq;    // stores <freq, list of <key, value> dll>
    unordered_map<int, pair<list<pair<int, int>>::iterator, int>> hash;    // stores <key, pair<key address, key freq>>
    int capacity;
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(hash.find(key)!=hash.end()){
            // found
            auto it = hash[key].first;
            int f = hash[key].second;
            int value = hash[key].first->second;
            // since element is accessed, freq increases and also its position in
            // dll will move forward (to the begin)
            int new_f = f+1;
            // erase old value
            freq[f].erase(it);
            // check if current freq dll becomes empty
            if(freq[f].empty()) freq.erase(f);
            // put the key with new_f to new list
            freq[new_f].push_front({key, value});
            // update the new address in hash
            hash[key] = {freq[new_f].begin(), new_f};
            
            return value;
        }else{
            // not found
            return -1;
        }
    }
    
    void put(int key, int value) {
        // check if already exists
        if(hash.find(key)!=hash.end()){
            // found
            auto it = hash[key].first;
            int f = hash[key].second;
            int oldValue = hash[key].first->second;
            // since element is accessed, freq increases and also its position in
            // dll will move forward (to the begin)
            int new_f = f+1;
            // erase the old value
            freq[f].erase(it);
            // check if current freq dll becomes empty
            if(freq[f].empty()) freq.erase(f);
            
            // put the key with new_f to new list, with new value provided
            freq[new_f].push_front({key, value});
            // update the new address in hash
            hash[key] = {freq[new_f].begin(), new_f};
            
            return;
        }
        // if not already exists
        else{
            if(hash.size() + 1 <= capacity){
                // nothing needs to be deleted
                int f = 1;
                freq[f].push_front({key, value});
                hash[key] = {freq[f].begin(), f};
            }else{
                // element needs to be deleted
                auto it = freq.begin();
                // now delete the least recently used item here
                int f = it->first;
                int keyToBeRemoved = it->second.back().first;
                // remove from freq
                it->second.pop_back();
                if(it->second.empty()) freq.erase(f);
                // remove from hash
                hash.erase(keyToBeRemoved);
                // insert new element
                freq[1].push_front({key, value});
                hash[key] = {freq[1].begin(), 1};
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */