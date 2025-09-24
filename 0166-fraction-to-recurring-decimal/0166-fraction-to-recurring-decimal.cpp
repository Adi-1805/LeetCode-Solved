class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        if(numerator==INT_MIN && denominator==-1) return "2147483648";
        if(numerator==INT_MIN && denominator==1) return "-2147483648";

        bool isNeg = (numerator<0)^(denominator<0);
        long num = abs((long)numerator);
        long den = abs((long)denominator);
        long rem = num%den;
        long div = num/den;

        string result = "";
        if(isNeg) result += "-";
        result += to_string(num / den);

        if (rem == 0) return result; // if no remainder, we are done

        result += "."; // okay, decimal part incoming
        // this map remembers: remainder -> index in result string
        unordered_map<long, int> seen;
        while (rem != 0) {
            // if we’ve seen this remainder before, loop detected
            if (seen.count(rem)) {
                result.insert(seen[rem], "("); // put opening bracket
                result += ")"; // close it
                break;
            }
            // mark where this remainder’s digit will appear
            seen[rem] = result.size();
            rem *= 10; // mimic long division (bring down zero)
            result += to_string(rem / den);
            rem %= den;
        }
        return result;
    }
};