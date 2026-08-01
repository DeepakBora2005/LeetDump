class Solution {
private:
    void find(vector<int> &row, int &maxArea) {
        stack<int> st;
        int n = row.size();

        for(int i = 0; i < n; i++) {
            while(!st.empty() && row[st.top()] >= row[i]) {
                int element = row[st.top()];
                st.pop(); 

                int nsi = i;
                int psi = st.empty() ? -1 : st.top();

                int area = (element) * (nsi - psi - 1);
                maxArea = max(area, maxArea);
            }

            st.push(i);
        }
    }

public:
    int maximalRectangle(vector<vector<char>>& nums) {
        int m = nums.size();
        int n = nums[0].size();

        int maxArea = 0;
        vector<int> height(n, 0);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(nums[i][j] == '1') height[j]++;
                else height[j] = 0;
            }

            find(height, maxArea);
        }

        return maxArea;
    }
};