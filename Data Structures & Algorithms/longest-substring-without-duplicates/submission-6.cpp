class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int n = s.size();
        if(n==0)
            return 0;
        int mx = INT_MIN, i=0,j=0, c=0;
        for(int j=0;j<n;j++){
            // cout<<i<<endl;
            if(mp.find(s[j])!=mp.end()){
                if(i<=mp[s[j]])
                    i = mp[s[j]] + 1;
            }
             mp[s[j]] = j;
             mx = max(j-i+1,mx);
        }
        
        return mx;
    }
};
