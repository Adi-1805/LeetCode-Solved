class Solution {
    vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token; stringstream ss(s);
        while(getline(ss, token, delimiter)){
            tokens.push_back(token);
        } 
        return tokens;
    }
public:
    int compareVersion(string version1, string version2) {
        // Splitting the string
        vector<string> v1 = split(version1, '.');
        vector<string> v2 = split(version2, '.');
        int sz1 = v1.size(), sz2 = v2.size();

        // padding the shorter version for easy comparison
        if(sz1 > sz2) for(int i = 0; i < abs(sz2-sz1); i++) v2.push_back("0");
        else for(int i = 0; i < abs(sz2-sz1); i++) v1.push_back("0");
        
        for(string val: v1) cout << val << " "; cout << endl;
        for(string val: v2) cout << val << " "; cout << endl;

        for(int i = 0; i < v1.size(); i++){
            // converting string to integer and then comparing
            stringstream ss1(v1[i]), ss2(v2[i]); int num1 = 0, num2 = 0; ss1 >> num1; ss2 >> num2;
            if(num1 > num2) return 1;
            else if(num2 > num1) return -1;  
        }

        return 0;
    }
};