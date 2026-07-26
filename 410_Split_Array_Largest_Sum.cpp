class Solution {
public:
    bool possible(int mid, vector<int> &nums, int k) {
        int currentSum = 0;
        int count = 1;

        for(int num : nums) {
            if(currentSum + num <= mid) {
                currentSum += num;
            }
            else {
                count++;
                currentSum = 0;
            }
        }

        if(count <= k) return true;

        return false;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int low =  nums[0];
        int high = 0;

        for(int num : nums) {
            low = max(low, num);
            high += num;
        }

        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(possible(mid, nums, k)) {
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