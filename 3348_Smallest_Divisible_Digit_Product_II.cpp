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

        if(prod % 2 == 0) return num;

        return "-1";
    }
};