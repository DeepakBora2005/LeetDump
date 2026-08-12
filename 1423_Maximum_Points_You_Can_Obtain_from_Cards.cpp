class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();

        int leftSum = 0;
        int rightSum = 0;

        int ans = 0;

        for(int i = 0; i < k; i++) {
            leftSum += nums[i];
        }

        ans = max(ans, leftSum);

        int rightIndex = n - 1;
        for(int j = k - 1; j >= 0; j--) {
            leftSum -= nums[j];
            rightSum += nums[rightIndex];
            rightIndex--;

            ans = max(ans, leftSum + rightSum);
        }

        return ans;
    }
};