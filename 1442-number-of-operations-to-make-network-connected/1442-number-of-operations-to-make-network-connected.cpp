class DisjointSet {
    vector<int> parent, size, rank;
    public:
    DisjointSet(int n) {
        rank.resize(n+1, 0); size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int findUltPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUltPar(parent[node]);
    }
    void unionBySize(int u, int v){
        int pu = findUltPar(u);
        int pv = findUltPar(v);
        if(pu == pv) return;
        // Compare size of parents
        if(size[pu] > size[pv]){ 
            parent[pv] = pu;
            size[pu] += size[pv];
        } else { 
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
    void unionByRank(int u, int v){
        int pu = findUltPar(u);
        int pv = findUltPar(v);
        if(pu == pv) return;
        // Compare size of parents
        if(rank[pu] > rank[pv]){ 
            parent[pv] = pu;
        } else if(rank[pu] < rank[pv]) { 
            parent[pu] = pv;
        } else {
            parent[pu] = pv;
            rank[pv] += 1;
        }
    }
    
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // Clearly if N nodes are there we need at least N-1 edges to join all nodes as required
        // So we initially need to find the the number of computers that are not connected i.e., we need to find the number o f  componets using dfs, bfs or disjoint sets

        if(connections.size() < n-1) return -1;

        DisjointSet ds(n);
        for(auto vec: connections){
            ds.unionBySize(vec[0], vec[1]);
        }
        int components = 0;
        for(int i = 0 ; i < n; i++){
            if(ds.findUltPar(i) == i) components++;
        }

        return components-1;
    }
};