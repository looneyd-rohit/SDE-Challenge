// Leetcode 341
// [IMP]: Nice Problem

// Approach 1: Stack Based
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    stack<NestedInteger> st;
    NestedIterator(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        for(int i=n-1; i>=0; i--){
            st.push(nestedList[i]);
        }
    }
    
    int next() {
        int val = st.top().getInteger();
        st.pop();
        return val;
    }
    
    bool hasNext() {
        while(!st.empty()){
            NestedInteger obj1 = st.top();
            if(obj1.isInteger()) return true;
            // if not a integer then it is a list, hence open the list
            vector<NestedInteger> l = obj1.getList();
            // now pop the accumulated list
            st.pop();
            for(int i=l.size()-1; i>=0; i--){
                st.push(l[i]);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

// Approach 2: Stack Based (using pointers)
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    stack<NestedInteger*> st;
    NestedIterator(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        for(int i=n-1; i>=0; i--){
            st.push(&nestedList[i]);
        }
    }
    
    int next() {
        int val = st.top()->getInteger();
        st.pop();
        return val;
    }
    
    bool hasNext() {
        while(!st.empty()){
            NestedInteger* obj1 = st.top();
            if(obj1->isInteger()) return true;
            // if not a integer then it is a list, hence open the list
            vector<NestedInteger> &l = obj1->getList();
            // now pop the accumulated list
            st.pop();
            for(int i=l.size()-1; i>=0; i--){
                st.push(&l[i]);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

// Approach 3: Queue Based, O(1) next() call
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    queue<int> q;
    NestedIterator(vector<NestedInteger> &nestedList) {
        // flatten the input nestedlist on input
        flatten(nestedList);
    }

    void flatten(vector<NestedInteger> &nestedList){
        int n = nestedList.size();
        for(int i=0; i<n; i++){
            NestedInteger &obj = nestedList[i];
            if(obj.isInteger()){
                q.push(obj.getInteger());
            }else{
                flatten(obj.getList());
            }
        }
    }
    
    int next() {
        int val = q.front(); q.pop();
        return val;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */