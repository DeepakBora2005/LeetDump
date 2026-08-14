class Solution {
public:
    bool find(int index, int n, vector<int> &nums, vector<int> &dp) {
        if(index >= n) return true;

        if(nums[index] == 0) return false;

        return find(index + 1, n, nums, dp) || find(index + nums[index], n, nums, dp);

        return false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        return find(0, n - 1, nums, dp);
    }
};