class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m =  mat.size();

        int n = mat[0].size();

        int ans = 0;

        int rowIndex = 0;
        int colIndex = 0;

        int row = 0;
        int col = n - 1;

        while(row < m && col >= 0) {
            if(mat[row][col] > ans) {
                ans = mat[row][col];
                rowIndex = row;
                colIndex = col;
                row++;
            }
            else {
                col--;
            }
        }

        return {rowIndex, colIndex};
    }
};