class Solution {
public:
    bool isSafe(int row, int col, vector<string> &board, int n) {
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }

        int r = row - 1;
        int c = col - 1;

        while(r >= 0 && c >= 0) {
            if(board[r][c] == 'Q') {
                return false;
            }

            r--;
            c--;
        }

        r = row - 1;
        c = col + 1;

        while(r >= 0 && c < n) {
            if(board[r][c] == 'Q') {
                return false;
            }

            r--;
            c++;
        }

        return true;
    }

    void find(int row, int n, vector<string> &board, vector<vector<string>> &ans) {
        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++) {
            if(isSafe(row, col, board, n)) {
                board[row][col] = 'Q';

                find(row + 1, n, board, ans);

                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        vector<vector<string>> ans;

        find(0, n, board, ans);

        return ans;
    }
};