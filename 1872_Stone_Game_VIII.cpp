class Solution {
public:
    int find(int index, vector<int> &prefix) {
        int n = prefix.size();

        if(index == n - 1) {
            return prefix[index];
        }

        int next = find(index + 1, prefix);

        return max(next, prefix[index] - next);
    }

    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> prefix(n);

        prefix[0] = stones[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = stones[i] + prefix[i - 1];
        }

        return find(1, prefix);
    }
};