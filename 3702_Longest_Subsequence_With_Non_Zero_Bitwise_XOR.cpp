class Solution {
public:
    int find(int i, int curr, vector<int> &nums, vector<vector<int>> &dp) {
        int n = nums.size();

        if(i == n) return 0;

        int take = 0;
        int notTake = 0;
        if(curr ^ nums[i] != 0) {
            take = 1 + find(i + 1, curr ^ nums[i], nums, dp);
        }

        notTake = find(i + 1, curr, nums, dp);


        return max(take, notTake);
    }

    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return find(0, 0, nums, dp);
    }
};