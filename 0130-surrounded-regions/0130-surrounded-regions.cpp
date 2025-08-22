class Solution {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    void dfs(int r, int c, int n, int m, vector<vector<char>>& board, vector<vector<bool>>& vis){
        vis[r][c] = 1;
        board[r][c] = '#';
        for(int i = 0; i < 4; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(nr >= 0 and nr < n and nc >= 0 and nc < m and !vis[nr][nc] and board[nr][nc] == 'O'){
                dfs(nr, nc, n, m, board, vis);
                
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        // Mark the edge 'O's as irreplaceable
        for(int i = 0; i < n; i++) if(board[i][0] == 'O') dfs(i, 0, n, m, board, visited);
        for(int i = 0; i < n; i++) if(board[i][m-1] == 'O') dfs(i, m-1, n, m, board, visited);
        for(int j = 0; j < m; j++) if(board[0][j] == 'O') dfs(0, j, n, m, board, visited);
        for(int j = 0; j < m; j++) if(board[n-1][j] == 'O') dfs(n-1, j, n, m, board, visited);

        for(int i = 0; i < n; i++){
            for(int j =0; j < m; j++){
                if(board[i][j] == '#') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }

    }
};