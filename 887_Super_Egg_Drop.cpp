class Solution {
public:
    int find(int mid, int k, int n) {
        vector<long long> dp(k + 1, 0);
        

        for(int i = 1; i <= mid; i++) {
            for(int j = k; j >= 1; j--) {
                dp[j] = 1 + dp[j] + dp[j - 1];

                if(dp[j] >= n) return true;
            }
        }

        return false;
    }

    int superEggDrop(int k, int n) {
        int low = 1;
        int high = n;
        int ans = n;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(find(mid, k, n)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};