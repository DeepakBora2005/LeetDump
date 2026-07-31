class Solution {
public:
    int candy(vector<int>& ratings) {
        sort(ratings.begin(), ratings.end());

        int n = ratings.size();
        int ans = 1;

        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i - 1]) {
                ans += ratings[i - 1] + 1;
            }
            else {
                ans++;
                continue;
            }
        }

        return ans;
    }
};