class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mini = 0;
        int maxi = 0;
        int minIndex = 0;
        int maxIndex = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] < mini) {
                minIndex = i;
                mini = nums[i];
            }

            if(nums[i] > maxi) {
                maxIndex = i;
                maxi = nums[i];
            }
        }

        int first = (maxIndex - 0 + 1) + (minIndex - 0 + 1);
        int second = (n - maxIndex) + (n - minIndex);
        int third = (minIndex - 0 + 1) + (n - maxIndex);

        return max(first, max(second, third));
    }
};