class Solution {
public:
    int findPar(vector<int> &par,int x){
        if(par[x]==x) return x;
        return par[x] = findPar(par,par[x]);
    }
    bool Union(int n1, int n2, vector<int> &par,  vector<int> &rank){
        int p1 = findPar(par,n1);
        int p2 = findPar(par,n2);
        if(p1==p2)
            return false;
        if(rank[p1]<rank[p2])
        {
            par[p1] = p2;
            rank[p2] += rank[p1];
        }
        else{
            par[p2] = p1;
            rank[p1] += rank[p2];
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> rank(n+1,1);
        vector<int> par(n+1,0);
        for(int i=1;i<=n;i++)
            par[i] = i;
        for(auto &i:edges){
            if(!Union(i[0],i[1],par,rank))
                return vector<int>{i[0],i[1]};
        }
        return {};
    }
    
};
