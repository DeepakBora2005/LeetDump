class Solution {
public:
    char repeatedCharacter(string s) {
        int n = s.size();

        unordered_set<char> visited;

        for(int i = 0; i < n; i++) {
            if(visited.count(s[i])) return s[i];
            visited.insert(s[i]);
        }

        return ' ';
    }
};