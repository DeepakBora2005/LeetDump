class Solution {
public:
    bool find(int i, int j, int changed, string &s, string &t, vector<int> &ans) {
        int m = s.size();
        int n = t.size();

        if(i == m) {
            return false;
        }

        if(j == n) {
            return true;
        }

        if(s[i] == t[j]) {
            ans.push_back(i);
            if(find(i + 1, j + 1, changed, s, t, ans)) {
                return true;
            }
            ans.pop_back();
        }
        else if(changed == 0) {
            ans.push_back(i);
            if(find(i + 1, j + 1, 1, s, t, ans)) {
                return true;
            }
            ans.pop_back();
        }

        if(find(i + 1, j, changed, s, t, ans)) {
            return true;
        }

        return false;
    }

    vector<int> validSequence(string word1, string word2) {
        vector<int> ans;

        find(0, 0, 0, word1, word2, ans);

        return ans;
    }
};