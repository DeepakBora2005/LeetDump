class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int smallest = nums[0];
        int largest = nums[0];

        unordered_map<int, int> mp;

        for(int i = 1; i < nums.size(); i++) {
            if(smallest < nums[i]) smallest = nums[i];
            else if(largest > nums[i]) largest = nums[i];
            mp[nums[i]]++;
        }

        vector<int> ans;

        for(int i = smallest; i <= largest; i++) {
            if(mp[i] == 0) ans.push_back(i);
        }

        return ans;
    }
};