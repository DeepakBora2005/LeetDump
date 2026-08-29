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
            if(right - 1 >= left) {
                if(nums[right - 1] > nums[right]) {
                    swap(nums[right - 1], nums[right]);
                }
            }

            right--;
        }

        return nums;
    }
};