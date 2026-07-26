class Solution {
public:
    bool possible(int mid, vector<int> &bloomDay, int m, int k) {
        int count = 0;
        int result = 0;

        for(int x : bloomDay) {
            if(x <= mid) {
                count++;
            }
            else {
                result += (count / k);
                count = 0;
            }
        }

        result += (count / k);

        return result >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if((long long)m * k > n) return -1; 

        int low = bloomDay[0];
        int high = bloomDay[0];

        for(int num : bloomDay) {
            low = min(low, num);
            high = max(high, num); 
        }

        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(possible(mid, bloomDay, m, k)) {
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