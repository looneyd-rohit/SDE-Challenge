// Leetcode 1845

// Approach 1: Using Set
class SeatManager {
public:
    set<int> st;
    SeatManager(int n) {
        for(int i=1; i<=n; i++) st.insert(i);
    }
    
    int reserve() {
        int begin = *st.begin();
        st.erase(begin);
        return begin;
    }
    
    void unreserve(int seatNumber) {
        st.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */


// Approach 2: Using a single variable + sets
class SeatManager {
public:
    int smallestSeat;    // contains the smallestSeat number that will be reserved next
    set<int> st;    // set will only contain those seats that were reserved in the past
    // and now are unreserved
    SeatManager(int n) {
        smallestSeat = 1;
    }
    
    int reserve() {
        if(!st.empty()){
            // contains unreserved seat
            int s = *st.begin();
            st.erase(s);
            return s;
        }
        return smallestSeat++;
    }
    
    void unreserve(int seatNumber) {
        st.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
