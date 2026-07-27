class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        if(n == 2) {
            return min(nums[0], nums[1]);
        }

        int mini = min(nums[0], nums[n - 1]);

        int low = 1;

        int high = n - 2;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] < mini) {
                mini = nums[mid];
            }

            if(nums[mid] > nums[low]) {
                if(nums[low] < mini) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else {
                if(nums[high] < mini) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return mini;
    }
};