class Solution {
public:
    int find(int index, int n, vector<int> &cost) {
        if(index >= n) return 0;

        return cost[index] + min(find(index + 1, n, cost), find(index + 2, n, cost));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        return min(find(0, n, cost), find(1, n, cost));
    }
};