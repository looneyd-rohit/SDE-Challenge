// Leetcode 1472

class BrowserHistory {
public:
    list<string> dll;
    list<string>::iterator it;
    BrowserHistory(string homepage) {
        dll.push_back(homepage);
        it = begin(dll);
    }
    
    void visit(string url) {
        // erase the part from the next of current pointer
        auto t = it;
        it++;
        dll.erase(it, end(dll));
        dll.push_back(url);
        t++;
        it = t;
    }
    
    string back(int steps) {
        while(it!=begin(dll) && steps--){
            it--;
        }
        return *it;
    }
    
    string forward(int steps) {
        while(++it!=end(dll) && steps--);
        it--;
        return *it;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */