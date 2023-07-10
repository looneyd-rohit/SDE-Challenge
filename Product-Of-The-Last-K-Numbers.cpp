// Leetcode 1352

// Queue based approch:
class ProductOfNumbers {
public:
    vector<int> q;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num == 0){
            q.clear();
        }else{
            if(q.empty()) q.push_back(num);
            else q.push_back(q.back()*num);
        }
    }
    
    int getProduct(int k) {
        if(k > q.size()) return 0;
        else if(k == q.size()) return q.back();
        else return q.back() / q[q.size()-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */


// Queue + Set based approach:
class ProductOfNumbers {
public:
    vector<int> q;
    int prod, ind;
    set<int> st;
    ProductOfNumbers() {
        prod = 1;
        ind = 0;
    }
    
    void add(int num) {
        if(num == 0){
            prod = 1;
            st.insert(ind);
            q.push_back(0);
        }else {
            prod *= num;
            q.push_back(prod);
        }
        ind++;
        // for(auto& e: q) cout<<e<<" ";cout<<endl;
    }
    
    int getProduct(int k) {
        int frontNum = q.size() - k - 1;
        auto it = st.upper_bound(frontNum);
        if(frontNum < 0 && it == st.end()) return q.back();
        if(it == st.end()){
            // zero does not exists after that index frontNum
            if(q[frontNum]==0) return q.back();
            else{
                return q.back() / q[frontNum];
            }
        }else{
            // zero exists after that index frontNum
            return 0;
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */