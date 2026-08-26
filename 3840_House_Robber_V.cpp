class Solution {
public:
    long long find(int i, vector<int> &a, vector<int> &b, vector<int> &dp) {
        if(i >= a.size()) return 0;

        if(dp[i] != - 1) return dp[i];

        long long skip = find(i + 1, a, b, dp);

        long long take = 0;

        if(i + 1 < a.size() && b[i] == b[i + 1]) {
            take = a[i] + find(i + 2, a, b, dp);
        }
        else {
            take = a[i] + find(i + 1, a, b, dp);
        }
        
        return dp[i] = max(skip, take);
    }

    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();

        vector<int> dp(n, -1);

        return find(0, nums, colors, dp);
    }
};