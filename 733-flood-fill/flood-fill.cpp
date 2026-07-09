class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void dfs(vector<vector<int>>& image, vector<vector<bool>>& visited, int r, int c, int color, int org){
        int rows = image.size();
        int cols = image[0].size();
        image[r][c] = color;
        visited[r][c] = true;

        for(int k = 0; k < 4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr >= 0 && nc >= 0 && nr < rows && nc < cols && !visited[nr][nc] && image[nr][nc] == org)
                dfs(image, visited, nr, nc, color, org);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();

        int org = image[sr][sc];

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        dfs(image, visited, sr, sc, color, org);

        return image;
    }
};