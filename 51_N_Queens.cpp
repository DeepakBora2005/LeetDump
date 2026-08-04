class Solution {
public:
    bool isSafe(int row, int col, vector<string> &board, int n) {
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }

        int upperRow = row - 1;
        int upperCol = col - 1;

        while(upperRow >= 0  && upperCol >= 0) {
            if(board[upperRow][upperCol] == 'Q') {
                return false;
            }   
            upperRow--;
            upperCol--;
        }

        upperRow = row - 1;
        upperCol = col + 1;

        while(upperRow >= 0 && upperCol < n) {
            if(board[upperRow][upperCol] == 'Q') {
                return false;
            }
            upperRow--;
            upperCol++;
        }

        return true;
    }

    void find(int row, vector<string> &board, vector<vector<string>> &ans, int n) {
        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(isSafe(row, i, board, n)) {
                board[row][i] = 'Q';

                find(row + 1, board, ans, n);

                board[row][i] = '.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        vector<vector<string>> ans;
    
        find(0, board, ans, n);

        return ans;
    }
};