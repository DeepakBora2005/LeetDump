class Solution {
public: 
    int find(int index, vector<int> &nums, vector<int> &dp) {
        if(index >= nums.size()) return 0;

        if(dp[index] != - 1) return dp[index];

        int first = nums[index] + find(index + 2, nums, dp);
        int second = find(index + 1, nums, dp);

        return dp[index] = max(first, second);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> first;
        vector<int> second;

        vector<int> dp1(n - 1, -1);
        vector<int> dp2(n - 1, -1);

        for(int i = 0; i < n - 1; i++) {
            first.push_back(nums[i]);
            second.push_back(nums[i + 1]);
        }

        return max(find(0, first, dp1), find(0, second, dp2));
    }
};