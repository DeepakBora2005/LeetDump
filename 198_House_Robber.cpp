class Solution {
public:
    int find(int index, vector<int> &nums) {
        if(index >= nums.size()) return 0;

        int first = nums[index] + find(index + 2, nums);
        int second = find(index + 1, nums);

        return max(first, second);
    }

    int rob(vector<int>& nums) {
        int ans = 0;

        if(nums.size() == 1) return nums[0];

        return find(0, nums);
    }
};