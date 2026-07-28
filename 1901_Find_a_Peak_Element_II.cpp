class Solution {
public:
    int find(vector<vector<int>> &matrix, int m, int n, int mid) {
        int maxRow = 0;

        for(int i = 0; i < m; i++) {
            if(matrix[i][mid] > matrix[maxRow][mid]) {
                maxRow = i;
            }
        }

        return maxRow;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m =  mat.size();

        int n = mat[0].size();

        int ans = 0;

        int rowIndex = 0;
        int colIndex = 0;

        int low = 0;
        int high = n - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int maxRow = find(mat, m, n, mid);

            int left = mid - 1 >= 0 ? mat[maxRow][mid - 1] : -1;
            int right = mid + 1 < n ? mat[maxRow][mid + 1] : -1;

            if(mat[maxRow][mid] > left && mat[maxRow][mid] > right) return {maxRow, mid};
            else if(mat[maxRow][mid] < left) high = mid - 1;
            else low = mid + 1; 
        }
        
        return {rowIndex, colIndex};
    }
};