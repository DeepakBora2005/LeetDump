class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        if(n == 1) return nums;

        int right = n - 2;
        int left = 0;

        while(left < right) {
            if(left + 1 < n) {
                if(limit > 0 && nums[left + 1] < nums[left]) {
                    limit--;
                    swap(nums[left], nums[left + 1]);
                }
            }
            
            if(right >= 0) {
                if(limit > 0 && nums[right + 1] < nums[right]) {
                    limit--;
                    swap(nums[right], nums[right + 1]);
                }
            }

            left++;
            right--;
        }

        return nums;
    }
};