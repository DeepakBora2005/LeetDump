class Solution {
public:
    bool find(int n, int x) {
        if(n < x) return false;

        return !find(n - x, x - 1);
    }

    bool canAliceWin(int n) {
        return find(n, 10);
    }
};