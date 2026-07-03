class Solution {
public:
    int n;

    bool check(int limit, vector<vector<pair<int,int>>> &adj,
               vector<bool> &online, vector<int> &topo,
               long long k)
    {
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        for(int node : topo){

            if(dist[node] == LLONG_MAX)
                continue;

            for(auto &ngbr : adj[node]){

                int nxtNode = ngbr.first;
                int cst = ngbr.second;

                if(cst < limit)
                    continue;

                if(nxtNode != n-1 && !online[nxtNode])
                    continue;

                dist[nxtNode] = min(dist[nxtNode], dist[node] + cst);
            }
        }

        return dist[n-1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k)
    {
        n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n);

        int low = INT_MAX;
        int high = 0;

        for(auto &e : edges){

            int u = e[0];
            int v = e[1];
            int cst = e[2];

            adj[u].push_back({v, cst});
            indegree[v]++;

            low = min(low, cst);
            high = max(high, cst);
        }

        queue<int> q;
        vector<int> topo;

        for(int i=0;i<n;i++){

            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){

            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(auto &ngbr : adj[node]){

                int nxtNode = ngbr.first;

                indegree[nxtNode]--;

                if(indegree[nxtNode] == 0)
                    q.push(nxtNode);
            }
        }

        int ans = -1;

        while(low <= high){

            int mid = low + (high-low)/2;

            if(check(mid, adj, online, topo, k)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
};