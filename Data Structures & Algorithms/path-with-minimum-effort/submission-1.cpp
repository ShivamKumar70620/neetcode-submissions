class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(),m=heights[0].size();
        vector<vector<int>> diff(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> q;
        q.push({0,{0,0}});
        diff[0][0] = 0;
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto it = q.top();
            int df = it.first;
            int x = it.second.first;
            int y = it.second.second;
            if(x==n-1 && y==m-1)
                return df;
            q.pop();
            for(auto i:dir){
                int nx = x + i[0];
                int ny = y + i[1];
                
                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    int newEff = max(df,abs(heights[nx][ny]-heights[x][y]));
                    if(newEff < diff[nx][ny]){
                        diff[nx][ny] = newEff;
                        q.push({newEff, {nx,ny}});
                    }
                }
            }
        }
        return 0;
    }
};