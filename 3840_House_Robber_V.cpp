class Solution {
public:
    long long find(int i, vector<int> &a, vector<int> &b) {
        if(i >= a.size()) return 0;

        long long skip = find(i + 1, a, b);

        long long take = 0;

        if(i + 1 < a.size() && b[i] == b[i + 1]) {
            take = a[i] + find(i + 2, a, b);
        }
        else {
            take = a[i] + find(i + 1, a, b);
        }
        
        return max(skip, take);
    }

    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();

        return find(0, nums, colors);
    }
};