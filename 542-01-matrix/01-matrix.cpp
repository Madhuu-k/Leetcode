class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        queue<pair<int, int>> q;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(mat[i][j] == 0) {
                    q.push({i, j});
                } else {
                    mat[i][j] = -1;
                }
            }
        }

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nc >= 0 && nr < rows && nc < cols && mat[nr][nc] == -1){
                    mat[nr][nc] = 1 + mat[r][c];
                    q.push({nr, nc});
                }
            }
        }
        
        return mat;
    }
};
