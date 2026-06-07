class Solution {
public:
    bool dfs(int i, vector<int> adj[], vector<int> &vis, int p){
        vis[i] = 1;
        for(auto x:adj[i]){
            if(vis[x]==1 && p!=x)
                return 1;
            else if(vis[x]==0 && dfs(x,adj,vis,i))
                return 1;
        }
        return 0;

    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n,0);
        if(dfs(0,adj,vis,-1))
            return false;
        for(auto i:vis){
            if(i==0)
                return 0;
        }
        return true;

    }
};
