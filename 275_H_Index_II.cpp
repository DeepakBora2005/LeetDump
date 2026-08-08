class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        int low = 0;
        int high = n - 1;

        int ans = 0;

        while(low < high) {
            int mid = low + (high - low) / 2;

            if(citations[mid] > mid) {
                high = mid;
                ans = (high - mid - 1);
            }
            else if(citations[mid] <= mid) {
                low = mid + 1;
            }
        }

        return ans;
    }
};