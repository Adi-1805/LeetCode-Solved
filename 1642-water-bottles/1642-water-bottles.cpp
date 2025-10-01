class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int bottles = numBottles;
        int filledBottles = numBottles, emptyBottles = 0, filledAfterExchange = 0, totalDrinks = 0;
        while(filledBottles != 0){
            totalDrinks += filledBottles;
            emptyBottles = (emptyBottles + filledBottles);
            filledAfterExchange = emptyBottles/numExchange;
            emptyBottles = (emptyBottles - filledAfterExchange*numExchange);
            filledBottles = filledAfterExchange;
        }
        return totalDrinks;
    }
};