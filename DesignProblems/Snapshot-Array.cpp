// Leetcode 1146

class SnapshotArray {
public:
    int snapId;
    unordered_map<int, map<int, int>> store;
    SnapshotArray(int length) {
        this->snapId = 0;
    }
    
    void set(int index, int val) {
        store[index][snapId] = val;
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        auto it = store[index].upper_bound(snap_id);
        if(it == store[index].begin()) return 0;
        return (--it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */