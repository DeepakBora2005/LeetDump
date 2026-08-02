class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        int n = s.size();

        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;   
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int ans = 0;

        for(int i = 0; i < n; i++) {
            ans += mp[s[i]];
        }

        return ans;
    }
};