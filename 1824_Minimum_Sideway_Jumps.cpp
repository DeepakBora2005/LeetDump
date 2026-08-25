class Solution {
public:
    int find(int index, int lane, vector<int> &nums) {
        int n = nums.size();

        if(index >= n) {
            return 0;
        }

        if(nums[index + 1] != lane) {
            return find(index + 1, lane, nums);
        }

        int ans = INT_MAX;

        if(lane != 1 && nums[index] != 1) {
            ans = min(ans, 1 + find(index, 1, nums));
        }
        if(lane != 2 && nums[index] != 2) {
            ans = min(ans, 1 + find(index, 2, nums));
        }
        if(lane != 3 && nums[index] != 3) {
            ans = min(ans, 1 + find(index, 3, nums));
        }

        return ans;
    }

    int minSideJumps(vector<int>& nums) {
        return find(0, 2, nums);
    }
};