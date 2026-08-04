class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    bool find(int index, int row, int col, vector<vector<char>> &board, string &word, vector<vector<bool>> &visited) {
        if(index == word.size()) {
            return true;
        }

        int m = board.size();
        int n = board[0].size();

        if(row >= m || row < 0 || col >= n || col < 0) {
            return false;
        }

        if(board[row][col] != word[index]) return false;

        if(visited[row][col]) return false;

        visited[row][col] = true;

        for(int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(find(index + 1, nr, nc, board, word, visited)) {
                visited[row][col] = false;
                return true;
            }
        }
        
        visited[row][col] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        if(word.size() > m * n) return false;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(word[0] == board[i][j] && find(0, i, j, board, word, visited)) return true;
            }
        }
        
        return false;
    }
};