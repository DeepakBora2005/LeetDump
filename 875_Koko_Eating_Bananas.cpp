class Solution {
public:
    bool possible(int mid, vector<int> &piles, int h) {
        long long sum = 0;

        for(int pile : piles) {
            if(sum > h) break;
            sum += ceil(pile / mid);
        }

        if(sum <= h) return true;

        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 1;
        int n = piles.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            high = max(high, piles[i]);
        }

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(possible(mid, piles, h)) {
                ans = mid;
                high = mid - 1;
            }
            else  {
                low = mid + 1;
            }
        }

        return ans;
    }
};