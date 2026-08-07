class Solution {
public:
    int find(int i, int j, vector<int> &a, vector<int> &b, int &ans,vector<vector<int>> &dp) {
        if(i == a.size() || j == b.size()) {
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int count = 0;
        if(a[i] == b[j]) {
            count = 1 + find(i + 1, j + 1, a, b, ans, dp);
        }

        ans = max(ans, count);

        find(i + 1, j, a, b, ans, dp);
        find(i, j + 1, a, b, ans, dp);

        return dp[i][j] = count;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int maxCount = 0;
        int ans = 0;
 
        find(0, 0, nums1, nums2, ans, dp);

        return ans;
    }
};