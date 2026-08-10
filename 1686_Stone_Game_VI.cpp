class Solution {
public:


    int stoneGameVI(vector<int>& alice, vector<int>& bob) {
        int n = alice.size();

        vector<pair<int, int>> nums;

        for(int i = 0; i < n; i++) {
            nums.push_back({alice[i] + bob[i], i});
        }

        sort(nums.rbegin(), nums.rend());

        int a = 0;
        int b = 0;

        for(int i = 0; i < nums.size(); i++) {
            int index = nums[i].second;

            if(i % 2 == 0) a += alice[index];
            else b += bob[index];
        }

        if(a > b) return 1;
        else if(a < b) return -1;

        return 0;
    }
};