class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int left = 0;
        int right = 0;
        
        int ans = 0;

        unordered_map<char, int> mp;

        while(right < n) {
            mp[s[right]]++;

            while(mp[s[left]] > 1) {
                mp[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);

            right++;
        }


        return ans;
    }
};