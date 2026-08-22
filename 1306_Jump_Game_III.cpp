class Solution {
public:
    bool find(int i, vector<int> &nums, vector<int> &visited) {
        int n = nums.size();

        if(i < 0 || i >= n) return false;

        if(nums[i] == 0) return true;

        if(visited[i]) return false;

        visited[i] = 1;

        int jump = nums[i];

        if(find(i + jump, nums, visited)) return true;

        if(find(i - jump, nums, visited)) return true;

        return false;
    }

    bool canReach(vector<int>& nums, int start) {
        int n = nums.size();

        vector<int> visited(n, 0);

        return find(start, nums, visited);
    }
};