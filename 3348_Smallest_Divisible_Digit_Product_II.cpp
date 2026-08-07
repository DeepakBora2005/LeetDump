class Solution {
public:
    string smallestNumber(string num, long long t) {
        string temp = num;
        int prod = 1;

        int x = stoi(num);

        while(x != 0) {
            prod *= (x % 10);

            x /= 10;
        }

        long long c1, c2, c3, c4;

        while(t % 2 == 0) {
            c1++;
            t /= 2;
        }

        while(t % 3 == 0) {
            c2++;
            t /= 3;
        }

        while(t % 5 == 0) {
            c3++;
            t /= 5;
        }

        while(t % 7 == 0) {
            c4++;
            t /= 7;
        }

        if(t != 1) return "-1";

        if(prod % 2 == 0) return num;

        return "-1";
    }
};