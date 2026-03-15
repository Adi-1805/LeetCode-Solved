class Fancy {
    static constexpr int mod = 1000000007;
    vector<long long> arr;
    vector<long long> mul;
    vector<long long> add;
public:
    Fancy() {
        mul.push_back(1); add.push_back(0);
    }

    int quickmul(int x, int y) {
        int ret = 1;
        int cur = x;
        while (y) {
            if (y & 1) {
                ret = (long long)ret * cur % mod;
            }
            cur = (long long)cur * cur % mod;
            y >>= 1;
        }
        return ret;
    }

    int inv(int x) { return quickmul(x, mod - 2); }
    
    void append(int val) {
        arr.push_back(val);
        mul.push_back(mul.back());
        add.push_back(add.back());
    }
    
    void addAll(int inc) {
        add.back() = (add.back() + inc) % mod;
    }
    
    void multAll(int m) {
        mul.back() = (long long)mul.back()*m % mod;
        add.back() = (long long)add.back()*m % mod;
    }
    
    int getIndex(int idx) {
        if(idx >= arr.size()) return -1;
        int ao = (long long)inv(mul[idx]) * mul.back() % mod;
        int bo = (add.back() - (long long)add[idx] * ao % mod + mod) % mod;
        int ans = ((long long)ao * arr[idx] % mod + bo) % mod;
        return ans;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */