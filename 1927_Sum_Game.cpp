class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int leftCount = 0;
        int rightCount = 0;

        for(int i = 0; i < n / 2; i++) {
            if(num[i] == '?') leftCount++;
            if(num[n / 2 + i] == '?') rightCount++;
        }

        if(abs(rightCount - leftCount) > 0) return true;


        return false;
    }
};