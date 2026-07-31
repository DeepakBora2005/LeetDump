class Solution {
public:
    int candy(vector<int>& ratings) {
        sort(ratings.begin(), ratings.end());

        int n = ratings.size();
        int ans = 1;
        int prev = 1;

        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i - 1]) {
                if(ratings[i - 1] == 0) {
                    int temp = 1;
                    ans += (temp + 1);
                    prev = temp;
                }
                else {
                    ans += (ratings[i - 1] + 1);
                    prev = ratings[i - 1];
                }
            }
            else {
                ans += prev;
            }
        }

        return ans;
    }
};