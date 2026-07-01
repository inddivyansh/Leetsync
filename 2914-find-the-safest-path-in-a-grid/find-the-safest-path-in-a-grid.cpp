class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n = grid.size();

        if(grid[0][0] || grid[n-1][n-1])
            return 0;

        vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    q.push({i,j});
            }
        }

        while(!q.empty()){

            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            for(auto d:dir){

                int x=i+d.first;
                int y=j+d.second;

                if(x<0 || y<0 || x>=n || y>=n)
                    continue;

                if(grid[x][y]!=0)
                    continue;

                grid[x][y]=grid[i][j]+1;
                q.push({x,y});
            }
        }

        priority_queue<tuple<int,int,int>> pq;

        pq.push({grid[0][0],0,0});
        grid[0][0]*=-1;

        while(!pq.empty()){

            auto [safe,i,j]=pq.top();
            pq.pop();

            if(i==n-1 && j==n-1)
                return safe-1;

            for(auto d:dir){

                int x=i+d.first;
                int y=j+d.second;

                if(x<0 || y<0 || x>=n || y>=n)
                    continue;

                if(grid[x][y]<=0)
                    continue;

                pq.push({min(safe,grid[x][y]),x,y});
                grid[x][y]*=-1;
            }
        }

        return 0;
    }
};