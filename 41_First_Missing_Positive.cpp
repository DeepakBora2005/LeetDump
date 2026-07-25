class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int totalSum = n * (n + 1) / 2;
        int sum = 0;
        int arr[n + 1];
        int ans;

        for(int i = 0; i < n; i++) {
            if(nums[i] < 1 || nums[i] > n) {
                nums[i] = 0;
            }
            else {
                arr[nums[i]] = 1;
                sum += nums[i];
            }
        }

        for(int i = 1; i <= n; i++) {
            if(arr[i] == 0) {
                ans = i;
            } 
        }

        return ans;
    }
};