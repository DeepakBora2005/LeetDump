class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int left = 0;
        int right = 0;

        int ans = 0;

        unordered_set<int> st;
 
        while(right < n) {
            st.insert(fruits[right]);

            while(st.size() > 2) {
                st.erase(fruits[left]);
                left++;
            }
            
            ans = max(ans, right - left + 1);

            right++;
        }

        return ans;
    }
};