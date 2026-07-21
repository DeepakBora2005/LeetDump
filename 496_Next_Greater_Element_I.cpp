class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;

        int m = nums2.size();

        vector<int> temp(m, -1);

        for(int i = m - 1; i >= 0; i--) {
            mp[nums2[i]] = i;
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if(!st.empty()) {
                temp[i] = st.top();
            }
           
            st.push(nums2[i]); 
        }

        int n = nums1.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            int index = mp[nums1[i]];
            ans[i] = temp[index];
        }
        
        return ans;
    }
};