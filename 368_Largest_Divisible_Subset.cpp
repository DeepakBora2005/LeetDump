class Solution {
public:
    void find(int i, vector<int> &nums, vector<int> &ans) {
        int n = nums.size();

        if(i >= n) return;

        if(i + 1 < n) {
            if((nums[i] % nums[i + 1] == 0) || (nums[i + 1] % nums[i] == 0)) {
                ans.push_back(nums[i]);
                ans.push_back(nums[i + 1]);
            }

            find(i + 1, nums, ans);
        }
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ans;

        find(0, nums, ans);

        return ans;
    }
};