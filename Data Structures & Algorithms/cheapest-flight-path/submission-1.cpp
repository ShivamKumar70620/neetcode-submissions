class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& fl, int src, int dst, int k) {
        vector<int> dist(n,INT_MAX);
        vector<pair<int,int>> adj[n];
        for(auto i:fl){
            adj[i[0]].push_back({i[1],i[2]});
        }
        dist[src] = 0;
        vector<int> vis(n,0);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<>> pq;
        pq.push({0,{src,0}});
        int ans = 0;
        while(!pq.empty()){
            auto it = pq.top();
            int x = it.second.first;
            int d = it.second.second;
            int st = it.first;
            pq.pop();
            ans=d;
            // cout<<x<<" "<<d<<" "<<dist[x]<<endl;
            if(x==dst && st==k+1)
                break;
            for(auto i:adj[x]){
                // cout<<i.first<<" "<<i.second<<endl;
                if(d+i.second<dist[i.first] && st<k+1){
                    dist[i.first] = d+i.second;
                    pq.push({st+1,{i.first,d+i.second}});
                }
            }
        }
        if(dist[dst]==INT_MAX)
            return -1;
        return dist[dst];
    }
};
