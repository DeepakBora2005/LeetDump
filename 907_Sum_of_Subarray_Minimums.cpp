class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int mod = 1e9 + 7;

        int n = arr.size();

        long long ans = 0;

        for(int i = 0; i <= n; i++) {
            while(!st.empty() && (i == n || arr[st.top()] >= arr[i])) {
                int index = st.top();
                st.pop();
                
                int left = (st.empty()) ? -1 : st.top();
                int right = i;

                long long leftCount = index - left;
                long long rightCount = right - index;

                ans = (ans + (long long)leftCount * rightCount * arr[index]) % mod;
            }

            st.push(i);
        }

        return ans;
    }
};