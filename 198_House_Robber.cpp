class Solution {
public:
    int find(int index, vector<int> &nums) {
        if(index >= nums.size()) return 0;

        int first = nums[index] + find(index + 2, nums);

        return first;
    }

    int rob(vector<int>& nums) {
        int ans = 0;

        if(nums.size() == 1) return nums[0];

        return max(find(1, nums), find(0, nums));
    }
};