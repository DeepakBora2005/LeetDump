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
            else leftSum += num[i] - '0';

            if(num[n / 2 + i] == '?') rightCount++;
            else rightSum += num[n / 2 + i] - '0';
        }

        return 2 * (leftSum - rightSum) != 9 * (rightCount - leftCount);
    }
};