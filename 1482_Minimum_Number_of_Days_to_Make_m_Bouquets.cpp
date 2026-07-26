class Solution {
public:
    bool possible(int mid, vector<int> &bloomDay, int k, int m) {
        long long sum = 0;
        int count = 0;

        vector<int> visited(bloomDay.size(), -1);

        for(int i = 0; i < bloomDay.size(); i++) {
            if(bloomDay[i] <= mid) {
                visited[i] = 1;
            }
        }

        long long temp = 0;
        long long result = 0;
        for(int i = 0; i < bloomDay.size(); i++) {
            sum += temp;

            if(visited[i] != 1) {
                if(sum >= k) result += temp / k;
                else count = 0;
            }
            if(visited[i] == 1) {
                count++;
            }
            
            temp = count;  
        }

        if(result < m) return false;

        return true;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        int low = 1;
        int high = 1;

        for(int num : bloomDay) {
            low = min(low, num);
            high = max(high, num); 
        }

        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(possible(mid, bloomDay, k, m)) {
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