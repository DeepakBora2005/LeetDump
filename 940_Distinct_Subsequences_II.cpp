class Solution {
public:
    int find(int i, string &s) {
        if(i == s.size()) return 0;

        return 1 + find(i + 1, s);
    }

    int distinctSubseqII(string s) {
        int n = s.size();

        return find(0, s);
    }
};