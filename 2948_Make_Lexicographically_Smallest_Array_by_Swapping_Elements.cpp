class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        int right = n - 1;
        int left = 0;

        while(limit > 0 && right != left) {
            if(nums[right] < nums[left]) {
                limit--;
                swap(nums[right], nums[left]);
            }

            right--;
        }

        return nums;
    }
};