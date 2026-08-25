class Solution {
public:
    bool find(int n) {
        if(n == 0) return false;

        for(int i = 0; i < n; i++) {
            if(find(n - (n - i)) == false) {
                return true;
            } 
        }

        return false;
    }

    bool canAliceWin(int n) {
        if(n < 10) return false;
        else if(n == 10) return true;

        return find(n);
    }
};