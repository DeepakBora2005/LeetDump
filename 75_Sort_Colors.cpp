class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        int low = 0;    
        int high = n - 1;

        while(low < high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == 1) {
                low++;
                mid++;
            }
            else if(nums[mid] == 0) {
                low++;
            }
            else {
                high--;
            }
        }
    }
};