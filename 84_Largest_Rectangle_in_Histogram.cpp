class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();

        stack<int> st;

        int maxArea = INT_MIN;
        
        for(int i = 0; i <= n; i++) {
            int currentHeight = (i == n) ? 0 : h[i];

            while(!st.empty() && h[st.top()] >= currentHeight) {
                int height = h[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }


            st.push(i);
        }

        return maxArea;
    }
};