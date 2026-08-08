class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        int low = 0;
        int high = n - 1;

        int ans = 0;

        for(int i = n - 1; i >= 0; i--) {
            int temp = citations[i]; 

            if(n - i >= temp) {
                ans = citations[i];
                break;
            }
        }

        return ans;
    }
};