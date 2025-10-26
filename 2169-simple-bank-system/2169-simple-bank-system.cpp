#define ll long long
class Bank {
    vector<ll> bal;
    int n;
    bool validAccNo(int account){
        return account > 0 and account <= n;
    }
public:
    Bank(vector<long long>& balance) {
        n = balance.size();
        bal.push_back(0);
        for(ll value: balance){
            bal.push_back(value);
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(!validAccNo(account1) || !validAccNo(account2) || money > bal[account1]){
            return false;
        }
        bal[account1] -= money;
        bal[account2] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(!validAccNo(account)) return false;
        bal[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!validAccNo(account) || bal[account] < money){
            return false;
        }
        bal[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */