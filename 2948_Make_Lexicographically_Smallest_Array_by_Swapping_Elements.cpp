class Solution {
public:
    void swapElements(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        int right = n - 1;
        int left = 0;

        while(limit > 0 && right != left) {
            if(nums[right] < nums[left]) {
                limit--;
                swapElements(&nums[right], &nums[left]);
            }

            right--;
        }

        return nums;
    }
};