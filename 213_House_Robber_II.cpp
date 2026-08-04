class Solution {
public: 
    int find(int index, vector<int> &nums) {
        if(index >= nums.size()) return 0;

        int first = nums[index] + find(index + 2, nums);
        int second = find(index + 1, nums);

        return max(first, second);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> first;
        vector<int> second;

        for(int i = 0; i < n - 1; i++) {
            first.push_back(nums[i]);
            second.push_back(nums[i + 1]);
        }

        return max(find(0, first), find(0, second));
    }
};