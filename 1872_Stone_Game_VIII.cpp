class Solution {
public:
    int find(int index, vector<int> &nums, vector<int> &prefix) {
        int n = nums.size();

        if(index == n - 1) {
            return prefix[index];
        }

        int ans = INT_MIN;

        for(int j = index + 1; j < n; j++) {
            ans = max(ans, prefix[index] - find(j, nums, prefix));
        }

        return ans;
    }

    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> prefix(n, 0);

        prefix[0] = stones[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = stones[i] + prefix[i - 1];
        }

        return find(1, stones, prefix);
    }
};