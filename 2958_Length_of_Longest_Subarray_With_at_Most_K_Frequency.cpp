class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int n = nums.size();

        int ans = 0;
        int left = 0;
        int right = 0;

        while(right < n) {
            mp[nums[right]]++;

            while(mp[nums[right]] > k) {
                mp[nums[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);

            right++;
        }

        return ans;
    }
};