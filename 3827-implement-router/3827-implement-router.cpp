class Router {
    // Basic data structure for FIFO
    queue< vector<int> > q; 
    // Set to store unique packets
    set< vector<int> > st;
    // Map to store packets 
    unordered_map< int, vector<int> > mp;
    // 'size' variable to store size
    int size = 1e9;

public:
    Router(int memoryLimit) {
        size = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        // check for overflow
        vector<int> packet = {source, destination, timestamp};
        if(st.count(packet) > 0) return false;
        if(q.size()+1 > size){
            st.erase(q.front());

            int s = q.front()[0];
            int d = q.front()[1];
            int tm = q.front()[2];
            auto &vec = mp[d];
            if(!vec.empty() and vec.front() == tm) vec.erase(vec.begin());
            if(!q.empty()) q.pop();
        }
        q.push(packet);
        st.insert(packet);
        mp[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()) return {};

        int s = q.front()[0];
        int d = q.front()[1];
        int tm = q.front()[2];
        q.pop();
        st.erase({s, d, tm});

        auto &vec = mp[d];
        auto it = lower_bound(vec.begin(), vec.end(), tm);
        if(it != vec.end() and *it == tm) vec.erase(it);
        return {s, d, tm};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto &vec = mp[destination];
        int l = lower_bound(vec.begin(), vec.end(), startTime) - vec.begin();
        int r = upper_bound(vec.begin(), vec.end(), endTime) - vec.begin();
        return r - l;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */