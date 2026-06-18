class Solution {
public:
    double angleClock(int hour, int minutes) {
        // theta = ((30 * H) - (5.5 * M))
        double ans = abs(30.0*hour - 5.5*minutes);
        return (ans > 180) ? 360 - ans : ans;
    }
};