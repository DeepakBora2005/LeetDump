class Solution {
public: 
    int find(int i, int k, vector<int> &nums) {
        int n = nums.size();

        if(i == n) return 0;

        int maxi = INT_MIN;
        int len = 0;
        int ans = 0;

        for(int j = i; j < min(n, i + k); j++) {
            len++;
            maxi = max(maxi, nums[j]);
            int sum = (len * maxi) + find(j + 1, k, nums);

            ans = max(ans, sum);
        }

        return ans;
    }

    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        int n = nums.size();

        return find(0, k, nums);
    }
};