class MovieRentingSystem {
    // NOTE: "shop and movie together is a primary key"

    // 1 map to store the mapping where shop and movie are key and price is value
    unordered_map< uint64_t, int > ShopMovieMap; 
    // 1 pq with {price, key(shop, movie)} of unrented movies
    unordered_map< int, set<pair<int, int>> > MovieSearchMap; 
    // 1 set of rented movies, only contains movie IDs (can be mapped to price and shop using MovieSearchMap)
    set<vector<int>> rentedMovies;

    static inline uint64_t key(int shop,int movie) {
        return (uint64_t)shop<<32|movie;
    }

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &entry: entries){
            int shop = entry[0], movie = entry[1], price = entry[2];
            ShopMovieMap[key(shop, movie)] = price;
            MovieSearchMap[movie].insert({price, shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> result;
        auto &s = MovieSearchMap[movie];
        int i = 0;
        for(auto it = s.begin(); it != s.end() and i < 5; it++, i++){
            result.push_back(it->second);
        }
        return result;
    }
    
    void rent(int shop, int movie) {
        int price = ShopMovieMap[key(shop, movie)];
        MovieSearchMap[movie].erase({price, shop});
        rentedMovies.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = ShopMovieMap[key(shop, movie)];
        MovieSearchMap[movie].insert({price, shop});
        rentedMovies.erase({price, shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int i=0;
        for (auto it = rentedMovies.begin(); it != rentedMovies.end() && i<5; it++, i++) {
            auto vec = *it;
            int price = vec[0], shop = vec[1], movie = vec[2];
            ans.push_back({shop, movie});
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */