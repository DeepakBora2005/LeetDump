class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m =  mat.size();

        int n = mat[0].size();

        int ans = 0;

        int rowIndex = 0;
        int colIndex = 0;

        for(int i = 0; i < m; i++) {
            int low = 0;
            int high = n - 1;

            while(low < high) {
                int mid = low + (high - low) / 2;

                if(mat[i][mid] > mat[i][mid + 1
                ]) {
                    high = mid;
                    rowIndex = i;
                    colIndex = mid;
                }
                else {
                    low = mid + 1;
                }
            }

            if(mat[rowIndex][colIndex] > ans) {
                ans = mat[rowIndex][colIndex];
            }
        }
        
        return {rowIndex, colIndex};
    }
};