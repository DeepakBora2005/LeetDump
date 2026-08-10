class Solution {
public:
    int find(int i, int j, vector<int> &nums, vector<vector<int>> dp) {
        if(i == j) return nums[j];

        int leftMost = nums[i] - find(i + 1, j, nums, dp);
        int rightMost = nums[j] - find(i, j - 1, nums, dp);

        return max(leftMost, rightMost);
    }

    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return find(0, n - 1, stones, dp);
    }
};