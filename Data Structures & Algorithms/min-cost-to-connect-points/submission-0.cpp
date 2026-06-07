class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> dist(n,INT_MAX);
        vector<bool> vis(n,false);
        vector<vector<int>> minV(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                minV[i][j] = d;
                minV[j][i] = d;
            }
        }
        int tc = 0;
        dist[0] = 0;
        for(int i=0;i<n;i++){
            int k = -1;
            for(int j=0;j<n;j++){
                if(!vis[j] && (k==-1 || dist[j]<dist[k])){
                    k = j;
                }
            }
            vis[k] = true;
            tc += dist[k];
            for(int j=0;j<n;j++){
                if(!vis[j]){
                    dist[j] = min(dist[j],minV[k][j]);
                }
            }

        }
        return tc;

    }
};
