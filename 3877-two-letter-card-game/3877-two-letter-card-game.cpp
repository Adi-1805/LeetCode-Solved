class Solution {
public:
    int score(vector<string>& cards, char x) {

        int n = cards.size();
        unordered_map<string, int> mpp1;
        unordered_map<string, int> mpp2;
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        int max1 = -1, max2 = -1, ans = 0;

        for (string& s : cards) {
            if (s[0] == x && s[1] == x) {
                cnt3++;
            } else {
                if (s[0] == x) {
                    mpp1[s]++;
                    max1 = max(max1, mpp1[s]);
                    cnt1++;
                }
                if (s[1] == x) {
                    mpp2[s]++;
                    max2 = max(max2, mpp2[s]);
                    cnt2++;
                }
            }
        }

        if (max1 > cnt1 / 2) {
            ans += cnt1 - max1;
            cnt1 = 2 * max1 - cnt1;
        } else {
            ans += cnt1 / 2;
            cnt1 = cnt1 % 2 == 0 ? 0 : 1;
        }
        if (max2 > cnt2 / 2) {
            ans += cnt2 - max2;
            cnt2 = 2 * max2 - cnt2;
        } else {
            ans += cnt2 / 2;
            cnt2 = cnt2 % 2 == 0 ? 0 : 1;
        }

        if (cnt3 <= cnt1 + cnt2)
            return ans + cnt3;
        else {
            cnt3 -= cnt1 + cnt2;
            if (ans * 2 >= cnt3) {
                return ans + cnt1 + cnt2 + cnt3 / 2;
            } else {
                return ans * 2 + cnt1 + cnt2;
            }
        }

        return 0;
    }
};