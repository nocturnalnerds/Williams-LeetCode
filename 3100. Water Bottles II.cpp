#include "lib.h"

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int bottles = 0;
        while(numBottles >= numExchange){
            bottles += numExchange;
            numBottles -= numExchange;
            numExchange++;
            numBottles++;
        }
        bottles += numBottles;
        return bottles;
    }
};