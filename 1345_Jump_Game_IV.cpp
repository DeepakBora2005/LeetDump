class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) {
            return 0;
        }

        unordered_map<int, vector<int>> mp;

        for(int i = 0;  i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        queue<int> q;
        vector<int> dist(n, -1);

        q.push(0);
        dist[0] = 0;

        while(!q.empty()) {
            int i = q.front();
            q.pop();

            int d = dist[i];

            if(i == n - 1) return dist[i];

            if(i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = dist[i] + 1;
                q.push(i - 1);
            }

            if(i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = dist[i] + 1;
                q.push(i + 1);
            }

            if(mp.count(nums[i])) {
                for(int j : mp[nums[i]]) {
                    if(dist[j] == -1) {
                        dist[j] = dist[i] + 1;
                        q.push(j);
                    }
                }

                mp.erase(nums[i]);
            }
        }

        return -1;
    }
};