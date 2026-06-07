class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &board, vector<vector<int>> &vis, int n,int m){
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || board[i][j]=='X')
            return;
        vis[i][j] = 1;
        dfs(i,j-1,board,vis,n,m);
        dfs(i,j+1,board,vis,n,m);
        dfs(i+1,j,board,vis,n,m);
        dfs(i-1,j,board,vis,n,m);
        
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(i,0,board,vis,n,m);
            }
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                dfs(i,m-1,board,vis,n,m);
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O' && !vis[0][i]){
                dfs(0,i,board,vis,n,m);
            }
            if(board[n-1][i]=='O' && !vis[n-1][i]){
                dfs(n-1,i,board,vis,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O')
                    board[i][j] = 'X';
            }
        }
    }
};
