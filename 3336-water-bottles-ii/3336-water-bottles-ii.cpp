class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalDrinks = numBottles;
        // The answer is clearly: (initial number of bottles) + (how many can be exchanged given the increment in NumExchange)
        while(numBottles >= numExchange){
            int netDecrementInBottlesAfterExchange = numExchange - 1;
            numBottles -= (netDecrementInBottlesAfterExchange); numExchange++; totalDrinks++;
        }
        return totalDrinks;
    }
};
