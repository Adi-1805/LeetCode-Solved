class Solution {
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
    int m, n;
    void dfs(vector<vector<char>>& board, int x, int y){
        if( x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O' ){
            return;
        }
        board[x][y] = '#'; // marking as irreplaceable
        for(int i = 0; i < 4; i++){
            int r = x + drow[i];
            int c = y + dcol[i];
            dfs(board, r, c);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        /* Think of the question as a maze where Os are path and Xs are walls, if you are at an O and you can escape the board  then that "path" of Os will not be replaced by X.

        Hence we will use dfs to mark all such Os as irreplaceable.
        */

        m = board.size();
        n = board[0].size();
        // Mark 'O's connected to borders
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][n - 1] == 'O') dfs(board, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[m - 1][j] == 'O') dfs(board, m - 1, j);
        }
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};