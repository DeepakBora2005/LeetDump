class Solution {
public:
    long long find(int i, vector<int> &a, vector<int> &b, vector<long long> &dp) {
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

        vector<long long> dp(n + 2, 0);

        for(int i = n - 1; i >= 0; i--) {
            long long skip = dp[i + 1];

            long long take = 0;
            
            if(i + 1 < n && colors[i] == colors[i + 1]) {
                take = nums[i] + dp[i + 2];
            }
            else {
                take = nums[i] + dp[i + 1];
            }

            dp[i] = max(skip, take);
        }

        return dp[0];
    }
};