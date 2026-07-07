#include "lib.h"

class FizzBuzz {
private:
    int n;
    int count = 1;
    bool end;

    sem_t fizzs;
    sem_t buzzs;
    sem_t fizzbuzzs;
    sem_t numbers;

public:
    FizzBuzz(int n) {
        this->n = n;
        end = false;

        sem_init(&fizzs, 0, 0);
        sem_init(&buzzs, 0, 0);
        sem_init(&fizzbuzzs, 0, 0);
        sem_init(&numbers, 0, 1);
    }

    // printFizz() outputs "fizz".
    void fizz(std::function<void()> printFizz) {
        while(1){
            sem_wait(&fizzs);
            if(end) break;
            if(count % 3 == 0){
                printFizz(); sem_post(&numbers);
            }else{
                sem_post(&buzzs);
            }
        }
        sem_post(&buzzs);
    }

    // printBuzz() outputs "buzz".
    void buzz(std::function<void()> printBuzz) {
        while(1){
            sem_wait(&buzzs);
            if(end) break;
            if(count % 5 == 0){
                printBuzz(); sem_post(&numbers);
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(std::function<void()> printFizzBuzz) {
        while(1){
            sem_wait(&fizzbuzzs);
            if(end) break;
            if(count % 3 == 0 && count % 5 == 0){
                printFizzBuzz(); sem_post(&numbers);
            }else{
                sem_post(&fizzs);
            }
        }
        sem_post(&fizzs);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(std::function<void(int)> printNumber) {
        auto it = 1;
        while(1){
            sem_wait(&numbers);
            if(it == (n+1)) break;
            if(it% 3 != 0 && it % 5 != 0){
                printNumber(it);
                sem_post(&numbers);
            }else{
                count = it;
                sem_post(&fizzbuzzs);
            }
            it++;
        }
        end = true;
        sem_post(&fizzbuzzs);
    }
};