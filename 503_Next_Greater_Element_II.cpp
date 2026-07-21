class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        stack<int> st;

        vector<int> temp(2 * n);

        int k = 0;
        for(int i = 0; i < 2 * n; i++) {
            if(k == n) {
                k = k % n; 
            }
            temp[i] = nums[k++];
        }

        vector<int> ans(n, -1);

        for(int i = 2 * n - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= temp[i % n]) {
                st.pop();
            }

            if(i < n) {
                if(!st.empty()) ans[i] = st.top();
            }
            
            st.push(temp[i % n]);
        }

        return ans;
    }
};