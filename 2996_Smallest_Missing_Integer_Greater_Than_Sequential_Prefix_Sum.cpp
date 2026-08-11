class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int,int> mp;

        int n = nums.size();

        for(int num : nums) {
            mp[num]++;
        }

        vector<int> prefix(n, 0);
        prefix[0] = nums[0];

        int ans = INT_MAX;

        for(int i = 1; i < n; i++) {
            prefix[i] = nums[i] + prefix[i - 1];

            if(prefix[i] > ans) ans = prefix[i];
        }

        return ans;
    }
};