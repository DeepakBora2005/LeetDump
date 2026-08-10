class Solution {
public:
    int find(int index, int count, vector<int> &nums, vector<int> &prefix, vector<vector<int>> &dp) {
        if(index >= nums.size() || count == 1) return 0;

        int ans = 0;
        for(int i = index; i < nums.size(); i++) {
            int take = find(index + i + 1, count - i - 1, nums,prefix, dp) + prefix[i];

            ans = max(ans, take);
        }

        return ans;        
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefix(n, 0);
        prefix[0] = stoneValue[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = stoneValue[i] + prefix[i - 1];
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return find(0, n, stoneValue, prefix, dp);
    }
};