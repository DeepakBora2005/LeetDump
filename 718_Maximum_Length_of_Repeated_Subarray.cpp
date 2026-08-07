class Solution {
public:
    int find(int i, int j, vector<int> &a, vector<int> &b, vector<vector<int>> &dp) {
        if(i == a.size() || j == b.size()) {
            return 0;
        }

        if(a[i] == b[j]) {
            return 1 + find(i + 1, j + 1, a, b, dp);
        }

        return max(find(i + 1, j, a, b, dp), find(i, j + 1, a, b, dp));
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
 
        return find(0, 0, nums1, nums2, dp);
    }
};