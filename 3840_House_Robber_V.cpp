class Solution {
public:
    long long find(int i, int j, vector<int> &a, vector<int> &b) {
        if(i == a.size() || j == b.size()) {
            return 0;
        }

        int skip = 0;
        if(a[i] == b[j]) {
            skip = find(i + 1, j, a, b);
        }

        int take = a[i] + find(i + 1, j + 1, a, b);

        return max(skip, take);
    }

    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();

        return find(0, 0, nums, colors);
    }
};