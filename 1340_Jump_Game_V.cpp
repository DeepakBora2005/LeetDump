class Solution {
public:
    int maxJumps(vector<int>& nums, int d) {
        int n = nums.size();
        vector<pair<int, int>> temp;

        for(int i = 0; i < n; i++) {
            temp.push_back({nums[i], i});
        }

        sort(temp.rbegin(), temp.rend());

        int ans = 1;

        for(int i = 0; i < n - 1; i++) {
            int index = temp[i].second;
            int count = 1;

            for(int j = i + 1; j < n; j++) {
                if(temp[j].second < index) count++;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};