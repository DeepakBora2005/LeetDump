class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int leftCount = 0;
        int rightCount = 0;
        int leftSum = 0;
        int rightSum = 0;

        for(int i = 0; i < n / 2; i++) {
            if(num[i] == '?') leftCount++;
            else if(num[i] != '?') leftSum += (int)num[i];

            if(num[n / 2 + i] == '?') rightCount++;
            else if(num[n / 2 + i] != '?') rightSum += (int)num[n / 2 + i];
        }

        if(abs(rightCount - leftCount) == 0) {
            if(leftSum == rightSum) return true;
        }

        if(abs(rightCount - leftCount) > 0) return true;


        return false;
    }
};