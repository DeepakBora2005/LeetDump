class Solution {
public:
    void find(int i, int j, string &s, string &t, vector<int> &ans) {
        int m = s.size();
        int n = t.size();

        if(i == m) {
            return;
        }

        if(s[i] == t[j]) {
            ans.push_back(i);
            find(i + 1, j + 1, s, t, ans);
            ans.pop_back();
        }

        find(i + 1, j, s, t, ans);
    }

    vector<int> validSequence(string word1, string word2) {
        vector<int> ans;

        find(0, 0, word1, word2, ans);

        return ans;
    }
};