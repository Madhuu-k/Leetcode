class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();

        int low = 0, high = c - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            int maxRow = 0;

            for(int i = 1; i < r; i++){
                if(mat[i][mid] > mat[maxRow][mid]) maxRow = i;
            }

            int left = (mid > 0) ? mat[maxRow][mid-1] : -1;
            int right = (mid < c - 1) ? mat[maxRow][mid + 1] : -1;
 
            if(mat[maxRow][mid] > left && mat[maxRow][mid] > right) return {maxRow, mid};
            else if (left > mat[maxRow][mid]) high =  mid - 1;
            else low = mid + 1;
        }

        return {-1, -1};
    }
};