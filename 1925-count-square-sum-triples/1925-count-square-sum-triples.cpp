class Solution {
    bool check_perfect_square(double num){
        return ceil(num) == floor(num);
    }
public:
    int countTriples(int n) {
        int count = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                double hypotenuse = sqrt(i*i + j*j);
                // cout << i << " " << j  << " " << hypotenuse << endl;
                if(hypotenuse <= n and check_perfect_square(hypotenuse)) count++;
            }
        }
        return count;
    }
};