class Solution {
public:
    int count(int index, int n, int sum, int target, int totalSum, vector<int> &nums, vector<vector<int>> &dp) {
        if(index == n) {
            if(sum == target) return 1;
            else return 0;
        }

        if(dp[index][sum + totalSum] != -1) return dp[index][sum + totalSum];
    
        int left = count(index + 1, n, sum - nums[index], target, totalSum, nums, dp);
        int right = count(index + 1, n, sum + nums[index], target, totalSum, nums, dp);

        return dp[index][sum + totalSum] = left + right;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
 
        int totalSum = 0;

        for(int num : nums) {
            totalSum += num;
        }

        vector<vector<int>> dp(n, vector<int>(2 * totalSum + 1, -1));

        return count(0, n, 0, target, totalSum, nums, dp);
    }
};