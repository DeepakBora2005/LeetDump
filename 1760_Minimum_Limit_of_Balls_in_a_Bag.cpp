class Solution {
public:
    int possible(int mid, vector<int> &nums, int k) {
        int op = 0;

        for(int i = 0; i < nums.size(); i++) {
            op += (nums[i] - 1) / mid;

            if(op > k) return false;
        }

        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        int ans = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(possible(mid, nums, maxOperations)) {
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