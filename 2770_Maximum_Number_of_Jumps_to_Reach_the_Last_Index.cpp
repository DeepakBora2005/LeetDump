class Solution {
public:
    int find(int index, vector<int> &nums, int target, vector<int> &dp) {
        int n  = nums.size();

        if(index >= n) return -1;

        if(index == n - 1) return 0;

        if(dp[index] != INT_MIN) return dp[index];

        int mini = -target;
        int maxi = target;

        int ans = -1;
        for(int j = 1; j < n; j++) {
            int temp = -1;
            if((index + j < n) && (nums[index + j] - nums[index] <= maxi) && (nums[index + j] - nums[index] >= mini)) {
                temp = find(index + j, nums, target, dp);

                if(temp != -1) {
                    ans = max(ans, 1 + temp);
                }
            }
        }

        return dp[index] = ans;
    }

    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> dp(n + 1, INT_MIN);

        return find(0, nums, target, dp);
    }
};