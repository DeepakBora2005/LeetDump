class Solution {
public:
    int find(vector<int> &nums, int start, int end, vector<vector<int>> &dp) {
        if(start == end) {
            return nums[start];
        }
            
        if(dp[start][end] != -1) {
            return dp[start][end];
        }

        int leftMost = nums[start] - find(nums, start + 1, end, dp);

        int rightMost = nums[end] - find(nums, start, end - 1, dp);
        
        return dp[start][end] = max(leftMost, rightMost);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return find(nums, 0, n - 1, dp) >= 0;
    }
};