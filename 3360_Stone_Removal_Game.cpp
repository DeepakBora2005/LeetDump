class Solution {
public:
    bool find(int n, int x) {
        if(n == 0 || n < x) return false;

        for(int i = x; i > 0; i--) {
            if(find(n - x, x - 1) == false) {
                return true;
            }
        }

        return false;
    }

    bool canAliceWin(int n) {
        return find(n, 10);
    }
};