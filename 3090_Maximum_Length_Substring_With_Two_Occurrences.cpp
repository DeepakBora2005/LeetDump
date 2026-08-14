class Solution {
public:
      int maximumLengthSubstring(string s) {
        int n = s.size();

        unordered_map<int, int> mp;

        int ans = 0;
                
        int left = 0;   
        int right = 0;      

        while(right < n) {
            mp[s[right]]++;

            while(mp[s[right]] > 2) {
                mp[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);

            right++;
        }

        return ans;
    }
};