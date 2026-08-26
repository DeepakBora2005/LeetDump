class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        
        bool hasNonZero = false;
        int curr = 0;

        for(int i = 0; i < n; i++) {
            curr ^= nums[i];
            
            if(nums[i] != 0) hasNonZero = true;
        }

        if(curr != 0) return n;

        if(hasNonZero) return n - 1;

        return 0;
    }
};