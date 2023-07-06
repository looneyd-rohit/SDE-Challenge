// https://practice.geeksforgeeks.org/problems/sort-a-stack/1

void insertAtCorrectLocation(stack<int>& st, int e){
    // base case
    if(st.empty()){
        st.push(e);
        return;
    }
    
    int t = st.top(); st.pop();
    if(t > e){
        insertAtCorrectLocation(st, e);
        st.push(t);
    }else{
        st.push(t);
        st.push(e);
    }
}

void SortedStack :: sort()
{
    // base case
    if(this->s.empty()) return;
    
    int top = this->s.top(); this->s.pop();
    sort();
    // insert the previous top at the correct location
    insertAtCorrectLocation(this->s, top);
}