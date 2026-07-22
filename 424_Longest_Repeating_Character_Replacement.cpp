class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> hash(n, 0);

        int maxLen = 0;

        for(int i = 0; i < n; i++) {
            int maxFreq = 0;

            for(int j = i; j < n; j++) {
                hash[s[j] - 'A']++;
                maxFreq = max(maxFreq, hash[j]);
                int changes = (j - i + 1) - maxFreq;

                if(changes <= k) {
                    maxLen = max(maxLen, (j - i + 1));
                }
                else {
                    break;
                }
            }
        }

        return maxLen;
    }
};