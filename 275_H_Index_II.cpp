class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        int low = 0;
        int high = n - 1;

        int ans = 0;

        for(int i = 0; i < n; i++) {
            int papers = n - i;

            if(citations[i] >= papers) {
                ans = papers;
                break;
            }
        }

        return ans;
    }
};