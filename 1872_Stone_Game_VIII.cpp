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

        vector<int> prefix(n + 1, 0);

        for(int i = 0; i < n; i++) {
            prefix[i + 1] = stones[i] + prefix[i];
        }

        return find(0, stones, prefix);
    }
};