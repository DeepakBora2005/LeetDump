class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int first = nums[0];
        int second = nums[0];

        for(int i = 1; i < n; i++) {
            if(nums[i] >= first) {
                second = first;
                first = nums[i];
            }
            if(nums[i] < first && nums[i] > second) {
                second = nums[i];
            }
        }

        return (first - 1) * (second - 1);
    }
};