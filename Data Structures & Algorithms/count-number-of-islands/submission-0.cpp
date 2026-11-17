class Solution {
public:
    void traverse(int i, int j, vector<vector<int>> &vis, vector<vector<char>>& grid, int n, int m){
        // cout<<i<<" "<<j<<endl;
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j]) return;
        if(!vis[i][j] && grid[i][j]=='1'){
            vis[i][j] = 1;
            traverse(i+1,j,vis,grid,n,m);                    
            traverse(i,j+1,vis,grid,n,m);
            traverse(i-1,j,vis,grid,n,m);
            traverse(i,j-1,vis,grid,n,m);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){ 
                // cout<<i<<" "<<j<<endl;
                if(!vis[i][j] && grid[i][j]=='1') {   
                    traverse(i,j,vis,grid,n,m);
                    ans+=1;
                }
                    
            }
        }
        return ans;
    }
};
