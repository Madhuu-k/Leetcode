class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        visited[r][c] = true;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int rows = grid.size();
        int cols = grid[0].size();

        for(int k = 0; k < 4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1' && !visited[nr][nc]) dfs(nr, nc, grid, visited);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int islands = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j <cols; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    islands++;
                    dfs(i, j, grid, visited);
                }
            }
        }

        return islands;
    }
};