class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> grid, vector<vector<int>> &vis, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0)
            return 1;
        if(vis[i][j])
            return 0;
        vis[i][j] = 1;
        return dfs(i+1,j,grid,vis,n,m) + dfs(i-1,j,grid,vis,n,m) + dfs(i,j+1,grid,vis,n,m) + dfs(i,j-1,grid,vis,n,m);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1)
                    return dfs(i,j,grid,vis,n,m);
            }
        }
        
    }
};