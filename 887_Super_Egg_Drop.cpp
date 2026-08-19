class Solution {
public:
    int find(int k, int n) {
        if(n == 0)
            return 0;

        if(k == 1)
            return n;

        int ans = INT_MAX;

        for(int x = 1; x <= n; x++) {
            int take = find(k - 1, x - 1);
            int notTake = find(k, n - x);

            int temp = 1 + max(take, notTake);

            ans = min(ans, temp);
        }

        return ans;
    }

    int superEggDrop(int k, int n) {
        return find(k, n);
    }
};