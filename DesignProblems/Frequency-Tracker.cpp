// Leetcode 2671

class FrequencyTracker {
public:
    unordered_map<int, int> hash;
    unordered_map<int, unordered_set<int>> freq;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        if(hash.find(number)!=hash.end()){
            // number already exists
            int oldFreq = hash[number];
            hash[number]++;
            freq[oldFreq].erase(number);
            freq[oldFreq+1].insert(number);
        }else{
            // does not exists
            hash[number]++;
            freq[1].insert(number);
        }
    }
    
    void deleteOne(int number) {
        if(hash.find(number)!=hash.end()){
            // number exists
            int oldFreq = hash[number];
            freq[oldFreq].erase(number);
            if(freq[oldFreq].size()==0) freq.erase(oldFreq);
            hash[number]--;
            if(hash[number] == 0){
                hash.erase(number);
            }else{
                freq[oldFreq-1].insert(number);
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        if(freq.find(frequency)!=freq.end()){
            return freq[frequency].size() > 0;
        }
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */