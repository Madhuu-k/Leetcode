class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                int left = (j > 0) ? mat[i][j-1] : -1;
                int right = (j < c - 1) ? mat[i][j+1] : -1;
                int up = (i > 0) ? mat[i-1][j] : -1;
                int down = (i < r - 1) ? mat[i+1][j] : -1;

                if(mat[i][j] > left && mat[i][j] > right && mat[i][j] > up && mat[i][j] > down) return {i, j};
            }
        }

        return {-1, -1};
    }
};