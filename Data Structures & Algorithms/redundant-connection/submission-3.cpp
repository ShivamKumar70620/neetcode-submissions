class Solution {
public:
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> indegree(n+1,0);
        vector<int> par(n+1,0);
        for(int i=1;i<=n;i++)
            par[i] = i;
        vector<int> adj[n+1];
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            indegree[i[1]]++;
            indegree[i[0]]++;
        }
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(indegree[i]==1)
                q.push(i);
        }
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto ne:adj[front]){
                indegree[ne]--;
                if(indegree[ne]==1)   q.push(ne);
            }
        }
        for(int i=edges.size()-1;i>=0;i--){
            if(indegree[edges[i][0]]>1 && indegree[edges[i][1]]>1)
                return {edges[i][0],edges[i][1]};
        }
        return {};
    }
    
};
