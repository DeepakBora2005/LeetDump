class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({grid[0][0], {0, 0}});

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        while(!pq.empty()) {
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(visited[row][col]) continue;

            visited[row][col] = true;

            if(row == m - 1 && col == n - 1) return time;

            for(int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];


                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    int newTime = max(time, grid[nr][nc]);

                    pq.push({newTime, {nr, nc}});
                } 
            }
        } 

        return -1;
    }
};