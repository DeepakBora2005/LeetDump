class Solution {
public:
    void find(int i, string curr, string &s, unordered_set<string> &st) {
        if(i == s.size()) {
            if(!st.empty()) {
                st.insert(curr);
            }
            return;
        }

        find(i + 1, curr + s[i], s, st);
        
        find(i + 1, curr, s, st);        
    }

    int distinctSubseqII(string s) {
        int n = s.size();

        const int mod = 1e9 + 7;

        unordered_set<string> st;

        find(0, "", s, st);

        int ans = st.size();
        ans = ans % mod;

        return ans;
    }
};