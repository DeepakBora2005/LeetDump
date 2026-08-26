class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();


        int left = 0;
        int right = 0;
        int ans = n;
        int count = 0;

        int start = 0;
        int end = 0;
        
        string result = "";

        while(right < n) {
            if(s[right] == '1') {
                count++;
            }

            while(count > k) {
                if(s[left] == '1') {
                    count--;
                }

                left++;
            }

            if(count == k) {
                if(ans > right - left + 1) {
                    ans = right - left + 1;
                    start = left;
                    end = right;
                }
            }

            right++;
        }

        for(int i = left; i <= right; i++) {
            result += s[i];
        }

        return result;
    }
};