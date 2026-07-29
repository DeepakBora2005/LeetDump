class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();

        stack<int> st;
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);

        for(int i = 0; i < n; i++) {
            while(!st.empty() && h[st.top()] >= h[i]) {
                st.pop();
            }

            st.empty() ? prefix[i] = -1 : prefix[i] = st.top();

            st.push(i);
        }

        while(!st.empty()) {
            st.pop();
        }

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && h[st.top()] >= h[i]) {
                st.pop();
            }

            st.empty() ? prefix[i] = n : prefix[i] = st.top();

            st.push(i);
        }

        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            int width = suffix[i] - prefix[i] -1;
            int area = h[i] * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};