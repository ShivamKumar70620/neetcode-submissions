class Solution {
public:
    void dfs(int i,vector<int> adj[], vector<int> &vis){
        vis[i] = 1;
        for(auto x:adj[i]){
            if(!vis[x]){
                dfs(x,adj,vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans+=1;
                dfs(i,adj,vis);
            }
        }
        return ans;
    }
};
