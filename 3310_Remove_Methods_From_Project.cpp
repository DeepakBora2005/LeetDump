class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis) {
        vis[node] = true;

        for(int neighbor : adj[node]) {
            if(!vis[neighbor]) {
                dfs(neighbor, adj, vis);
            }
        }
    }
    
    vector<int> remainingMethods(int n, int k, vector<vector<int>> &nums) {
        vector<vector<int>> adj(n);

        for(auto &edge : nums) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        } 

        vector<bool> vis(n, false);

        dfs(k, adj, vis);

        vector<int> ans;

        for(auto &edge : nums) {
            int u = edge[0];
            int v = edge[1];

            if(!vis[u] && vis[v]) {
                for(int i = 0; i < n; i++) {
                    ans.push_back(i);
                }

                return ans;
            }
        }

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};