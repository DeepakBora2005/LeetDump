class Solution {
public:
    int find(int i, int j, vector<int> &nums) {
        int n = nums.size();

        if(i > j) return 0;

        int ans = 0;
        for(int k = i; k <= j; k++) {
            int cost =  nums[i - 1] * nums[k] * nums[j + 1] + find(i, k - 1, nums) + find(k + 1, j, nums);

            ans = max(ans, cost);
        }

        return ans;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        return find(1, n - 2, nums);
    }
};