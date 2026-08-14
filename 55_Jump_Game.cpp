class Solution {
public:
    bool find(int index, int n, vector<int> &nums, vector<int> &dp) {
        if(index >= n) return true;

        if(nums[index] == 0) return false;

        for(int i = 0; i < nums[index]; i++) {
            if(find(index + i + 1, n, nums, dp) == true) {
                return true;
            }
        }

        return false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        return find(0, n - 1, nums, dp);
    }
};