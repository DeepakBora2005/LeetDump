class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int low = INT_MAX;
        int high = INT_MIN;

        unordered_map<int, int> mp;

        for(int num : nums) {
            low = min(low, num);
            high = max(high, num);
            mp[num]++;
        }

        vector<int> ans;

        for(int i = low; i <= high; i++) {
            if(mp[i] == 0) ans.push_back(i);
        }

        return ans;
    }
};