class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        // vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
            for(auto i:dir){
                int nx = i[0]+x;
                int ny = i[1]+y;
                // cout<<nx<<" "<<ny<<endl;
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==2147483647){
                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }
};
