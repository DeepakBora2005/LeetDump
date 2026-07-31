class Solution {
public:
    bool possible(int mid, vector<int> &candies, long long k) {
        int count = 0;
        int prev = 0;

        for(int i = 0; i < candies.size(); i++) {
            if(((candies[i] + mid - 1) / mid) > prev) {
                count++;
                prev = ceil((double)candies[i] / mid);
            }
        }

        return count <= k;
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