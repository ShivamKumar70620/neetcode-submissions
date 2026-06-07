class Solution {
public:
    bool checkTrust(int i, int j, vector<int> adj[], vector<int> &vis){
        if(vis[j])
            return 1;
        vis[j] = 1;
        for(auto x:adj[j])
        {
            if(x==i){
                return 0;
            }
            else
                return checkTrust(i,x,adj,vis);
        }
        return 1;
    }
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> adj[n];
        map<int,int> mp;
        for(auto i:trust){
            mp[i[0]]--;
            mp[i[1]]++;
        }
        for(auto i:mp){
            if(i.second==n-1)
                return i.first;
        }
        return -1;
    }
};