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
        int left = 0;
        int right = 0;

        while(right < n) {
            if(temp[right] <= k) {
                ans = max(ans, (right - left) + 1);
            }
            else if(temp[right] > k) {
                left = right;
                ans = max(ans, (right - left) + 1);
            }

            right++;
        }

        return ans;
    }
};