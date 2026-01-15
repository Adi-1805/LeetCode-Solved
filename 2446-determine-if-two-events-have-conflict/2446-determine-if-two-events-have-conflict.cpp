class Solution {
    int string_to_time(string st){
        std::stringstream ss(st);
        int hours, minutes;
        char colon; // To consume the colon
        ss >> hours >> colon >> minutes;
        return (hours*100 + minutes);
    }
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        // ensuring event1 starts first
        if(event1[0] > event2[0]){
            vector<string> temp = event1;
            event1 = event2;
            event2 = temp;
        }

        int s1 = string_to_time(event1[0]),
        e1 = string_to_time(event1[1]),
        s2 = string_to_time(event2[0]),
        e2 = string_to_time(event2[1]);

        if(e1 >= s2) return true; // overlap
        else if(s1 >= s2 and e2 <= e1) return true; //subset
        else return false;
    }
};