class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MIN;
        int index = 0;

        int low = 0;
        int high = n - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] > ans) {
                index = mid;
                ans = nums[mid];
            }

            if(nums[mid + 1] > nums[mid]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return index;
    }
};