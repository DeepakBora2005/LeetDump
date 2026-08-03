class Solution {
public:
    int find(int start, int n, vector<int> &nums, vector<int> &dp) {
        if(start >= n) return 0;

        if(dp[start] != -1) return dp[start];

        int first = nums[start] - find(start + 1, n, nums, dp);
        int second = 0;
        int third = 0;

        if(start + 2 < n) {
            int second = nums[start] + nums[start + 1] - find(start + 1, n, nums, dp);
        }
        if(start + 2 < n) {
            int third = nums[start] + nums[start + 1] + nums[start + 2] - find(start + 3, n, nums, dp);
        }
        
        return dp[start] = max(first, max(second, third));
    }

    string stoneGameIII(vector<int> &nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        int ans = find(0, n, nums, dp);

        if(ans == 0) return "Tie";
        else if(ans > 0) return "Alice";

        return "Bob";
    }
};