class DetectSquares {
    // d[(x,y)] -> freq
    unordered_map<long long, int> d;
    // x_coord[x][y] -> freq
    unordered_map<int, unordered_map<int, int>> x_coord;
    // custome hash to encode coords with their frequency
    auto encode(int x, int y){
        return (long long)x << 32 | (unsigned int)y;
    }
public:
    DetectSquares(){}
    void add(vector<int> point){
        if(point.empty()) return ;
        int x = point[0], y = point[1];
        d[encode(x, y)]++;
        x_coord[x][y]++;
    }
    
    int count(vector<int> point) {
        if(point.empty()) return -1;
        int x = point[0], y = point[1];
        int ans = 0;
        if (!x_coord.count(x)) return 0;
        for (auto &p : x_coord[x]) {
            int y2 = p.first;
            if (y2 == y) continue;
            int freq = p.second;
            int x1 = x + (y2 - y);   // right side
            int x2 = x - (y2 - y);   // left side
            ans += freq * d[encode(x1, y)] * d[encode(x1, y2)];
            ans += freq * d[encode(x2, y)] * d[encode(x2, y2)];
        }

        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */