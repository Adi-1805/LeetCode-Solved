class MyCalendarThree {
public:
    map<int, int> timestamps;
    MyCalendarThree() {
        timestamps = {};
    }
    
    int book(int startTime, int endTime) {
        timestamps[startTime]++; timestamps[endTime]--;
        int max_val = 0, cnt = 0;
        for(map<int, int>::iterator it = timestamps.begin(); it != timestamps.end(); it++){
            cnt += it->second; max_val = max(max_val, cnt);
        }
        return max_val;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */