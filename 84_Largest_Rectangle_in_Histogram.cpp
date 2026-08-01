class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        
        stack<int> st;

        int maxArea = 0;

        for(int i = 0; i <= n; i++) {
            while(!st.empty() && (i == n || h[st.top()] >= h[i])) {
                int element = h[st.top()];
                st.pop();

                int nsi = i;
                int psi = st.empty() ? -1 : st.top();

                int area = element * (nsi - psi - 1);
                maxArea = max(area, maxArea);
            }

            st.push(i);
        }

        return maxArea;
    }
};