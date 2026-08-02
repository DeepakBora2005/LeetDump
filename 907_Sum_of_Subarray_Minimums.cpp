class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;

        int n = arr.size();

        vector<int> nse(n, 1);
        vector<int> pse(n, 1);

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            int index = (st.empty()) ? -1 : st.top();

            pse[i] = i - index;

            st.push(i);
        }

        while(!st.empty()) {
            st.pop();
        }

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            int index = (st.empty()) ? n : st.top();

            pse[i] = index - i;
        }

        int mod = (int)1e9 + 7;
        int sum = 0;

        for(int i = 0; i < n; i++) {
            int temp = (pse[i] * nse[i] * arr[i]) % mod;
            sum += temp;
        }

        return sum;
    }
};