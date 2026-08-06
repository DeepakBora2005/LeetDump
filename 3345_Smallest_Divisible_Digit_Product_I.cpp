class Solution {
public:
    int find(int num) {
        int product = 1;

        while(num != 0) {
            product *= num % 10;

            num /= 10;
        }

        return product;
    }

    int smallestNumber(int n, int t) {
        while(find(n) % t != 0) {
            n++;
        } 

        return n;
    }
};