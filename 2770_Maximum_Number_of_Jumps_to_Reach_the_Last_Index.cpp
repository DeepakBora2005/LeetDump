class Solution {
public:
    int find(int index, vector<int> &nums, int target) {
        int n  = nums.size();

        if(index >= n) return -1;

        if(index == n - 1) return 0;
        int mini = -target;
        int maxi = target;

        int ans = -1;
        for(int j = 1; j < n; j++) {
            int temp = -1;
            if((index + j < n) && (nums[index + j] - nums[index] <= maxi) && (nums[index + j] - nums[index] >= mini)) {
                temp = 1 + find(index + j, nums, target);
            }

            ans = max(ans, temp);
        }

        return ans;
    }

    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        return find(0, nums, target);
    }
};