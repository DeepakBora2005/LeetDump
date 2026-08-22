class Solution {
public:
    bool checkDivisibility(int n) {
        int temp, sum = 0, product = 1;
        int m = n;

        while(m > 0) {
            temp = m % 10;

            sum += temp;
            product *= temp;

            m = m / 10;
        }

        if(n % (sum + product) == 0) return true;
        

        return false;
    }
};
