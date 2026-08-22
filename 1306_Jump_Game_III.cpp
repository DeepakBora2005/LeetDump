class Solution {
public:
    bool find(int i, vector<int> &nums, vector<int> &dp, vector<int> &visited) {
        int n = nums.size();

        if(i < 0 || i >= n) return false;

        if(nums[i] == 0) return true;

        if(dp[i] != -1) return dp[i];

        if(visited[i]) return false;

        visited[i] = 1;

        for(int index = 1; index <= nums[i]; index++) {
            bool front = false;
            bool back = false;

            if(i + index < n) {
                front = find(i + index, nums, dp, visited);
            }
            if(i - index >= 0) {
                back = find(i - index, nums, dp, visited);
            }

            if(front || back) return dp[i] = true;
        }

        return dp[i] = false;
    }

    bool canReach(vector<int>& nums, int start) {
        int n = nums.size();

        vector<int> dp(n, -1);
        vector<int> visited(n, 0);

        return find(start, nums, dp, visited);
    }
};