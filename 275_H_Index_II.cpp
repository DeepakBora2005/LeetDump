class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        int low = 0;
        int high = n - 1;

        int ans = 0;

        for(int i = 0; i < n; i++) {
            int temp = citations[i];

            if(n - i > temp) continue;
            else if(n - i == temp) ans = n - i;
        }

        return ans;
    }
};