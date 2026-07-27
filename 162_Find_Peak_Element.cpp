class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 0;

        if(n == 2) {
            if(nums[0] > nums[1]) return 0;
            else return 1;
        }

        int ans = max(nums[0], nums[n - 1]);
        int index = 0;

        int low = 1;
        int high = n - 2;

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