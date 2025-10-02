class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int filledBottles = numBottles, emptyBottles = 0, filledAfterExchange = 0, totalDrinks = 0;
        while(filledBottles != 0){
            totalDrinks += filledBottles;
            emptyBottles = (emptyBottles + filledBottles);
            filledBottles = 0;
            
            while(numExchange <= emptyBottles) {
                emptyBottles = (emptyBottles - numExchange);
                filledBottles += 1; 
                numExchange++;
            }
        }
        
        return totalDrinks;
    }
};