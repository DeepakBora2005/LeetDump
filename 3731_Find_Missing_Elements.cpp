class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int low = 0;
        int high = 0;

        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {
            if(low < nums[i]) low = nums[i];
            if(high > nums[i]) high = nums[i];
            mp[nums[i]]++;
        }

        vector<int> ans;

        for(int i = low; i <= high; i++) {
            if(mp[i] == 0) ans.push_back(i);
        }

        return ans;
    }
};