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

        while(limit > 0 && left != right) {
            if(nums[left] > nums[left + 1]) {
                limit--;
                swap(nums[right], nums[left]);
            }

            left++;
        }

        return nums;
    }
};