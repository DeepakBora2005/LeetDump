class Solution {
public:
    bool possible(int mid, vector<int> &candies, long long k) {
        long long sum = 0;

        for(int i = 0; i < candies.size(); i++) {
            sum += (candies[i] + mid - 1) / mid;
        }

        return sum <= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();

        sort(candies.begin(), candies.end());

        int low = 1;
        int high = candies.back();

        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(possible(mid, candies, k)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};