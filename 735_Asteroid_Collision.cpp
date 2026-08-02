class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();

        stack<int> st;
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            if(ast[i] < 0 && st.empty()) {
                continue;
            }
            else if(ast[i] < 0 && st.empty()) {
                int last = st.top();

                int left = abs(last);
                int right = abs(ast[i]);

                if(left > right) {
                    continue;
                }
                else if(left == right) {
                    st.pop();
                    continue;
                }
                else {
                    while(left < right && !st.empty()) {
                        st.pop();
                        if(st.empty()) break;
                        int temp = st.top();
                        left = abs(temp);
                    }
                    
                    if(st.empty()) st.push(ast[i]);
                }
            }

            if(ast[i] > 0) {
                st.push(ast[i]);
            }
        }

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};