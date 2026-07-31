class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = 0;

        vector<int> store(n, 1);

        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i - 1]) {
                store[i] = store[i - 1] + 1;
            } 
        }

        for(int i = n - 2; i >= 0; i--) {
            store[i] = max(store[i], store[i + 1] + 1);
        }

        for(int num : ratings) {
            ans += num;
        }

        return ans;
    }
};