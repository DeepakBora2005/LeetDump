class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();

        stack<int> st;

        for(int i = 0; i < n; i++) {
            bool destroyed = false;

            while(!st.empty() && st.top() > 0 && ast[i] < 0) {
                int left = abs(st.top());
                int right = abs(ast[i]);

                if(left == right) {
                    st.pop();
                    destroyed = true;
                    break;
                }
                else if(left < right) {
                    st.pop();
                }
                else {
                    destroyed = true;
                    break;
                }
            }

            if(!destroyed) {
                st.push(ast[i]);
            }
        }

        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};