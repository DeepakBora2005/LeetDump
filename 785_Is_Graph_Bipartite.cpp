class Solution {
public:
    bool dfs(int node, int col, vector<vector<int>> &graph, vector<int> &color) {
        color[node] = col;
        
        for(int neighbor : graph[node]) {
            if(color[neighbor] == -1) {
                if(color[node] == 0) {
                    if(!dfs(neighbor, 1 - col, graph, color)) return false;
                }
            }
            else if(color[neighbor] == color[node]) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);

        return dfs(0, 0, graph, color);
    }
};