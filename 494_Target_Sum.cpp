class Solution {
public:
    int count(int index, int n, int sum, int target, vector<int> &nums, map<pair<int, int>, int> &dp) {
        if(index == n) {
            if(sum == target) return 1;
            else return 0;
        }

        pair<int, int> state = {index, sum};
        if(dp.find(state) != dp.end()) return dp[state];
    
        int left = count(index + 1, n, sum - nums[index], target, nums, dp);
        int right = count(index + 1, n, sum + nums[index], target, nums, dp);

        return dp[state] = left + right;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
 
        map<pair<int, int>, int> dp;

        return count(0, n, 0, target, nums, dp);
    }
};