class TaskManager {
    // map to store the taskId to prority mappings to facilitate O(1) look up and O(1) for updations i.e., taskId: {priority, userId}
    unordered_map<int, pair<int, int>> mp;
    // Priority Queue to store: {priority, {taskId, userId}}
    priority_queue< pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>> >pq; 
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto& vec: tasks){
            int uId = vec[0], tId = vec[1], prt = vec[2];
            mp[tId] = {prt, uId};
            pq.push({prt, {tId, uId}});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId] = {priority, userId};
        pq.push({priority, {taskId, userId}});
    }
    
    void edit(int taskId, int newPriority) {
        /* We're updating the map here not the queue so the old value will remain in Queue so upon executing the top task we'll check if it's priority matches with the one that exists in the map, if not we'll simply pop
        */
        if(mp.find(taskId) != mp.end()){
            int uId = mp.at(taskId).second;
            mp[taskId] = {newPriority, uId};
            pq.push({newPriority, {taskId, uId}});
        }
    }
    
    void rmv(int taskId) {
        mp.erase(taskId);
    }
    
    int execTop(){

        while (!pq.empty()) {
            int prt = pq.top().first;
            int tId = pq.top().second.first;
            int uId = pq.top().second.second;

            // Pop element then check validity
            pq.pop();
            
            // Check if the tId still exists in the map
            if (mp.count(tId) > 0) {
                // Check if the priority matches in the map
                if(prt == mp[tId].first){
                    // Valid task. Process it.
                    mp.erase(tId);
                    return uId;
                }
            }
            // If the code reaches here, the task was either outdated or removed. The loop will continue.
        }
        
        // If the loop finishes, the priority queue is empty.
        return -1;
    }
};

/*
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */