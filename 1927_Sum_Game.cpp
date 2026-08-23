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
            else leftSum += (int)num[i];

            if(num[n / 2 + i] == '?') rightCount++;
            else rightSum += (int)num[n / 2 + i];
        }

        return leftSum - rightSum != 9 * (rightCount - leftCount) / 2;
    }
};