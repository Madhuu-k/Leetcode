class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        int low = 0, high = col - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            int maxRow = 0;

            for(int i = 1; i < row; i++){
                if(mat[i][mid] > mat[maxRow][mid]) maxRow = i;
            }

            int left = (mid > 0) ? mat[maxRow][mid - 1] : -1;
            int right = (mid < col - 1) ? mat[maxRow][mid + 1] : -1;

            if(mat[maxRow][mid] > left && mat[maxRow][mid] > right) return {maxRow, mid};
            else if(left > mat[maxRow][mid]) high = mid - 1;
            else low = mid + 1;
        }
        return {-1, -1};
    }
};