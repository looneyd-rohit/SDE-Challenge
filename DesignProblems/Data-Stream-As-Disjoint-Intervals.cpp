// Leetcode 352

// Approach 1: using ordered set
class SummaryRanges {
public:
    set<int> st;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        if(st.empty()) return ans;
        int start = *st.begin(), end = *st.begin();
        for(auto it = st.begin(); it!=st.end(); it++){
            if(end == *it){
                end = *it;
            }else{
                if(end + 1 == *it){
                    end = *it;
                }else{
                    ans.push_back({start, end});
                    start = *it, end = *it;
                }
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

// Approach 2: using ordered map

class SummaryRanges {
public:
    map<int, int> ranges;    // storing range as <left end, right end> in a map
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        // find out the just greater left end and just smaller right end to add numbers
        int l = value, r = value;
        auto just_greater = ranges.upper_bound(value);
        // for left end
        if(just_greater != ranges.begin()){
            // just_smaller exists
            auto just_smaller = just_greater;
            just_smaller--;
            
            if(just_smaller->second >= value) return;
            
            if(just_smaller->second + 1 == value) l = just_smaller->first;  // merging possible
        }
        
        if(just_greater != ranges.end()){
            if(just_greater->first - 1 == value){
                r = just_greater->second;
                ranges.erase(just_greater->first);
            }
        }
        
        ranges[l] = r;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(auto& e: ranges){
            ans.push_back({e.first, e.second});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */