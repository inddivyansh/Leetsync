class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<int> vis;
    int ans = INT_MAX;

    void dfs(int u){
        vis[u] = 1;

        for(auto &[v,w] : adj[u]){
            ans = min(ans, w);

            if(!vis[v]){
                dfs(v);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        adj.assign(n + 1, {});
        vis.assign(n + 1, 0);

        for(auto &it : roads){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        dfs(1);

        return ans;
    }
};