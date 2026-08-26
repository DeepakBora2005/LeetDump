class Solution {
public:
    int find(int i, int j, vector<int> &nums) {
        int n = nums.size();

        if(i >= n || j < 0) return 1;

        if(i == j) return nums[i];

        int ans = INT_MIN;
        for(int k = i; k <= j; k++) {
            int cost = nums[k] * (k == 0 ? 1 : nums[k - 1]) * (k == n - 1 ? 1 : nums[k + 1]) + find(i, k - 1, nums) + find(k + 1, j, nums);

            ans = max(ans, cost);
        }

        return ans;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        return find(0, n - 1, nums);
    }
};