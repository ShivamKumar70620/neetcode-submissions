class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> time(n+1,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<pair<int,int>> adj[n+1];
        for(auto i: times){
            adj[i[0]].push_back({i[1],i[2]});
        }
        time[k] = 0;
        pq.push({k,0});
        while(!pq.empty()){
            auto it = pq.top();
            int curr = it.first;
            int tt = it.second;
            pq.pop();
            cout<<curr<<" "<<tt<<endl;
            for(auto i:adj[curr]){
                if(tt+i.second<time[i.first]){
                    pq.push({i.first,tt+i.second});
                    time[i.first] = tt+i.second;
                }
            }
        }
        int ans = INT_MIN;
        for(int i=0;i<=n;i++){
            cout<<time[i]<<endl;
            if(i!=0 && time[i]==INT_MAX)
                return -1;
            if(i!=0)
                ans = max(ans,time[i]);
        }
        return ans;
    }
};
