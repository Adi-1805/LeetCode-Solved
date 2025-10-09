#define ll long long int
class Solution {
public:
    ll minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        if (n == 0 || m == 0)
            return 0;
        ll total_skill = 0;
        for (int s : skill){
            total_skill += s;
        }
        ll time = total_skill * mana[m - 1];
        for (int j = 0; j < m - 1; j++){
            ll pre = 0, mx = 0;
            for (int s : skill){
                ll need = (pre + s) * (ll)mana[j] - pre * (ll)mana[j + 1];
                if (need > mx) mx = need;
                    pre += s;
            }
            time += mx;
        }
        return time;
    }
};