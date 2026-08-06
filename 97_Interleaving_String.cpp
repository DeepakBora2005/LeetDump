class Solution {
public:
    void find(int i, string &curr, string &s, unordered_set<string> &st) {
        if(i == s.size()) {
            if(!curr.empty()) {
                st.insert(curr);
            }
            return;
        }

        curr.push_back(s[i]);
        find(i + 1, curr, s, st);
        curr.pop_back();
        
        find(i + 1, curr, s, st);        
    }

    int distinctSubseqII(string s) {
        int n = s.size();

        const int mod = 1e9 + 7;

        unordered_set<string> st;

        string curr = "";

        find(0, curr, s, st);

        int ans = st.size() % mod;

        return ans;
    }
};