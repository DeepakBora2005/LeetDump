class Solution {
public:
    long long find(long long index, vector<vector<int>> &nums, vector<long long> &dp) {
        int n = nums.size(); 

        if(index >= n) return 0;

        if(dp[index] != -1) return dp[index];

        long long skip = nums[index][1];
        long long take = nums[index][0] + find(index + skip + 1, nums, dp);
        
        long long notTake = find(index + 1, nums, dp);

        return dp[index] = max(take, notTake);
    }

    long long mostPoints(vector<vector<int>>& nums) {
        long long n = nums.size();

        vector<long long> dp(n, -1);

        return find(0, nums, dp);
    }
};