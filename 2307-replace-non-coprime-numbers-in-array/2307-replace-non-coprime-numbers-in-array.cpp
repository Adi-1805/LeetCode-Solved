#include <iostream>
#include <vector>
#include <numeric>

// Function to calculate the Greatest Common Divisor (GCD) using Euclidean algorithm
long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

class Solution {
public:
    std::vector<int> replaceNonCoprimes(std::vector<int>& nums) {
        std::vector<long long> result;

        for (int num : nums) {
            long long current_num = num;
            while (!result.empty()) {
                long long last_num = result.back();
                long long common_divisor = gcd(current_num, last_num);

                if (common_divisor > 1) {
                    // They are non-coprime, merge them
                    long long lcm_val = (last_num / common_divisor) * current_num;
                    result.pop_back();
                    current_num = lcm_val;
                } else {
                    // They are coprime, no more merging
                    break;
                }
            }
            result.push_back(current_num);
        }

        // Convert long long result back to int vector
        std::vector<int> final_result;
        for (long long val : result) {
            final_result.push_back(static_cast<int>(val));
        }

        return final_result;
    }
};
