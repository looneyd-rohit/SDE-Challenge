// Leetcode 1116

class ZeroEvenOdd {
private:
    int n;
    mutex m;
    condition_variable cv;
    int turn;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->turn = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i=1; i<=n; i++){
            unique_lock<mutex> lock(m);
            while(turn!=0) cv.wait(lock);
            printNumber(0);
            if((i % 2) == 0){
                turn = 2;
            }else{
                turn = 1;
            }
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i=2; i<=n; i+=2){
            unique_lock<mutex> lock(m);
            while(turn!=2) cv.wait(lock);
            printNumber(i);
            turn = 0;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i=1; i<=n; i+=2){
            unique_lock<mutex> lock(m);
            while(turn!=1) cv.wait(lock);
            printNumber(i);
            turn = 0;
            cv.notify_all();
        }
    }
};