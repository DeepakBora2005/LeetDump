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

            while(count == k) {
                if(ans > right - left + 1) {
                    ans = right - left + 1;
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