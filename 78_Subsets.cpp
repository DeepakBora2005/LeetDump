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
        vector<int> temp;

        find(0, n, nums, temp, result);

        return result;
    }
};