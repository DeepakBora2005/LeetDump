class Solution {
public:
    void find(int index, string &digits, unordered_map<char, string> &mp, string &temp, vector<string> &result){
        if(index == digits.size()){
            result.push_back(temp);
            return;
        }

        string letters = mp[digits[index]];

        for(char ch : letters) {
            temp.push_back(ch);

            find(index + 1, digits, mp, temp, result);

            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        
        vector<string> result;
        string temp;

        find(0, digits, mp, temp, result);

        return result;
    }
};