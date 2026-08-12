class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastSeen[3] = {-1, -1, -1};
        int ans = 0;

        int n = s.size();

        for(int i = 0; i < n; i++) {
            lastSeen[s[i] - 'a'] = i;

            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                int mini = min(lastSeen[0], min(lastSeen[1], lastSeen[2]));

                ans += mini + 1;
            } 
        }

        return ans;
    }
};