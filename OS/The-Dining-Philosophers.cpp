// Leetcode 1226

class Semaphore {
private:
    mutex mtx;
    condition_variable cv;
    int count;
public:
    Semaphore (int count_ = 0): count(count_) {}

    void setCount(int c) {
        this->count = c;
    }
    
    inline void notify() {
        unique_lock<mutex> lock(mtx);
        count++;
        //notify the waiting thread
        if(count <= 0) cv.notify_one();
    }

    inline void wait() {
        unique_lock<mutex> lock(mtx);
        count--;
        while(count < 0) {
            //wait on the mutex until notify is called
            cv.wait(lock);
        }
    }
};
class DiningPhilosophers {
public:
    Semaphore forks[5];
    mutex m;
    DiningPhilosophers() {
        // making all of them mutexes(binary semaphore)
        for(int i=0; i<5; i++) forks[i].setCount(1);
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		
        // get access to both the forks first, then pick it
        {
            lock_guard<mutex> lock(m);
            forks[philosopher].wait();    // right fork
            forks[(philosopher+1)%5].wait();    // left fork
        }

        pickRightFork();
        pickLeftFork();

        eat();

        putRightFork();
        forks[philosopher].notify();
        putLeftFork();
        forks[(philosopher+1)%5].notify();
    }
};