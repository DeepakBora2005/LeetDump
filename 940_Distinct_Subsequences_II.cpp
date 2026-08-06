class Solution {
public:
    long long find(int i, string &s) {
        if(i == s.size()) return 0;

        return 1 + find(i + 1, s);
    }

    int distinctSubseqII(string s) {
        int n = s.size();

        long long ans = 0;

        const int mod = 1e9 + 7;

        for(int i = 0; i < n; i++) {
            ans = max(ans, find(i, s));
            ans = ans % mod;
        }

        return ans;
    }
};