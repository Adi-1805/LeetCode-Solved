class Solution {
    bool DFScheck(int node, vector<vector<int>>& adjacencyList, vector<int>& visited, vector<int>& pathVisited, stack<int> &revCourseOrder){
        /* DFScheck function:
            Traverses graph using recursion and returns true if a cycle is detected in the graph, else return false;
        */
        visited[node] = 1;
        pathVisited[node] = 1;
        for(int nextNode: adjacencyList[node]){
            if(!visited[nextNode]){
                if(DFScheck(nextNode, adjacencyList, visited, pathVisited, revCourseOrder)) return true; //cycle detected
            }
            else if(pathVisited[nextNode]) return true; // cycle detected
        }

        pathVisited[node] = 0;
        revCourseOrder.push(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Graph simulation of the problem
        // Each course is a node 
        if(numCourses == 1) return {0};
        vector<vector<int>> adjacencyList(numCourses);
        for(auto pair: prerequisites){
            adjacencyList[pair[1]].push_back(pair[0]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);
        stack<int> revCourseOrder;

        for(int course = 0; course < numCourses; course++){
            if(!visited[course]){
                if(DFScheck(course, adjacencyList, visited, pathVisited, revCourseOrder)) return {};
            }
        }

        vector<int> courseOrder;
        while(!revCourseOrder.empty()){
            courseOrder.push_back(revCourseOrder.top());
            revCourseOrder.pop();
        }
        return courseOrder;
    }
};