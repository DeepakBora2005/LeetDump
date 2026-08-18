class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        unordered_map<int, int> mp;
 
        int left = 0;
        int right = 0;
        int count = 1;

        while(right < n) {
            if(count == k) {
                unordered_map<int, int> seen;

                for(int i = left; i <= right; i++) {
                    if(seen[nums[i]] == 0) {
                        seen[nums[i]] = 1;
                        mp[nums[i]]++;
                    } 
                }
            }

            if(count == k) {
                right++;
                left++;
            }
            else {
                right++;
                count++;
            }
        }

        for(auto x : mp) {
            if(x.second == 1) {
                ans = max(ans, x.first);
            }
        }

        return ans;
    }
};