// https://www.hackerrank.com/challenges/poisonous-plants/problem
// [IMP]: Very nice monotonic stack based question

int poisonousPlants(vector<int> p) {
    int n = p.size();
    if(n == 0) return 0;
    // the idea is to maintain a monotonic increasing sequence from the traversing
    // from the back of the array
    // a sequence like a < b < c < d < e --> will have less no of days
    // rather than a < b > c > d > e (provided a is smallest)
    stack<int> st;
    int maxDays = 0, maxStackSize = 0;
    for(int i=n-1; i>=0; i--){
        int curr_poison = p[i];
        while(!st.empty() && curr_poison < st.top()) st.pop();
        // size of decreases due to pop --> the size decrease/diff is the no of days
        // elapsed during the process
        maxDays = max(maxDays, (int)(maxStackSize - st.size()));
        st.push(curr_poison);
        maxStackSize = max(maxStackSize, (int)st.size());
    }
    return maxDays;
}