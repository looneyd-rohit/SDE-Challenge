// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> st;
    int t = k;
    while(t--){
        st.push(q.front()); q.pop();
    }
    while(!st.empty()){
        q.push(st.top()); st.pop();
    }
    t = q.size() - k;
    while(t--){
        q.push(q.front()); q.pop();
    }
    return q;
}