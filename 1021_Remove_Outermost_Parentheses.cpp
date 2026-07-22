class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;

        string ans = "";

        int n = s.size();

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                if(!st.empty()) {
                    ans += s[i];
                }

                st.push(s[i]);
            }
            else {
                st.pop();

                if(!st.empty()) {
                    ans += s[i];
                }
            }
        }

        return ans;
    }
};