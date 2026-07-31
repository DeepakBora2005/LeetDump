class Solution {
public:
    int candy(vector<int>& ratings) {
        sort(ratings.begin(), ratings.end());

        int n = ratings.size();
        int prev = 1;
        int temp = 1;
        int ans = 1;

        for(int i = 1; i < n; i++) {
            if(ratings[i] != ratings[i - 1]) {
                temp++;
                ans += temp;
                prev = temp;
            }
            else {
                ans++;
                continue;
            }
        }

        return ans;
    }
};