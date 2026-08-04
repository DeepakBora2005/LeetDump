class Solution {
public:
    void find(int row, int col, int m, int n, int &ans) {
        if(row == m - 1 && col == n - 1) {
            ans++;
        }

        if(row < 0 || row >= m || col < 0 || col >= n) {
            return;
        }

        find(row + 1, col, m, n, ans);
    
        find(row, col + 1, m, n, ans);
    }

    int uniquePaths(int m, int n) {
        int ans = 0;

        find(0, 0, m, n, ans);

        return ans;
    }
};