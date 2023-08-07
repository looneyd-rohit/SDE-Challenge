// Leetcode 1195

class FizzBuzz {
private:
    int n;
    int i;
    mutex m;
    condition_variable cv;
public:
    FizzBuzz(int n) {
        this->n = n;
        this->i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(i<=n and !((i%3 == 0) and (i%5 != 0))){
                cv.wait(lock);
            }
            if(i<=n){
                i++;
                printFizz();
            }
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(i<=n and !((i%3 != 0) and (i%5 == 0))){
                cv.wait(lock);
            }
            if(i<=n){
                i++;
                printBuzz();
            }
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(i<=n and !((i%3 == 0) and (i%5 == 0))){
                cv.wait(lock);
            }
            if(i<=n){
                i++;
                printFizzBuzz();
            }
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(i<=n and !((i%3 != 0) and (i%5 != 0))){
                cv.wait(lock);
            }
            if(i<=n){
                printNumber(i);
                i++;
            }
            cv.notify_all();
        }
    }
};