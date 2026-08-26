class Solution {
public:
    void find(int index, int n, vector<int> &nums, vector<int> &temp, vector<vector<int>> &result) {
        if(index == n) {
            result.push_back(temp);
            return;
        }
        
        temp.push_back(nums[index]);
        find(index + 1, n, nums, temp, result);
        temp.pop_back();
        find(index + 1, n, nums, temp, result);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;

        for(int mask = 0; mask < (1 << n); mask++) {
            vector<int> temp;
            
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    temp.push_back(nums[i]);
                }
            }

            result.push_back(temp);
        }

        return result;
    }
};