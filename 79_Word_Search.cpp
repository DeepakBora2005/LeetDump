class Solution {
public:
    void find(vector<vector<bool>> &visited, vector<vector<char>> &board, string &word, int row, int col, int m, int n, string &temp, string &result) {
        if(row >= m || row < 0 || col >= n || col < 0) {
            return;
        }

        if(visited[row][col]) return;

        if(temp == word) {
            result.push_back(temp);
            return;
        }

        visited[row][col] = true;

        find(visited, board, word, row + 1, col, m, n, temp + board[row][col], result);
        find(visited, board, word, row, col + 1, m, n, temp + board[row][col], result);
        find(visited, board, word, row - 1, col, m, n, temp + board[row][col], result);
        find(visited, board, word, row, col - 1, m, n, temp + board[row][col], result);
        
        visited[row][col] = false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        string result = "";

        find(visited, board, word, 0, 0, m, n, "", result);

        return result == word;
    }
};