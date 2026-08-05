class Solution {
public:
    int find(int index, int prev, int n, vector<int> &nums) {
        if(index == n) return 0;

        int notTake = find(index + 1, index, n, nums);

        int take = 0;

        if(prev == - 1 || nums[prev] < nums[index]) {
            take = 1 + find(index + 1, index, n, nums);
        }

        return max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        return find(0, -1, n, nums);
    }
};