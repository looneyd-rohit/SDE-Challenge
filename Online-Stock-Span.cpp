// Leetcode 901

class StockSpanner {
public:
    // similar to prev greater element --> but online (so, need to maintain indices)
    int index;
    stack<pair<int, int>> st;
    StockSpanner() {
        index = 0;
        st.push({-1, 0});
    }
    
    int next(int price) {
        index++;
        while(this->st.top().first!=-1 && this->st.top().first <= price){
            this->st.pop();
        }
        int ans = index - st.top().second;
        st.push({price, index});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */