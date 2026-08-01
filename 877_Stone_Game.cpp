class Solution {
public:
    int find(vector<int> &piles, int start, int end) {
        if(start == end) {
            return piles[start];
        }

        int leftMost = piles[start] - find(piles, start + 1, end);
        int rightMost = piles[end] - find(piles, start, end - 1);

        return max(leftMost, rightMost);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        return find(piles, 0, n - 1) > 0;
    }
};