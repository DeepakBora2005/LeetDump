class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<int, int> arr;

        int n = s.size();

        for(int i = 0; i < n; i++) {
            arr[int(s[i])]++;
        }

        unordered_map<int, int> mp;

        for(auto &num : arr) {
            mp[num.second]++;
        }

        char ans;
        for(int i = 0; i < n; i++) {
            if(mp[arr[i]] == 2) ans = s[i]; 
        }

        return ans;
    }
};