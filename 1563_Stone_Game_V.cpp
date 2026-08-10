class Solution {
public:
    int find(int index, vector<int> &nums, vector<int> &prefix, vector<vector<int>> &dp) {
        if(index >= nums.size()) return 0;

        int ans = 0;
        for(int i = index; i < nums.size(); i++) {
            int ans = find(index + i + 1, nums, prefix, dp);

            ans = min(ans, prefix[index]);
        }

        return ans;        
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);
        prefix[0] = stoneValue[0];

        for(int i = n - 1; i >= 0; i--) {
            prefix[i] = stoneValue[i] + prefix[i + 1];
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return find(0, stoneValue, prefix, dp);
    }
};