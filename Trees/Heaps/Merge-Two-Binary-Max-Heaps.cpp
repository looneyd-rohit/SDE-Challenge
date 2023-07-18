// https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// Approach 1: using heapify
class Solution{
    public:
    void heapify(vector<int>& arr, int index){
        // max heap logic
        int current = index;
        int leftChild = 2*current + 1;
        int rightChild = 2*current + 2;
        
        if(leftChild < arr.size() && arr[current] < arr[leftChild]){
            current = leftChild;
        }
        if(rightChild < arr.size() && arr[current] < arr[rightChild]){
            current = rightChild;
        }
        if(current != index){
            swap(arr[index], arr[current]);
            // recursively propagate
            heapify(arr, current);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;
        for(auto& e: a) ans.push_back(e);
        for(auto& e: b) ans.push_back(e);
        // call heapify
        int len = ans.size();
        for(int i=len/2-1; i>=0; i--){
            heapify(ans, i);
        }
        return ans;
    }
};

// Approach 2: using insert operation of heap
class Solution{
    public:
    void insert(vector<int>& arr, int e){
        arr.push_back(e);
        int index = arr.size() - 1;
        // root will not have any parent so don't take the root node
        while(index > 0){
            int parent = (index - 1) / 2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }else{
                break;
            }
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;
        for(auto& e: a) insert(ans, e);
        for(auto& e: b) insert(ans, e);
        return ans;
    }
};