class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i - 1] + 1) sum += nums[i];
            else break;
        }

        unordered_set<int> st(nums.begin(), nums.end());

        int ans = sum;

        while(st.count(ans)) {
            ans++;
        }

        return ans;
    }
};