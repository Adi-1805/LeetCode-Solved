class Spreadsheet {
    unordered_map<string, int> cell_map;
    vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token; stringstream ss(s);
        while(getline(ss, token, delimiter)) tokens.push_back(token);
        return tokens;
    }
public:
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        cell_map[cell] = value;
    }
    
    void resetCell(string cell) {
        cell_map[cell] = 0;
    }
    
    int getValue(string formula) {
        int result = 0;
        string s = formula.substr(1, formula.size()-1);
        vector<string> values = split(s, '+');
        for(string ss: values){
            if(cell_map.find(ss) != cell_map.end()){
                result += cell_map[ss];
            }else{
                stringstream sss(ss);
                int num = 0;
                sss >> num;
                result += num;
            }
        } 
        return result;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */