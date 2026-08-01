class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        
        stack<int> st;

        int maxArea = 0;

        for(int i = 0; i <= n; i++) {
            int current = (i == n) ? 0 : h[i];
            while(!st.empty() && h[st.top()] >= current) {
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