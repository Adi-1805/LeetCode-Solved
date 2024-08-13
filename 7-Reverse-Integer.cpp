class Solution {
public:
    int reverse(int x) {
        if(x<0){
            string str = to_string(abs(x));
            std::reverse(str.begin(),str.end());
            str = "-"+ str;
            stringstream ss;
            ss << str;
            int z = 0;
            ss >> z;
            if( z<INT_MAX && z>INT_MIN) return z; 
            return 0;
        }
        string str = to_string(x);
        std::reverse(str.begin(),str.end());
        stringstream ss;
        ss << str;
        int z = 0;
        ss >> z;
        if( z<INT_MAX && z>INT_MIN) return z; 
        return 0;
    }
};