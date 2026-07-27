class Solution {
public:
    bool possible(int mid, vector<int> &nums, int t) {
        int temp = 0;

        for(int i = 0; i < nums.size(); i++) {
            temp += (nums[i] + mid - 1) / mid;

            if(temp > t) return false;
        }

        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int low = 1;
        int high;

        for(int num : nums) {
            high = max(high, num);
        }

        int ans = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(possible(mid, nums, threshold)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};