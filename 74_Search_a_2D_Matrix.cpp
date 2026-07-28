class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int left = 0;
        int right = row * col - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            int mid_val = matrix[mid / col][mid % col];

            if(mid_val == target) {
                return true;
            }
            else if(mid_val > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return false;
    }
};