class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m =  mat.size();

        int n = mat[0].size();

        int ans = 0;

        int rowIndex = 0;
        int colIndex = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] > ans) {
                    ans = mat[i][j];
                    rowIndex = i;
                    colIndex = j;
                }
            }
        }


        return {rowIndex, colIndex};
    }
};