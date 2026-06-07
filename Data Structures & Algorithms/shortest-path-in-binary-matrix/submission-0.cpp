class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0)
            return -1;
        int n = grid.size();
        int m = grid[0].size();
        int dir[8][2] = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        vector<vector<int>> vis(n,vector<int>(m,0));
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.second.first;
            int y = it.second.second;
            int d = it.first;
            if(vis[x][y])
                continue;
            vis[x][y] = 1;
            if(x==n-1 && y==m-1)
                return d;
            for(auto i:dir){
                int nx = i[0]+x;
                int ny = i[1]+y;
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==0){
                    q.push({d+1,{nx,ny}});
                }
            }
        }
        return -1;
    }
};