class Solution {
private: 
    int dp[20][20][2];

    int find(vector<int> &nums, int start, int end, int turn) {
        if(start == end) {
            return (turn == 0) ? nums[start] : 0;
        }
            
        if(dp[start][end][turn] != -1) {
            return dp[start][end][turn];
        }

        if(turn == 0) {
            int leftMost = nums[start] + find(nums, start + 1, end, 1);
            int rightMost = nums[end] + find(nums, start, end - 1, 1);

            return dp[start][end][turn] = max(leftMost, rightMost);
        }
        else 
        {
            int leftMost = find(nums, start + 1, end, 0);
            int rightMost = find(nums, start, end - 1, 0);

            return dp[start][end][turn] = min(leftMost, rightMost);
        }
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int num : nums) {
            totalSum += num;
        }

        memset(dp, -1, sizeof(dp));

        int player1 = find(nums, 0, n - 1, 0);
        int player2 = totalSum - player1;

        return player1 >= player2;
    }
};