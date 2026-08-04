class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int low = 0;
        int high = 0;

        unordered_map<int, int> mp;

        for(int num : nums) {
            if(low < num) low = num;
            if(high > num) high = num;
            mp[num]++;
        }

        vector<int> ans;

        for(int i = low; i <= high; i++) {
            if(mp[i] == 0) ans.push_back(i);
        }

        return ans;
    }
};