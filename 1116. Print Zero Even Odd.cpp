#include "lib.h"

class ZeroEvenOdd {
private:
    int n;
    int curr = 1;
    std::atomic<bool> done{false};
    sem_t zeros;
    sem_t evens;
    sem_t odds;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        done = false;
        sem_init(&zeros, 0, 1);
        sem_init(&evens,0,0);
        sem_init(&odds,0,0);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(std::function<void(int)> printNumber) {
        int it = 1;
        while(1){
            sem_wait(&zeros);
            
            if(it == (n+1)) break;
            printNumber(0);
            
            curr = it;
            if(it & 1) sem_post(&odds);
            else sem_post(&evens);
            ++it;
        }
        done = true;
        sem_post(&odds);
        sem_post(&evens);
    }

    void even(std::function<void(int)> printNumber) {
        while(true){
            sem_wait(&evens);
            if(done) break;
            printNumber(curr);
            sem_post(&zeros);
        }
    }

    void odd(std::function<void(int)> printNumber) {
        while(true){
            sem_wait(&odds);
            if(done) break;
            printNumber(curr);
            sem_post(&zeros);
        }
    }
};