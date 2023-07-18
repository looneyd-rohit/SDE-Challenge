// Leetcode 295

class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // always maintain minheap size > maxheap size --> a rule to be followed
        // if one of them is greater it should always be minheap (right side one)
        int maxi = maxheap.empty() ? INT_MIN : maxheap.top();
        int mini = minheap.empty() ? INT_MAX : minheap.top();
        // cout<<num<<endl;
        // cout<<maxheap.size()<<" : "<<minheap.size()<<endl;
        if(maxheap.size() == minheap.size()){
            if(maxi <= num && num <= mini){
                minheap.push(num);
            }else if(maxi >= num){
                maxheap.pop();
                minheap.push(maxi);
                maxheap.push(num);
            }else if(num >= mini){
                minheap.push(num);
            }
        }else if(maxheap.size() < minheap.size()){
            if(num <= mini){
                maxheap.push(num);
            }else if(num >= maxi){
                minheap.pop();
                maxheap.push(mini);
                minheap.push(num);
            }
        }else if(maxheap.size() > minheap.size()){
            if(num >= maxi){
                minheap.push(num);
            }else if(num <= mini){
                maxheap.pop();
                minheap.push(maxi);
                maxheap.push(num);
            }
        }
    }
    
    double findMedian() {
        if(minheap.size() == maxheap.size()){
            return (maxheap.top() + minheap.top()) / 2.0;
        }else{
            return minheap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */