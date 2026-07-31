class Solution {
public:
    bool possible(int mid, vector<int> &candies, long long k) {
        long long count = 0;

        for(int i = 0; i < candies.size(); i++) {
            count += (floor((double)candies[i] / mid));
        }

        return count >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();

        int low = 1;
        int high = 0;

        for(int num : candies) {
            high = max(high, num);
        }

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