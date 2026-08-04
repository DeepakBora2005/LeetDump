class Solution {
public:
    void find(vector<int> &nums, vector<bool> &visited, vector<int> &temp, vector<vector<int>> &result) {
        if(temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(visited[i]) continue;

            visited[i] = true;
            temp.push_back(nums[i]);

            find(nums, visited, temp, result);

            temp.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);

        find(nums, visited, temp, result);

        return result;
    }
};