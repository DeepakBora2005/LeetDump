class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int low = 0;
        int hi

        vector<int> ans;

        for(int i = smallest; i <= largest; i++) {
            if(mp[i] == 0) ans.push_back(i);
        }

        return ans;
    }
};