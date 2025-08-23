class Solution {
    bool DFScheck(int node, vector<vector<int>>& adjacencyList, vector<int>& visited, vector<int>& pathVisited){
        /* DFScheck function:
            Traverses graph using recursion and returns true if a cycle is detected in the graph, else return false;
        */
        visited[node] = 1;
        pathVisited[node] = 1;
        for(int nextNode: adjacencyList[node]){
            if(!visited[nextNode]){
                if(DFScheck(nextNode, adjacencyList, visited, pathVisited)) return true;
            }
            else if(pathVisited[nextNode]) return true;
        }

        pathVisited[node] = 0;

        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Graph simulation of the problem
        // Each course is a node 
        vector<vector<int>> adjacencyList(numCourses);
        for(auto pair: prerequisites){
            adjacencyList[pair[1]].push_back(pair[0]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);

        for(int course = 0; course < numCourses; course++){
            if(!visited[course]){
                if(DFScheck(course, adjacencyList, visited, pathVisited)) return false;
            }
        }

        return true;
    }
};