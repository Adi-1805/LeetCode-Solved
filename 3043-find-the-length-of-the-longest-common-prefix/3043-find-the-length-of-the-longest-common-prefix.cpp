class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;  // all prefixes from arr1

        // all possible prefixes from arr1
        for (int val : arr1) {
            while (!st.count(val) && val > 0) {
                st.insert(val);
                val /= 10; // next shorter prefix by removing the last digit
            }
        }

        int ans = 0;

        // check in arr2 for the longest matching prefix
        for (int val : arr2) {
            while (!st.count(val) && val > 0) {
                val /= 10;
            }
            if (val > 0) {
                // log10 to determine the no of digits
                ans = max(ans, static_cast<int>(log10(val) + 1));
            }
        }
        return ans;
    }
};