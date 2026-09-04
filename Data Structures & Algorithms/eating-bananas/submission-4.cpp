class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mn = 1, mx = INT_MIN;
        for(auto i:piles){
            mx = max(mx,i);
        }
        int k;
        int ans = INT_MAX;
        while(mn<=mx){
            k = mn + (mx-mn)/2;
            cout<<"k "<<k<<endl;
            int a = 0;
            for(auto i:piles){
                a += i/k;
                a += i%k==0?0:1;
                // cout<<a<<endl;
            }
            cout<<"a "<<a<<endl;
            if(a<=h){
                cout<<"yes"<<endl;
                ans = min(ans,k);
                mx = k-1;
            }
            else if(a>h){
                cout<<"no"<<endl;
                mn = k+1;
            }
            cout<<"ans "<<ans<<endl;
        }
        return ans;
    }
};
