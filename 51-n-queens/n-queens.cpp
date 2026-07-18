class Solution {
public:
    vector<vector<string>> ans;
    
    bool isSafe(vector<string>& board, int row, int col){
        // CHECK FOR COLON SAFETY
        for(int i = row - 1; i >= 0; i--){
            if(board[i][col] == 'Q') return false;
        }

        // CHECK FOR UPPER LEFT DIAGNOL SAFETY
        int r = row - 1;
        int c = col - 1;

        while(r >= 0 && c >= 0){
            if(board[r][c] == 'Q') return false;
            r--; c--;
        }

        // CHECK FOR UPPER RIGHT DIAGNOL SAFETY
        r = row - 1; c = col + 1;

        while(r >= 0 && c < board.size()){
            if(board[r][c] == 'Q') return false;
            r--; c++;
        }

        return true;
    }

    void backtrack(int row, int n, vector<string>& board){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++){
            if(isSafe(board, row, col)){
                board[row][col] = 'Q';
                backtrack(row + 1, n, board);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(0, n, board);
        return ans;
    }
};