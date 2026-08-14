class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int m = players.size();
        int n = trainers.size();

        int left = 0;
        int right = 0;

        int ans = 0;

        while(left < m && right < n) {
            if(players[left] <= trainers[right]) {
                ans++;
                left++;
            }

            right++;
        }

        return ans;
    }
};