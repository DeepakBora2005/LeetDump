class Solution {
public:
    bool possible(int mid, vector<int> &weights, int days) {
        int currentWeight = 0;
        int currentDays = 1;

        for(int weight : weights) {
            if(currentWeight + weight <= mid) {
                currentWeight += weight;
            }
            else {
                currentDays++;
                currentWeight = weight;
            }

            if(currentDays > days) return false;
        } 

        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = 1;
        int high = 0;

        for(int num : weights) {
            low = max(low, num);
            high += num;
        }

        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(possible(mid, weights, days)) {
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