class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int left = 0;
        int right = 0;
        
        int ans = 0;

        int count = 0;
        while(right < n) {
            if(nums[right] == 0) {
                count++;
            }

            while(count > k) {
                if(nums[left] == 0) {
                    count--;
                } 

                left++;
            }

            ans = max(ans, right - left + 1);
 
            right++;
        }

        return ans;
    }
};