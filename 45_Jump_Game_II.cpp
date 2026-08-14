class Solution {
public:
    int find(int index, int n, vector<int> &nums, vector<int> &dp) {
        if(index == n - 1) return 0;

        if(nums[index] == 0) {
            return INT_MAX;
        }

        if(dp[index] != -1) return dp[index];

        int ans = INT_MAX;

        for(int i = 1; i <= nums[index]; i++) {
            if(index + i < n) {
                int temp = find(index + i, n, nums, dp);
                
                if(temp != INT_MAX) ans = min(ans, 1 + temp);
            }
        }

        return dp[index] = ans;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        return find(0, n, nums, dp);
    }
};