class Solution {
public:
    int find(int i, int j, vector<int> &cuts) {
        if(i > j) return 0;

        int ans = INT_MAX;
        for(int index = i; index <= j; index++) {
            int cost = cuts[j + 1] - cuts[i - 1] + find(i, index - 1, cuts) + find(index + 1, j, cuts);

            ans = min(ans, cost);
        }

        return ans;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        sort(cuts.begin(), cuts.end());

        int c = cuts.size();

        return find(1, c - 2, cuts);
    }
};