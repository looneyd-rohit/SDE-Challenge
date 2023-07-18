// Leetcode 146
// [IMP]: Design Problem, intution is to be preserved

// Approach 1: Brute Force --> O(n) put and O(n) get
class LRUCache {
public:
    // since it is easier to push back on vector, we keep our most recently items on back
    // and least recently items on front while using vector
    vector<pair<int, int>> cache;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        // check if already, exists, if yes --> erase it from its position and put it to back
        for(int i=0; i<cache.size(); i++){
            if(cache[i].first == key){
                // found
                int value = cache[i].second;
                cache.erase(begin(cache)+i, begin(cache)+i+1);
                cache.push_back({key, value});
                return value;
            }
        }
        // if does not exist return -1;
        return -1;
    }
    
    void put(int key, int value) {
        // check if already exists, if yes --> erase old value, put new value in back
        for(int i=0; i<cache.size(); i++){
            if(cache[i].first == key){
                // found
                int oldValue = cache[i].second;
                cache.erase(begin(cache)+i, begin(cache)+i+1);
                cache.push_back({key, value});
                return;
            }
        }
        
        // if does not exist, push back and if size exceeds pop_front()
        cache.push_back({key, value});
        if(cache.size() > capacity){
            // size exceeds
            cache.erase(begin(cache));
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Approach 2: Optimal --> O(1) put, O(1) get
// using dll + hashmap to store addresses
class LRUCache {
public:
    // in doubly linked list it is easier to push front so we keep most recently used elements in front
    // and least recently used elements in the back
    list<int> dll;
    unordered_map<int, pair<list<int>::iterator, int>> hash;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        // check if it exists in hash, if yes then place it in front of dll
        if(hash.find(key)!=hash.end()){
            // found
            int value = hash[key].second;
            auto it = hash[key].first;    // address
            // erase from doubly linked list
            dll.erase(it);
            // push to front
            dll.push_front(key);
            // update in hashmap the new address
            hash[key].first = dll.begin();
            // return the value
            return value;
        }
        
        // if it does not exist, then return -1
        return -1;
    }
    
    void put(int key, int value) {
        // check for existence, if yes, then update its position
        if(hash.find(key)!=hash.end()){
            // found
            int oldValue = hash[key].second;
            auto it = hash[key].first;    // address
            // erase from doubly linked list
            dll.erase(it);
            // push to front
            dll.push_front(key);
            // update in hashmap the new address
            hash[key] = {dll.begin(), value};
            
            return;
        }
        
        // if it does not exist, push to front and if size exceeds pop from back
        dll.push_front(key);
        hash[key] = {dll.begin(), value};
        if(dll.size() > capacity){
            auto it = hash[dll.back()].first;
            hash.erase(dll.back());
            dll.erase(it);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */