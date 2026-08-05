class Solution {
public:
    bool find(int index, int n, int currSum, int target, vector<int> &nums, vector<vector<int>> &dp) {
        if(currSum == target) return true;

        if(currSum > target || index >= n) return false;

        if(dp[index][currSum] != -1) return dp[index][currSum];

        return find(index + 1, n, currSum + nums[index], target, nums, dp) || find(index + 1, n, currSum, target, nums, dp);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
         
        for(int num : nums) {
            totalSum += num;
        }

        if(totalSum % 2 != 0) return false;

        int target = totalSum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return find(0, n, 0, target, nums, dp);
    }
};