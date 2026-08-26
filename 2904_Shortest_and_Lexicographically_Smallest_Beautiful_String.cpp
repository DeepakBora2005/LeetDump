class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();


        int left = 0;
        int right = 0;
        int count = 0;

        int ans = n + 1;
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

            while(count == k) {
                int len = right - left + 1;

                if((ans > len) || (ans == len && s.substr(left, len) < s.substr(start, ans))) {
                    ans = len;
                    start = left;
                    end = right;
                } 

                if(s[left] == '1') {
                    break;
                }

                left++;
            }

            right++;
        }

        if(ans == n) {
            return "";
        }

        for(int i = start; i <= end; i++) {
            result += s[i];
        }

        return result;
    }
};