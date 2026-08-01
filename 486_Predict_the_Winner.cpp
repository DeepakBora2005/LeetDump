class Solution {
public:
    int find(vector<int> &nums, int start, int end) {
        if(start == end) return nums[start];

        int leftMost = nums[start] - find(nums, start + 1, end);

        int rightMost = nums[end] - find(nums, start, end - 1);

        return max(leftMost, rightMost);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        return find(nums, 0, n - 1) >= 0;
    }
};