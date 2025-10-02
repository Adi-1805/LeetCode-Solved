class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalDrinks = numBottles;
        // The answer is clearly: (initial number of bottles) + (how many can be exchanged given the increment in NumExchange)
        while(numBottles >= numExchange){
            int netDecreaseInBottlesAfterExchange = numExchange - 1;
            numBottles -= (netDecreaseInBottlesAfterExchange); numExchange++; totalDrinks++;
        }
        return totalDrinks;
    }
};
