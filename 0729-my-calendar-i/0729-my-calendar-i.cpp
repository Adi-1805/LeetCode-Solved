class MyCalendar {
public:
    map<int, int> timestamp;
    MyCalendar() {
        timestamp = {};
    }
    
    bool book(int startTime, int endTime) {
        timestamp[startTime] += 1;
        timestamp[endTime] -= 1;
        int count = 0;
        for(auto [ts, val]: timestamp){
            count += val;
            if(count >= 2){
                timestamp[startTime] -= 1;
                timestamp[endTime] += 1;
                if(timestamp[startTime] == 0) timestamp.erase(startTime);
                else if(timestamp[endTime] == 0) timestamp.erase(endTime);
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */