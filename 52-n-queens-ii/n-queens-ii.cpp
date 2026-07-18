class Solution {
public:
    int count = 0;

    bool isSafe(vector<string>& board, int row, int col){
        // COLON SAFETY
        for(int i = row - 1; i >= 0; i--){
            if(board[i][col] == 'Q') return false;
        }

        // UPPER LEFT DIAGONAL CHECK
        int r = row - 1; int c = col - 1;
        while(r >= 0 && c >= 0){
            if(board[r][c] == 'Q') return false;
            r--; c--;
        } 

        // UPPER RIGHT DIAGONAL CHECK
        r = row - 1; c = col + 1;
        while(r >= 0 && c < board.size()){
            if(board[r][c] == 'Q') return false;
            r--; c++;
        }

        return true;
    }

    void backtrack(int row, int n, vector<string>& board){
        if(row == n){
            count++;
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

    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(0, n, board);
        return count;
    }
};