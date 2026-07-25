class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        int ans = 0;

        while(left <= right) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) {
                ans =  mid;
                break;
            }
            else if(nums[mid] < target) {
                if(nums[mid] < target) {
                    if(mid == n - 1) {
                        ans = mid + 1;
                    }
                    else if(nums[mid + 1] > target) {
                        ans = mid + 1;
                    }
                    break;
                }
                else {
                    low = mid + 1;
                }
            }
            else {
                if(nums[mid] > target && nums[mid - 1] < target) {
                    ans = mid;
                    break;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return ans;
    }
};