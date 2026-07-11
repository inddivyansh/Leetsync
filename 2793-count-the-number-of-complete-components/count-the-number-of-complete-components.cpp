class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;
    vector<int> comp;

    void dfs(int u){
        vis[u] = 1;
        comp.push_back(u);

        for(auto &v : adj[u]){
            if(!vis[v]){
                dfs(v);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.assign(n, {});
        vis.assign(n, 0);

        for(auto &it : edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            if(vis[i]) continue;

            comp.clear();
            dfs(i);

            bool ok = true;

            for(auto &u : comp){
                if(adj[u].size() != comp.size() - 1){
                    ok = false;
                    break;
                }
            }

            if(ok) ans++;
        }

        return ans;
    }
};