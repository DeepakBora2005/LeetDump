class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        int first;
        int last;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] >= target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        if(low < n && nums[low] == target) {
            first = low;
        }
        else {
            first = -1;
        }

        low = 0;
        high = n - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        if(high >= 0 && nums[high] == target) {
            last = high;
        }
        else {
            last = -1;
        }

        return {first, last};
    }
};