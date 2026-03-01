class Solution {
public:
    int minPartitions(string n) {
        int ind = max_element(n.begin(), n.end()) - n.begin();
        return (n[ind] - '0');
    }
};