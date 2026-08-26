class Solution {
public:
    bool possible(int mid, vector<int> &arr, int m) {
        int count = 1;
        int prev = 0;

        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] - arr[prev] >= mid) {
                count++;
                prev = i;
            }

            if(count == m) return true;
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        int n = position.size();

        sort(position.begin(), position.end());

        int low = 1;    
        int high = (position.back() - position.front());

        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(possible(mid, position, m)) {
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