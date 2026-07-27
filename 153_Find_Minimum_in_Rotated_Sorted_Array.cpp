class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        int ans = INT_MAX;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] < ans) {
                ans = nums[mid];
            }

            if(nums[low] <= nums[mid]) {
                ans = nums[low];
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};