class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int n = nums.size();

        vector<int> temp(n, 0);

        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;

            temp[i] = mp[nums[i]];
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(temp[i] <= k) {
                ans = max(ans, i + 1);
            }
        }

        return ans;
    }
};