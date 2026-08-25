class Solution {
public:
    int find(int index, int turn, vector<int> &nums, vector<int> &prefix) {
        int n = nums.size();

        if(index >= n) return 0;

        int score1 = 0;
        int score2 = 0;

        if(turn == 0) {
            for(int i = 2; i < n; i++) {
                int take = 0;
                if(index + i < n) {
                    take = prefix[i + 1] + find(index + i, 1, nums, prefix); 
                }

                score1 = max(score1, take);
            }
        }
        else {
            for(int i = 2; i < n; i++) {
                int take = 0;
                if(index + i < n) {
                    take = prefix[i + 1] + find(index + i, 0, nums, prefix);
                }

                score2 = max(score2, take);
            }
        }

        return score1 - score2;
    }

    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> prefix(n + 1, 0);
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = stones[i] + prefix[i];
        }

        return find(0, 0, stones, prefix);
    }
};