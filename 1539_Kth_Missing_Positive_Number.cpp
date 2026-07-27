class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        int n = arr.size();

        for(int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }

        int ans = 0;

        for(int i = 1; i <= 1000; i++) {
            if(mp[i] == 0) k--;

            if(k == 0) ans = i;
        }

        return ans;
    }
};