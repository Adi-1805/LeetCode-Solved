class MyCalendarTwo {
    map<int, int> timestamps;
public:
    MyCalendarTwo() {
        timestamps = {};
    }
    
    bool book(int startTime, int endTime) {
        timestamps[startTime]++;
        timestamps[endTime]--;
        int count = 0;
        for(auto &[time, val]: timestamps){
            count += val;
            if(count >= 3){
                timestamps[startTime]--;
                timestamps[endTime]++;
                if(timestamps[startTime] == 0) timestamps.erase(startTime);
                if(timestamps[endTime] == 0) timestamps.erase(endTime);
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */